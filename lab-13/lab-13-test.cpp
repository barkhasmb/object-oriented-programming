#include <iostream>
#include <vector>
using namespace std;

inline void hr() {
    cout << "-------------------------------------------------------" << endl;
}

inline void lb() {
    cout << endl;
}

class Base {
    public:
        void fun() {
            cout << "Base fun() called" << endl;
        }
        void fun(int i) {
            cout << "Base fun(int i) called" << endl;
        }
};

class Derived: public Base {
    public:
        using Base::fun;
        void fun() {
            cout << "Derived fun() called" << endl;
        }
};

int main() {
    Derived d;

    d.fun(5);

    return 0;
}