#include <iostream>
#include <vector>
using namespace std;

class Student {
    string studentName;
    int creditsGot;
    int creditsLeft;
public:
    static int credits;

    Student(string studentName = "", int creditsGot = 0) {
        this -> studentName = studentName;
        this -> creditsGot = creditsGot;
    }
    void calculateCreditsLeft() {
        creditsLeft = credits - creditsGot;
    }
    void printStudent() {
        cout << "Name: " << studentName << endl;
        cout << "Gotten credits: " << creditsGot << endl;
    }
    void printStudentWithLeft() {
        cout << "Name: " << studentName << endl;
        cout << "Credits gotten: " << creditsGot << endl;
        cout << "Credits left: " << creditsLeft << endl;
    }
};