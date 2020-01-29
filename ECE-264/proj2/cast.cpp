#include <string>

using namespace std;

int main() {
    string name = "ANAME";
    uint8_t* n = reinterpret_cast<uint8_t*>(name.c_str());
    cout << *n << endl;
}
