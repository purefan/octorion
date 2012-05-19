//Simple example of how to use functions, files and exceptions to read the
// number of bytes in a file
#include <iostream> // Needed for cout
#include <stdio.h> // needed for fopen
#include <sstream> // needed for ostringstream

// I dont want to write things like std::string all the time:
using namespace std;

// This function returns a string, the name of the function is "getFileSize" and it
// requires a string to be passed as a parameter, this parameter is called
// "fileName" and is used as a variable inside this function
string getFileSize(string fileName)
{
    // We "protect" the code by wrapping it in a "try" block
    try
    {
        // Now all this code can cause an Exception and the program
        // will continue working because this exception is handled
        // by the catch block

        // We need a FILE object to act as a stream to a file
        FILE * myFile;

        // the function fopen will try to open the file, in this line we convert
        // a "string" into a "const char*" and open the file in read mode ("r")
        myFile = fopen(fileName.c_str(), "r");

        // now we tell the FILE object (myFile) to move to the end of the stream
        fseek(myFile, 0, SEEK_END);

        // now we ask the file in which position is the cursor at:
        int iFileSize = ftell(myFile);

        // if the pointer did not move the file did not exist
        if (iFileSize < 0)
        {
            throw "This message is not used";
        }

        // Always close your streams
        fclose(myFile);

        // Now we need to prepare the string that this function will return
        string stringReturned;

        // We also have an int (iFileSize) that needs to be converted to a string
        // to do that we use the ostringstream object
        ostringstream convert;

        // and because it is a stream we use << instead of + to add iFileSize to it
        convert << iFileSize;

        // Now we can put our message together
        stringReturned = fileName + " has " + convert.str() + " bytes";
        // we still needed to convert the stream to a string with convert.str()

        // this function returns a string
        return  stringReturned ;
    }
    catch (const char* errorMessage)
    {
        // if an exception is triggered this block will handle it
        // and return a simple string still
        return "The file \"" + fileName + "\" cannot be read";
    }
}

int main(int argc, char** argv)
{

    cout << "1. File that does exist: " << getFileSize("it-exists.txt") << endl;
    cout << "2. File that does not exist: " << getFileSize("it-does-not-exist.txt") << endl;

    return 0;
}
