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

struct Success {
    int Code;
    string Name;
    int G;
    int B;
    int Total;
};

inline void hr() {
    cout << "-------------------------------------------------------" << endl;
}

void input_students(Student *S) {

    int random;

    string school[3] = {"S114", "U007", "C089"};

    for(int i = 0; i < 5; i++) {

        random = rand() % 90 + 10;
        S[i].Code = random;

        S[i].Class = 49;
        random = rand() % 4 + 97;
        S[i].Class += random;

        random = rand() % 3;
        S[i].Name = school[random];
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

    hr();

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

void success_by_code(Student *S, Grade *G, Success *Su) {

    for(int i = 0; i < 5; i++) {

        Su[i].Code = S[i].Code;
        Su[i].Name = S[i].Name;
        Su[i].G = 0;
        Su[i].B = 0;
        Su[i].Total = 0;

        for(int j = 0; j < 10; j++) {

            if(Su[i].Code == G[j].Code) {
                if(G[j].R == 71) 
                    Su[i].G++;
                else 
                    Su[i].B++;
                Su[i].Total++;
            }
        }
    }

    float ratio;

    hr();

    cout << left
         << setw(6) << "Code"
         << setw(6) << "G"
         << setw(6) << "B"
         << setw(6) << "Total"
         << setw(6) << "%" << endl;

    for(int i = 0; i < 5; i++) {
        ratio = Su[i].G * 100;
        ratio /= Su[i].Total;
        cout << left
             << setw(6) << Su[i].Code
             << setw(6) << Su[i].G
             << setw(6) << Su[i].B
             << setw(6) << Su[i].Total
             << setw(6) << ratio << endl;
    }
}

void success_by_name(Success *Su) {

    int table_count = 0;
    string table_name[5];
    int table_data[5][3];
    bool match = false;

    for(int i = 0; i < 5; i++, match = false) {

        for(int j = 0; j < table_count; j++) {

            if(table_name[j] == Su[i].Name) {
                match = true;
                table_data[j][0] += Su[i].G;
                table_data[j][1] += Su[i].B;
                table_data[j][2] += Su[i].Total;
            }
        }

        if(match == false) {
            table_name[table_count] = Su[i].Name;
            table_data[table_count][0] = Su[i].G;
            table_data[table_count][1] = Su[i].B;
            table_data[table_count][2] = Su[i].Total;
            table_count++;
        }
    }

    float ratio;

    hr();

    cout << left
         << setw(6) << "Name"
         << setw(6) << "G"
         << setw(6) << "B"
         << setw(6) << "Total"
         << setw(6) << "%" << endl;

    for(int i = 0; i < table_count; i++) {
        ratio = table_data[i][0] * 100;
        ratio /= table_data[i][2];
        cout << left
             << setw(6) << table_name[i]
             << setw(6) << table_data[i][0]
             << setw(6) << table_data[i][1]
             << setw(6) << table_data[i][2]
             << setw(6) << ratio << endl;
    }
}

int main() {

    Student S[5];

    Grade G[10];

    Success Su[5];

    input_students(S);

    list_students(S);

    input_grades(G, S);

    list_grades(G);

    success_by_code(S, G, Su);

    success_by_name(Su);

    return 0;
}