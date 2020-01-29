#include "simplelist.cpp"

template <typename datatype>
class Stack : public virtual SimpleList<datatype> {
public:
        Stack();
        Stack(string&);
		void push(const datatype&);
		datatype pop();
};
