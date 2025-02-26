#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
using namespace std;

void print_csv_line(string csv_line) {

    for(int i = 0; i < csv_line.size(); i++) {

        if(csv_line[i] != 44)
            cout << csv_line[i];
        else
            cout << endl;
    }

    cout << endl;
}

int main() {

    print_csv_line("Print,each,word,in,different,lines.");

    return 0;
}