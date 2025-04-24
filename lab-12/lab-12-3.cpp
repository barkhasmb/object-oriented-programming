#include <iostream>
#include <vector>
using namespace std;

inline void hr() {
    cout << "-------------------------------------------------------" << endl;
}

inline void lb() {
    cout << endl;
}

class Person {
    string name;
    int age;
    public:
        void printName() {
            cout << "Name: " << "John" << endl;
        }
};

class Student: virtual public Person {
    string school;
    float gpa;
    public:
};

class Employee: virtual public Person {
    string company;
    int salary;
    public:
        void printSalary() {
            cout << "Salary: " << 1500000 << endl;
        }
};

class WorkingStudent: public Student, public Employee {

};

int main() {
    WorkingStudent ws;
    
    ws.printName();
    ws.printSalary();

    return 0;
}