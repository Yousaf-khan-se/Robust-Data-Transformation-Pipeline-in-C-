#ifndef STREAMPROCESSOR_H
#define STREAMPROCESSOR_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
#include <unistd.h>
#include <fcntl.h>

using namespace std;

class StreamProcessor
{
public:
        void processData(const vector<string> &data)
        {
                cout << "Processing input file...\n";
                for (const auto &number_str : data)
                {
                        cout << "Read number: " << number_str << endl;
                        try
                        {
                                int number = stoi(number_str);
                                if (number == 0)
                                {
                                        throw runtime_error("Division by zero encountered.");
                                }
                                int processed = 100 / number;
                                cout << "Processed number: " << processed << endl;
                        }
                        catch (const invalid_argument &)
                        {
                                string error = "Error: Invalid number format for '" + number_str + "'";
                                cout << error << endl;
                                cerr << error << endl;
                        }
                        catch (const runtime_error &e)
                        {
                                string error = "Error: " + string(e.what());
                                cout << error << endl;
                                cerr << error << endl;
                        }
                }
        }
};

#endif