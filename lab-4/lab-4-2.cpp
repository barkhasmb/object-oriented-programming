#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
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

void write_to_grades_file(Grade *G) {

    ofstream gradesFile("grades.csv");

    if(gradesFile.is_open()) {

        gradesFile << "Code" << "," 
                   << "Date" << ","  
                   << "A" << "," 
                   << "B" << "," 
                   << "C" << endl;

        for(int i = 0; i < 10; i++) {
            gradesFile << G[i].Code << "," 
                       << G[i].Date << ","  
                       << G[i].A << "," 
                       << G[i].B << "," 
                       << G[i].C << endl;
        }

        gradesFile.close();

    } else {

        cerr << "Error occurred when opening file." << endl;

    }

}

void print_csv_line(string csv_line) {

    string word = "";

    for(int i = 0; i < csv_line.size(); i++) {

        if(csv_line[i] != 44) {

            word += csv_line[i];

        } else {
            cout << left << setw(6) << word;
            word = "";
        }
    }

    cout << left << setw(6) << word << endl;
}

void print_from_grades_file(int code) {

    ifstream gradesFile("grades.csv");
    string line;

    bool first = true;

    if(gradesFile.is_open()) {

        while(getline(gradesFile, line)) {

            if(first == true) {

                print_csv_line(line);
                first = false;
            }
            else if((line[0] - 48) * 10 + line[1] - 48 == code) {

                print_csv_line(line);

            }

        }

        gradesFile.close();

    } else {

        cerr << "Error occurred when opening file." << endl;

    }

}

int main() {

    Student S[5];

    Grade G[10];

    Success Su[5];

    input_students(S);

    input_grades(G, S);

    write_to_grades_file(G);

    print_from_grades_file(48);

    return 0;
}