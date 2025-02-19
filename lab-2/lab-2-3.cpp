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

void input(Address *A) {
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
}

void list(Address *A) {

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
}

void ur_item(Address *A) {

    int a[2][5] = {0};
    char ur[2] = {85, 82};

    for(int i = 0; i < 10; i++) {

        if(A[i].area == 85) {
            a[0][A[i].item - 1]++;
            a[0][4]++;
        } else {
            a[1][A[i].item - 1]++;
            a[1][4]++;
        }
    }

    cout << "-------------------------------------------------------" << endl;

    cout << left
         << setw(5) << "Area"
         << setw(5) << "1"
         << setw(5) << "2"
         << setw(5) << "3"
         << setw(5) << "4"
         << setw(5) << "Total" << endl;

    for(int i = 0; i < 2; i++) {
        cout << left
             << setw(5) << ur[i]
             << setw(5) << a[i][0]
             << setw(5) << a[i][1]
             << setw(5) << a[i][2]
             << setw(5) << a[i][3]
             << setw(5) << a[i][4] << endl;
    }
}

int main() {

    Address A[10];

    input(A);

    list(A);

    ur_item(A);

    return 0;
}