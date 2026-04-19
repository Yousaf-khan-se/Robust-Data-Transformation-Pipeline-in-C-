#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
#include <unistd.h>
#include <fcntl.h>

using namespace std;
class FileManager
{
private:
        string inputFile;
        string outputFile;
        string errorFile;
        int savedStdout;
        int savedStderr;

public:
        FileManager(const string &input, const string &output, const string &error)
            : inputFile(input), outputFile(output), errorFile(error) {}

        void redirectOutput()
        {
                savedStdout = dup(STDOUT_FILENO);
                savedStderr = dup(STDERR_FILENO);

                int outFd = open(outputFile.c_str(), O_WRONLY | O_CREAT | O_TRUNC, 0644);
                int errFd = open(errorFile.c_str(), O_WRONLY | O_CREAT | O_TRUNC, 0644);

                if (outFd == -1 || errFd == -1)
                {
                        throw runtime_error("Failed to open output or error file");
                }

                dup2(outFd, STDOUT_FILENO);
                dup2(errFd, STDERR_FILENO);

                close(outFd);
                close(errFd);
        }

        void restoreOutput()
        {
                dup2(savedStdout, STDOUT_FILENO);
                dup2(savedStderr, STDERR_FILENO);
                close(savedStdout);
                close(savedStderr);
        }

        vector<string> readInputFile()
        {
                ifstream inFile(inputFile);
                if (!inFile)
                {
                        throw runtime_error("Failed to open input file: " + inputFile);
                }

                vector<string> numbers;
                string number;
                while (inFile >> number)
                {
                        numbers.push_back(number);
                }
                return numbers;
        }
};

#endif