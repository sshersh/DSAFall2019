#pragma once
#include "simplelist.h"
#include <iostream>

template <typename datatype>
class SimpleList<datatype>::Node {
	public:
        //data stored in the node
		datatype data;
        //ptr to the next node
		Node* next;
        //different constructors implemented for convenience
        Node() {}
        Node(const datatype& D) {
            data = D;
            next = nullptr;
        }
		Node(const datatype& D, Node* N) {
			data = D;
			next = N;
		}
};

template <typename datatype>
void SimpleList<datatype>::insertStart(const datatype& data) {
    //first create a new node with the current head as its next ptr
    //then assign that node to head
    //must first check that list isn't empty (not dereferencing a NULL ptr)
    if(head) {
	       head = new Node(data, head);
    }
    else {
        //now list is no longer empty: head and tail point to same Node
        head = new Node(data);
        tail = head;
    }
	theSize++;
}

template <typename datatype>
void SimpleList<datatype>::insertEnd(const datatype& data) {
    //check if tail already exists (if list isn't empty)
    //if so, add onto next of tail. If not, create a tail
    if(tail) {
        tail->next = new Node(data);
        tail = tail->next;
    }
    else {
        tail = new Node(data);
        head = tail;
    }
	theSize++;
}

template <typename datatype>
datatype SimpleList<datatype>::removeStart() {
    //temp is needed to temporarily store the new head ptr while current head is deleted
    //although tail and head point to the same node when list has size 1, both have to be taken care of seperately
    Node* temp;
    datatype tempData;
    if (head == tail){
        tail = nullptr;
    }
    temp = head->next;
    tempData = head->data;
    delete head;
    head = temp;
    temp = nullptr;
    theSize--;
    return tempData;
}

template <typename datatype>
SimpleList<datatype>::SimpleList() {
    head = nullptr;
	tail = nullptr;
	theSize = 0;
}

template <typename datatype>
SimpleList<datatype>::SimpleList(string& s){
    name = s;
    head = nullptr;
	tail = nullptr;
	theSize = 0;
}

template <typename datatype>
SimpleList<datatype>::~SimpleList() {
    using namespace std;
    while(head) {
        removeStart();
    }
    delete head;
}

template <typename datatype>
string SimpleList<datatype>::getName() {
	return name;
}

template <typename datatype>
int SimpleList<datatype>::size() {
	return theSize;
}
