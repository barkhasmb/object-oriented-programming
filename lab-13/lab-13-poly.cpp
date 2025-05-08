#include <iostream>
#include <vector>
using namespace std;

inline void hr() {
    cout << "-------------------------------------------------------" << endl;
}

inline void lb() {
    cout << endl;
}

class Supplier {
    public:
        virtual void supply() {}
};

class BookSupplier: public Supplier {
    public:
        void supply() override {
            cout << "Sent 15 book supplies" << endl;
        }
};

class FoodSupplier: public Supplier {
    public:
        void supply() override {
            cout << "Sent 2 food supplies" << endl;
        }
};

class ClothingSupplier: public Supplier {
    public:
        void supply() override {
            cout << "Sent 5 clothing supplies" << endl;
        }
};

int main() {
    vector<Supplier *> suppliers;

    suppliers.push_back(new BookSupplier);
    suppliers.push_back(new FoodSupplier);
    suppliers.push_back(new ClothingSupplier);

    // for(int i = 0; i < 3; i++) {
    //     suppliers.push_back(new BookSupplier);
    // }
    // for(int i = 0; i < 3; i++) {
    //     suppliers.push_back(new FoodSupplier);
    // }
    // for(int i = 0; i < 3; i++) {
    //     suppliers.push_back(new ClothingSupplier);
    // }

    for(Supplier * supplier : suppliers) {
        supplier -> supply();
    }

    return 0;
}