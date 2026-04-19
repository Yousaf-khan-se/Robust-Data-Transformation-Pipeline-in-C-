#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
#include <unistd.h>
#include <fcntl.h>

#include "FileManager.h"
#include "StreamProcessor.h"

using namespace std;
int main(int argc, char *argv[])
{
        if (argc != 4)
        {
                cerr << "Usage: " << argv[0] << " <input_file> <output_file> <error_file>" << endl;
                return 1;
        }

        try
        {
                FileHandler fileHandler(argv[1], argv[2], argv[3]);
                DataProcessor dataProcessor;

                vector<string> inputData = fileHandler.readInputFile();

                fileHandler.redirectOutput();
                dataProcessor.processData(inputData);
                fileHandler.restoreOutput();

                cout << "File descriptors have been restored to their original state." << endl;
        }
        catch (const exception &e)
        {
                cerr << "An error occurred: " << e.what() << endl;
                return 1;
        }

        return 0;
}