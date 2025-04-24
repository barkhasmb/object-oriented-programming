#include <iostream>
using namespace std;

inline void hr() {
    cout << "-------------------------------------------------------" << endl;
}

inline void lb() {
    cout << endl;
}

template <typename type>
void add(type a, type b) {
    cout << a + b << endl;
}

template <typename type>
void decrease(type a, type b) {
    cout << a - b << endl;
}

template <typename type>
void times(type a, type b) {
    cout << a * b << endl;
}

template <typename type>
void divide(type a, type b) {
    cout << a / b << endl;
}

int main() {

    add <float> (5.0, 2.1f);
    add <int> (2, 3);

    decrease <float> (5.0, 2.1f);
    decrease <int> (2, 3);

    times <float> (5.0, 2.1f);
    times <int> (2, 3);

    divide <float> (5.0, 2.1f);
    divide <int> (2, 3);

    return 0;
}