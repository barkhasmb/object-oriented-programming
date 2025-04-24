#include <iostream>
using namespace std;

inline void hr() {
    cout << "-------------------------------------------------------" << endl;
}

inline void lb() {
    cout << endl;
}

class Fuel {
    protected:
        int fuel, cost;
    public:
        void move(float distance) {
            fuel -= distance / 100 * cost;
        }
        void reFuel(int fuel) {
            this -> fuel += fuel;
        }
        void printFuelAmount() {
            cout << "Fuel remaining: " << fuel << endl;
        }
        
};

class Truck: public Fuel {
    public:
        Truck(int fuel = 0) {
            this -> fuel = fuel;
            cost = 30;
        }
};

class Bus: public Fuel {
    public:
        Bus(int fuel = 0) {
            this -> fuel = fuel;
            cost = 20;
        }
};

int main() {
    Truck truck = Truck(200);
    Bus bus = Bus(75);

    truck.move(450);
    bus.move(300);

    truck.reFuel(50);
    bus.reFuel(20);

    truck.printFuelAmount();
    bus.printFuelAmount();

    return 0;
}