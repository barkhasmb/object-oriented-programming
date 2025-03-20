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

inline void lb() {
    cout << endl;
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

    cout << left << setw(6) << word;
}

void print_student_from_grades_file(int code) {

    ifstream gradesFile("grades.csv");
    string line;

    bool first = true;

    if(gradesFile.is_open()) {

        while(getline(gradesFile, line)) {

            if(first == true) {

                print_csv_line(line);
                lb();
                first = false;
            }
            else if((line[0] - 48) * 10 + line[1] - 48 == code) {

                print_csv_line(line);
                lb();

            }

        }

        gradesFile.close();

    } else {

        cerr << "Error occurred when opening file." << endl;

    }

}

int convert(string word) {

    int num = 0;

    for(int i = 0; i < word.size(); i++) {
        num *= 10;
        num += word[i] - 48;
    }

    return num;

}

void print_with_r_from_grades_file() {

    ifstream gradesFile("grades.csv");
    string line;
    char random;

    bool first = true;

    if(gradesFile.is_open()) {

        while(getline(gradesFile, line)) {

            string word = "";
            int space = 0;
            int num;

            for(int i = 0; i < line.size(); i++) {

                if(line[i] != 44) {

                    word += line[i];

                } else {

                    num = convert(word);

                    switch(space) {
                        case 2:
                            random = num;
                            break;
                        case 3:
                            random += num;
                            break;
                        case 4:
                            random -= num;
                            break;
                    }

                    space++;
                    word = "";
                }
            }

            if(random == 0) 
                random = 71;
            else
                random = 66;

            if(first == true) {

                print_csv_line(line);
                cout << left << setw(6) << "R" << endl;
                first = false;
            }
            else {

                print_csv_line(line);
                cout << left << setw(6) << random << endl;

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

    print_student_from_grades_file(48);

    hr();

    print_with_r_from_grades_file();

    return 0;
}