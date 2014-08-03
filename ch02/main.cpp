#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

/* This is a challenge in codeeval.com the instructions are this:

CHALLENGE DESCRIPTION:

In this challenge you need to find the longest word in a sentence. If the sentence has more than one word of the same length you should pick the first one.

INPUT SAMPLE:

Your program should accept as its first argument a path to a filename. Input example is the following

some line with text
another line
Each line has one or more words. Each word is separated by space char.

OUTPUT SAMPLE:

Print the longest word in the following way.

some
another

*/

int main(int argc, char *argv[])
{
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
        string word, longest = "";
        ss.str(line);
        while(getline(ss, word, ' ')){
            if (word.length() > longest.length()) longest = word;
        }

        cout << longest << endl;

    }
    return 0;
}
