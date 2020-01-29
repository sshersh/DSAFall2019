#include "Stack.h"

template <typename datatype>
Stack<datatype>::Stack()
    :SimpleList<datatype>() {
        cout << "Stack created!" << endl;
    }

template <typename datatype>
Stack<datatype>::Stack(string& word)
    :SimpleList<datatype>(word) {}

template <typename datatype>
datatype Stack<datatype>::pop() {
    return SimpleList<datatype>::removeStart();
}

template <typename datatype>
void Stack<datatype>::push(const datatype& d) {
	SimpleList<datatype>::insertStart(d);
}
