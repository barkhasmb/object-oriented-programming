#include <iostream>
#include <iomanip>
using namespace std;

struct Address {
    string name; 
    char area;
    int num;
    int item; 
};

int main() {

    Address A;

    cout << "Name: "; 
    cin >> A.name;

    cout << "Area: "; 
    cin >> A.area;

    cout << "Num: "; 
    cin >> A.num;

    cout << "Item: "; 
    cin >> A.item;

    cout << left << setw(5) << "Name" << setw(5) << "Num" << setw(5) << "Area" << setw(5) << "Item" << endl;
    cout << left << setw(5) << A.name << setw(5) << A.num << setw(5) << A.area << setw(5) << A.item << endl;

    return 0;
}