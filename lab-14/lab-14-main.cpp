#include <iostream>
#include <vector>
#include "myHeader.h"
#include "lab-14-classes-1.cpp"
#include "lab-14-classes-2.cpp"
#include "lab-14-classes-3.cpp"
#include "lab-14-classes-4.cpp"
using namespace std;

inline void hr() {
    cout << "-------------------------------------------------------" << endl;
}

inline void lb() {
    cout << endl;
}

int main() {
    vector<Task *> tasks;

    tasks.push_back(new Lab14Task1);
    tasks.push_back(new Lab14Task2);
    tasks.push_back(new Lab14Task3);
    tasks.push_back(new Lab14Task4);

    for(Task * task : tasks) {
        hr();
        task -> process();
        hr();
    }

    return 0;
}