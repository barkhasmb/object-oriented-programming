#include <iostream>
#include <vector>
#include "myHeader.h"
using namespace std;

class Vector {
    int x, y;
    public:
        Vector(int x = 0, int y = 0) {
            this -> x = x;
            this -> y = y;
        }
        friend Vector operator+(const Vector& v1, Vector& v2);
        void print() {
            cout << x << " " << y << endl;
        }
};

Vector operator+(const Vector& v1, Vector& v2) {
    Vector v3(v1.x + v2.x, v1.y + v2.y);
    return v3;
}

class Lab14Task1: public Task {
    public:
        void process() override {
            cout << "*TASK-1*" << endl;
            Vector v1(2, 4), v2(3, 5), v3;
            v3 = v1 + v2;
            v3.print();
        }
};
