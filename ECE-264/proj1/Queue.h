#include "simplelist.h"

template <typename datatype>
class Queue : public virtual SimpleList<datatype> {
public:
        Queue();
        Queue(string&);
		void push(const datatype&);
		datatype pop();
};
