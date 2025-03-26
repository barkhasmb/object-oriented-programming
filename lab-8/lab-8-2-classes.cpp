#include <iostream>
#include <vector>
using namespace std;

class PhoneBrand {
    string brandName;
    int stock;
public:
    PhoneBrand(string brandName = "", int stock = 0) {
        this -> brandName = brandName;
        this -> stock = stock;
    }
    void restock(int quantity) {
        stock += quantity;
    }
    void sell(int quantity) {
        stock -= quantity;
    }
    string getBrandName() {
        return brandName;
    }
    int getStock() {
        return stock;
    }
};

class Store {
    string storeName;
    vector<PhoneBrand *> phoneBrands;
public:
    static int soldAmount;

    Store(string storeName = "") {
        this -> storeName = storeName;
    }
    void addPhoneBrand(PhoneBrand *phoneBrand) {
        phoneBrands.push_back(phoneBrand);
    }
    void sellPhone(PhoneBrand *phoneBrand, int quantity) {
        int size = phoneBrands.size();

        for(int i = 0; i < size; i++) {
            if(phoneBrands.at(i) == phoneBrand) {
                phoneBrands[i] -> sell(quantity);
                soldAmount += quantity;
                break;
            }
        }
    }
    void restockPhone(PhoneBrand *phoneBrand, int quantity) {
        int size = phoneBrands.size();

        for(int i = 0; i < size; i++) {
            if(phoneBrands.at(i) == phoneBrand) {
                phoneBrands[i] -> restock(quantity);
                break;
            }
        }
    }
    void phoneReturned(PhoneBrand *phoneBrand, int quantity) {
        restockPhone(phoneBrand, quantity);
        soldAmount -= quantity;
    }
    void printStock() {
        cout << "Store: " << storeName << endl;
        cout << "Current stock:" << endl;

        int size = phoneBrands.size();

        for(int i = 0; i < size; i++) {
            cout << "  " << phoneBrands[i] -> getBrandName() <<
                    ": " << phoneBrands[i] -> getStock() << endl;
        }

        cout << "Total sold amount: " << soldAmount << endl;
    }
};