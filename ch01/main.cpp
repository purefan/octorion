#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

/* This is a challenge in codeeval.com the instructions are this:

Write a program which finds the next-to-last word in a string.

INPUT SAMPLE:

Your program should accept as its first argument a path to a filename. Input example is the following

some line with text
another line

Each line has more than one word.

OUTPUT SAMPLE:

Print the next-to-last word in the following way.

with
another
*/

int main(int argc, char *argv[])
{
    cout << "\tChallenge 1 - Codeeval.com " << endl << "\tFind the next-to-last word" << endl;

    if (argc != 2){
        cerr << "Please enter the path to a text file as the program's first and only argument" << endl << argc << endl << endl;
        cerr << argv[1] << endl;
        return 1;
    }

    string line;
    ifstream incoming;
    incoming.open(argv[1]);

    while (getline(incoming, line)){
        stringstream ss;
        string word;
        vector<string> container;
        ss.str(line);
        while(getline(ss, word, ' ')){
            container.push_back(word);
        }
        if (container.size() < 2){
            cerr << "This file is not formatted correctly, this line does not have at least 2 words";
        }
        else {
            cout << container[container.size() - 2] << endl;
        }

    }
    return 0;
}
