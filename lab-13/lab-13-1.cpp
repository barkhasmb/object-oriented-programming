#include <iostream>
#include <vector>
using namespace std;

inline void hr() {
    cout << "-------------------------------------------------------" << endl;
}

inline void lb() {
    cout << endl;
}

static int inprocess;

class Participant {
    public:
        virtual void process(int i) = 0;
};

class Supplier: public Participant {
    public:
        void process(int i) override {
            cout << "Orders: " << inprocess << endl; 
            cout << "   " << "Supplied " << i << " products." << endl;
            cout << "   " << inprocess - i << " products waiting for process." << endl;
            inprocess = i;
        }
};

class Distributor: public Participant {
    public:
        void process(int i) override {
            cout << "At-Distributor: " << inprocess << endl; 
            cout << "   " << "Distributed " << i << " products." << endl;
            cout << "   " << inprocess - i << " products waiting for distribution." << endl;
            inprocess = i;
        }
};

class Retailer: public Participant {
    public:
        void process(int i) override {
            cout << "In-Store: " << inprocess << endl; 
            cout << "   " << "Sold " << i << " products." << endl;
            cout << "   " << inprocess - i << " products in stock." << endl;
            inprocess = i;
        }
};


int main() {
    Participant *p; 

    inprocess = 10;

    p = new Supplier;
    p -> process(7);

    p = new Distributor;
    p -> process(5);

    p = new Retailer;
    p -> process(5);

    return 0;
}