#include <iostream>
#include "myClasses.cpp"
using namespace std;

inline void hr() {
    cout << "-------------------------------------------------------" << endl;
}

inline void lb() {
    cout << endl;
}

int main() {
    Computer *pc1 = new Computer("Intel i7");
    Computer *pc2 = new Computer("AMD");
    Computer *pc3 = new Computer("M2");

    SchoolClass class1 = SchoolClass("Class No.1");
    SchoolClass class2 = SchoolClass("Class No.2");

    class1.addComputer(pc1);
    class1.addComputer(pc2);
    class1.addComputer(pc3);

    hr();
    class1.printComputers();
    lb();
    class2.printComputers();

    pc2 -> broken();

    class1.transfer(class2, pc3);

    hr();
    class1.printComputers();
    lb();
    class2.printComputers();
    hr();
    
    return 0;
}