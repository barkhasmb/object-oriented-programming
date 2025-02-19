#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

struct Address {
    string name; 
    char area;
    int num;
    int item; 
};

int main() {

    Address A[10];
    int random, temp = 0;

    for(int i = 0; i < 10; i++) {

        while(temp == 0) {

            random = rand() % 91;
            if(random > 64) {
                A[i].name = random;
                temp = 1;
            }

        }
        temp = 0;

        while(temp < 3) {

            random = rand() % 58;
            if(random > 47) {
                A[i].name += random;
                temp++;
            }

        }
        temp = 0;

        if(rand() % 2 == 0) 
            A[i].area = 85;
        else
            A[i].area = 82;

        while(temp == 0) {

            random = rand() % 2501;
            if(random > 99) {
                A[i].num = random;
                temp = 1;
            }

        }
        temp = 0;

        A[i].item = rand() % 4 + 1;
    }

    cout << left
         << setw(5) << "Name"
         << setw(5) << "Num"
         << setw(5) << "Area"
         << setw(5) << "Item" << endl;

    for(int i = 0; i < 10; i++) {
        cout << left
             << setw(5) << A[i].name
             << setw(5) << A[i].num
             << setw(5) << A[i].area
             << setw(5) << A[i].item << endl;
    }
    return 0;
}