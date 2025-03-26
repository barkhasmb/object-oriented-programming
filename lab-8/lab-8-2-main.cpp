#include <iostream>
#include "lab-8-2-classes.cpp"
using namespace std;

inline void hr() {
    cout << "-------------------------------------------------------" << endl;
}

inline void lb() {
    cout << endl;
}

int Store::soldAmount = 0;

int main() {
    PhoneBrand *phoneBrand1 = new PhoneBrand("iPhone", 3);
    PhoneBrand *phoneBrand2 = new PhoneBrand("Android", 3);

    Store store = Store("Phone Market");

    store.addPhoneBrand(phoneBrand1);
    store.addPhoneBrand(phoneBrand2);

    store.sellPhone(phoneBrand1, 2);
    store.sellPhone(phoneBrand2, 1);

    store.sellPhone(phoneBrand1, 1);

    store.phoneReturned(phoneBrand2, 1);

    PhoneBrand *phoneBrand3 = new PhoneBrand("Xaomi", 3);

    store.addPhoneBrand(phoneBrand3);

    hr();
    store.printStock();
    hr();

    return 0;
}