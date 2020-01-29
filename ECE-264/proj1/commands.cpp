#include <fstream>
#include <string>
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <vector>
#include <sstream>

using namespace std;

vector<string> names;
vector<string> inWords;

int parseInput() {
    ifstream input;
    string inFile;
    cout << "name of input file: ";
    cin >> inFile;
    input.open(inFile, ifstream::in);
    string line;
    string curWord;
    while(getline(input, line)) {
        stringstream ss(line);
        while(ss >> curWord) {
            inWords.push_back(curWord);
        }
    }
    input.close();
}

int pickRand(int max) {
    return (rand() % max);
}

string newCommand(ofstream& os) {
    string first[] = {"create", "push", "pop"};
    string types[] = {"i", "d", "s"};
    string createVals[] = {"stack", "queue"};
    string newName = "";
    string val;
    string curName;
    int com = pickRand(3);
    switch(com) {
        case 0:
            os << first[com] << " ";
            newName = types[pickRand(3)] + to_string(pickRand(1000));
            os << newName << " ";
            val = createVals[pickRand(2)];
            os << val << endl;
            break;
        case 1:
            if(names.size() > 0) {
                os << first[com] << " ";
                curName = names[pickRand(names.size())];
                os << curName << " ";
                switch(curName[0]) {
                    case('i'):
                        os << pickRand(1000) << endl;
                        break;
                    case('d'):
                        os << pickRand(10) << "." << pickRand(1000) << endl;
                        break;
                    case('s'):
                        os << inWords[pickRand(inWords.size())] << endl;
                        break;
                }
            }
            break;
        case 2:
            if(names.size() > 0) {
                os << first[com] << " ";
                curName = names[pickRand(names.size())];
                os << curName << endl;
            }
            break;
    }
    return newName;
}

int main() {
    parseInput();
    srand(time(NULL));
    string currentName;
    int numCommands;
    string outName;
    cout << "How many commands? ";
    cin >> numCommands;
    cout << "Name of output file: ";
    cin >> outName;
    ofstream output(outName);
    for(int ii = 0; ii < numCommands; ii++) {
        currentName = newCommand(output);
        if(currentName != "") {
            names.push_back(currentName);
        }
    }
    cout << endl << endl << names.size();
}
