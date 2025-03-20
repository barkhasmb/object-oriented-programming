#include <iostream>
#include "myClasses.cpp"
using namespace std;

int main() {
    Computer *pc1 = new Computer("Intel i7");
    Computer *pc2 = new Computer("AMD");
    Computer *pc3 = new Computer("M2");

    SchoolClass class1 = SchoolClass("Class No.1");
    SchoolClass class2 = SchoolClass("Class No.2");

    class1.addComputer(pc1);
    class1.addComputer(pc2);
    class1.addComputer(pc3);

    pc2 -> broken();

    class1.transfer(class2, pc3);
    
    return 0;
}