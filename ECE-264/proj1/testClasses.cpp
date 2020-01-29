#include "queue.cpp"
#include <iostream>
#include "Stack.cpp"

template<typename datatype>
void testStack(datatype d[], int s) {
    string nameStack = "firstStack";
    Stack<datatype>* stack = new Stack<datatype>(nameStack);
    for (int ii = 0; ii < s; ii++) {
        stack->push(d[ii]);
    }

    cout << "size = " << stack->size() << endl;
    while(stack->size()) {
        cout << stack->pop();
        cout << "   size:  " << stack->size() << endl;
    }
    cout << stack->pop() << endl;
    delete stack;
}

template<typename datatype>
void testQueue(datatype d[], int s) {
    string nameQueue = "firstQueue";
    Queue<datatype>* queue = new Queue<datatype>(nameQueue);
    for (int ii = 0; ii < s; ii++) {
        queue->push(d[ii]);
    }

    cout << "size = " << queue->size() << endl;
    while(queue->size()) {
        cout << queue->pop();
        cout << "   size:  " << queue->size() << endl;
    }
    cout << queue->pop() << endl;
    delete queue;
}


int main() {
    string data[] = {"blah", "bleep", "blew", "blaba", "bloop"};
    int datasize = 5;
    testStack<string>(data, datasize);
    testQueue<string>(data, datasize);
}
