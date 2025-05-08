#include <iostream>
#include <vector>
using namespace std;

inline void hr() {
    cout << "-------------------------------------------------------" << endl;
}

inline void lb() {
    cout << endl;
}

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


int main() {
    Warehouse w(110);
    Distributor d;
    d.ship(w, 65);
    return 0;
}