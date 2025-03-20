#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
using namespace std;

class Student {
    int Code;
    string Class;
    string Name;

    public:
        void setStudent(int x, string y, string z) {
            Code = x;
            Class = y;
            Name = z;
        }

        int getCode() {
            return Code;
        }

        void printHeader() {
            cout << left
                 << setw(6) << "Code"
                 << setw(6) << "Class"
                 << setw(6) << "Name" << endl;;
        }

        void printStudent() {
            cout << left
                 << setw(6) << Code
                 << setw(6) << Class
                 << setw(6) << Name << endl;
        }
};

class Result {
    int Code;
    string Date;
    int A, B, C;

    public:
        void setResult(int x, string y, int a, int b, int c) {
            Code = x;
            Date = y;
            A = a;
            B = b;
            C = c;
        }

        int getCode() {
            return Code;
        }

        string evaluate() {
            if(A + B == C) 
                return "GOOD";
            else 
                return "BAD";
        }

        void printHeader() {
            cout << left
                 << setw(6) << "Code"
                 << setw(6) << "Date"
                 << setw(6) << "A"
                 << setw(6) << "B"
                 << setw(6) << "C"
                 << setw(6) << "R" << endl;
        }

        void printResult() {
            cout << left
                 << setw(6) << Code
                 << setw(6) << Date
                 << setw(6) << A
                 << setw(6) << B
                 << setw(6) << C
                 << setw(6) << evaluate() << endl;
        }
};

inline void hr() {
    cout << "-------------------------------------------------------" << endl;
}

void input_students(Student *S) {

    int random;

    string name[3] = {"S114", "U007", "C089"};
    string c[5] = {"1a", "1b", "1c", "1d", "1e"};

    for(int i = 0; i < 5; i++) 
        S[i].setStudent(rand() % 90 + 10, c[rand() % 5], name[rand() % 3]);
    
}

void list_students(Student *S) {

    S -> printHeader();

    for(int i = 0; i < 5; i++) 
        S[i].printStudent();

}

void input_results(Result *R, Student *S) {

    int random;
    string date;

    for(int i = 0; i < 10; i++) {

        date = "07";
        random = rand() % 31 + 1;
        date += random / 10 + 48;
        date += random % 10 + 48;

        R[i].setResult(S[rand() % 5].getCode(), date, rand() % 100, rand() % 100, rand() % 100);

    }
}

void list_results(Result *R) {

    R -> printHeader();

    for(int i = 0; i < 10; i++) 
        R[i].printResult();

}

void list_results_with_eval(Result *R) {

    R -> printHeader();

    for(int i = 0; i < 10; i++) {
        R[i].printResult();
    }

}

int main() {

    Student S[5];
    Result R[10];

    input_students(S);

    hr();
    list_students(S);

    input_results(R, S);

    hr();
    list_results(R);
    hr();
}