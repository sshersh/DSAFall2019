/*
Sam Shersher, ECE-264, Prof. Sable

Code to process commands from specified file into management of user-defined stacks and queues implemented as lists.
The stacks and queues are stored as simplelist ptrs in 3 maps for each of the three data types.
    std::map was used for convenience: the name of the list can be used as the key.
In processCommands() input file is parsed and determines what will happen to the list in question.
*/

#include "Queue.cpp"
#include "Stack.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

void processCommands(string inFile, string outFile) {
        ifstream input(inFile);
        ofstream output(outFile);

        map<string, SimpleList<int>*> intLists;
        map<string, SimpleList<double>*> doubleLists;
        map<string, SimpleList<string>*> stringLists;

        string m1 = "PROCESSING COMMAND: ";

        string line;
        string command;
        string name;
        string in;
        char type;

        while(getline(input, line)) {
            stringstream ss(line);
            ss >> command >> name >> in;
            type = name[0];
            output << m1 << line << endl;
            if(command == "create") {
                switch(type){
                    case 'i':
                        if(intLists.find(name) == intLists.end()) {
                            if(in == "queue") {
                                intLists.insert(pair<string,  SimpleList<int>*>(name, new Queue<int>(name)));
                            }
                            else if(in == "stack") {
                                intLists.insert(pair<string, SimpleList<int>*>(name, new Stack<int>(name)));
                            }
                        }
                        else {
                            output << "ERROR: This name already exists!" << endl;
                        }
                        break;
                    case 'd':
                        if(doubleLists.find(name) == doubleLists.end()) {
                            if(in == "queue") {
                                doubleLists.insert(pair<string,  SimpleList<double>*>(name, new Queue<double>(name)));
                            }
                            else if(in == "stack") {
                                doubleLists.insert(pair<string,  SimpleList<double>*>(name, new Stack<double>(name)));
                            }
                        }
                        else {
                            output << "ERROR: This name already exists!" << endl;
                        }
                        break;
                    case 's':
                        if(stringLists.find(name) == stringLists.end()) {
                            if(in == "queue") {
                                stringLists.insert(pair<string,  SimpleList<string>*>(name, new Queue<string>(name)));
                            }
                            else if(in == "stack") {
                                stringLists.insert(pair<string,  SimpleList<string>*>(name, new Stack<string>(name)));
                            }
                        }
                        else {
                            output << "ERROR: This name already exists!" << endl;
                        }
                        break;
                }
            }
            else if(command == "push"){
                switch(type) {
                    case 'i':
                        if(intLists.find(name) == intLists.end()) {
                            output << "ERROR: This name does not exist!" << endl;
                        }
                        else {
                            intLists[name]->push(stoi(in));
                        }
                        break;
                    case 'd':
                        if(doubleLists.find(name) == doubleLists.end()) {
                            output << "ERROR: This name does not exist!" << endl;
                        }
                        else {
                            doubleLists[name]->push(stod(in));
                        }
                        break;
                    case 's':
                        if(stringLists.find(name) == stringLists.end()) {
                            output << "ERROR: This name does not exist!" << endl;
                        }
                        else {
                            stringLists[name]->push(in);
                        }
                        break;
                }
            }
            else if(command == "pop"){
                switch (type) {
                    case 'i':
                        if(intLists.find(name) == intLists.end()) {
                            output << "ERROR: This name does not exist!" << endl;
                        }
                        else if (intLists[name]->size() == 0) {
                            output << "ERROR: This list is empty!" << endl;
                        }
                        else {
                            output << "Value popped: " << intLists[name]->pop() << endl;
                        }
                        break;
                    case 'd':
                        if(doubleLists.find(name) == doubleLists.end()) {
                            output << "ERROR: This name does not exist!" << endl;
                        }
                        else if (doubleLists[name]->size() == 0) {
                            output << "ERROR: This list is empty!" << endl;
                        }
                        else {
                            output << "Value popped: " << doubleLists[name]->pop() << endl;
                        }
                        break;
                    case 's':
                        if(stringLists.find(name) == stringLists.end()) {
                            output << "ERROR: This name does not exist!" << endl;
                        }
                        else if (stringLists[name]->size() == 0) {
                            output << "ERROR: This list is empty!" << endl;
                        }
                        else {
                            output << "Value popped: " << stringLists[name]->pop() << endl;
                        }
                        break;
                }
            }
        }
}

int main() {
    string inFile;
    cout << "Enter name of input file: ";
    cin >> inFile;
    string outFile;
    cout << "Enter name of output file: ";
    cin >> outFile;

    processCommands(inFile, outFile);
}
