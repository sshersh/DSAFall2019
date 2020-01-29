#include "queue.h"

template <typename datatype>
Queue<datatype>::Queue()
    :SimpleList<datatype>() {}

template <typename datatype>
Queue<datatype>::Queue(string& s)
    :SimpleList<datatype>(s){}

template <typename datatype>
datatype Queue<datatype>::pop() {
	return SimpleList<datatype>::removeStart();
}

template <typename datatype>
void Queue<datatype>::push(const datatype& d) {
	SimpleList<datatype>::insertEnd(d);
}
