#include <iostream>
#include <vector>
#include "myHeader.h"
using namespace std;

class Warehouse {
    int itemCount;
    friend class Distributor;
    public:
        Warehouse(int n = 0) {
            itemCount = n;
        }
};

class Distributor {
    public:
        void ship(Warehouse& w, int n) {
            cout << "c1: " << w.itemCount;
            cout << ", shipped: " << n;
            w.itemCount -= n;
            cout << ", c2: " << w.itemCount << endl;
        }
};

class Lab14Task2: public Task {
    public:
        void process() override {
            cout << "*TASK-2*" << endl;
            Warehouse w(110);
            Distributor d;
            d.ship(w, 65);
        }
};
