#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

struct Student {
    int Code; 
    string Class;
    string Name; 
};

struct Grade {
    int Code;
    string Date;
    int A;
    int B;
    int C;
    char R;
};

void input_students(Student *S) {

    int random;

    for(int i = 0; i < 5; i++) {

        random = rand() % 90 + 10;
        S[i].Code = random;

        S[i].Class = 49;
        random = rand() % 4 + 97;
        S[i].Class += random;

        random = rand() % 26 + 65;
        S[i].Name = random;

        for(int j = 0; j < 3; j++) {

            random = rand() % 10 + 48;
            S[i].Name += random;
        }
    }
}

void list_students(Student *S) {

    cout << left
         << setw(6) << "Code"
         << setw(6) << "Class"
         << setw(6) << "Name" << endl;

    for(int i = 0; i < 5; i++) {
        cout << left
             << setw(6) << S[i].Code
             << setw(6) << S[i].Class
             << setw(6) << S[i].Name << endl;
    }
}

void input_grades(Grade *G, Student *S) {

    int random;

    for(int i = 0; i < 10; i++) {

        G[i].Code = S[rand() % 5].Code;

        G[i].Date = "07";
        random = rand() % 31 + 1;
        G[i].Date += random / 10 + 48;
        G[i].Date += random % 10 + 48;

        random = rand() % 100;
        G[i].A = random;

        random = rand() % 100;
        G[i].B = random;

        random = rand() % 100;
        G[i].C = random;

        if(rand() % 2 == 0) 
            G[i].R = 71;
        else
            G[i].R = 66;

    }
}

void list_grades(Grade *G) {

    cout << "-------------------------------------------------------" << endl;

    cout << left
         << setw(6) << "Code"
         << setw(6) << "Date"
         << setw(6) << "A"
         << setw(6) << "B"
         << setw(6) << "C"
         << setw(6) << "R" << endl;

    for(int i = 0; i < 10; i++) {
        cout << left
             << setw(6) << G[i].Code
             << setw(6) << G[i].Date
             << setw(6) << G[i].A
             << setw(6) << G[i].B
             << setw(6) << G[i].C
             << setw(6) << G[i].R << endl;
    }
}

int main() {

    Student S[5];

    Grade G[10];

    input_students(S);

    list_students(S);

    input_grades(G, S);

    list_grades(G);

    return 0;
}