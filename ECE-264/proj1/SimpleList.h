//note: this directive must be used so that simplelist won't be included multiple times.
#pragma once
#include <string>

//based on the textbook implementation
using namespace std;

template <typename datatype>
class SimpleList {
private:
		string name;
		class Node;
		Node* head;
		Node* tail;
		int theSize;
protected:
		void insertStart(const datatype&);
		void insertEnd(const datatype&);
		datatype removeStart();
public:
        ~SimpleList();
        SimpleList();
        SimpleList(string&);
        string getName();
		int size();
		virtual void push(const datatype&) = 0;
		virtual datatype pop() = 0;
};
