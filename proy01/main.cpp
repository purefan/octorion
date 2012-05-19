// In this snippet we will read the number of lines in text file
#include <stdlib.h>
#include <iostream>
#include <fstream>

// I dont want to be using std:: all the time
using namespace std;

// This is the Main function and it will be executed when you run your program
int main(int argc, char** argv)
{
    // This program requires one parameter to be passed, argc is a variable
    // that tells how many parameters were passed and the name of the program is
    // always passed as argv[0]
    if (argc < 2)
    {
        cout << "Error: You have to tell me which file to read." << endl;
        cout << "Example: " << argv[0] << " my-file.txt";
        return EXIT_FAILURE;
    }

    // We need a stream to read the file
    ifstream hFile(argv[1]);

    // Make sure the file exists and it was opened ok
    if (hFile.is_open())
    {
        cout << "Reading file: " << argv[1] << endl;
        string sLine;
        int iCounter = 0;

        // Lets go through all the file
        while ( hFile.good() )
        {
            // lets put the current line from our stream into the sLine string
            getline (hFile,sLine);
            iCounter++;
            cout << iCounter << ". " << sLine << endl;
        }
        // always close your streams
        hFile.close();
        cout << endl << endl << "This file has " << iCounter << " lines";
    }
    else
    {
        cout << "Error: The file (" << argv[1] <<") does not exist or cannot be read";
        return EXIT_FAILURE;
    }

    return (EXIT_SUCCESS);
}
