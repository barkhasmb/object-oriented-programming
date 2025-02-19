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

    int a = 89;
    char b = a;
    string c = "S";
    c += rand() % 101;
    cout << b << endl;
    cout << c << endl;

    return 0;
}