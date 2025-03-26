#include <iostream>
#include "lab-8-1-classes.cpp"
using namespace std;

inline void hr() {
    cout << "-------------------------------------------------------" << endl;
}

inline void lb() {
    cout << endl;
}

int Student::credits = 120;

int main() {
    Student student1 = Student("Bat", 78);
    Student student2 = Student("Dorj", 112);
    Student student3 = Student("Saran", 18);

    hr();
    student1.printStudent();
    student2.printStudent();
    student3.printStudent();
    hr();

    student1.calculateCreditsLeft();
    student2.calculateCreditsLeft();
    student3.calculateCreditsLeft();

    student1.printStudentWithLeft();
    student2.printStudentWithLeft();
    student3.printStudentWithLeft();
    hr();
    return 0;
}