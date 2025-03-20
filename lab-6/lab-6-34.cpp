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

inline void lb() {
    cout << endl;
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

void write_to_file(Result R, string filename) {

    ofstream gradesFile(filename);

    if(gradesFile.is_open()) {

        gradesFile << "Code" << "," 
                   << "Date" << ","  
                   << "A" << "," 
                   << "B" << "," 
                   << "C" << endl;

        // for(int i = 0; i < 10; i++) {
        //     gradesFile << R.Code << "," 
        //                << R.Date << ","  
        //                << R.A << "," 
        //                << R.B << "," 
        //                << R.C << endl;
        // }

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

void print_code_from_file(int code, string filename) {

    ifstream gradesFile(filename);
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

void print_with_r_from_file(int code, string filename) {

    ifstream gradesFile(filename);
    string line;
    char random;

    bool first = true;

    if(gradesFile.is_open()) {

        while(getline(gradesFile, line)) {

            string word = "";
            int space = 0;
            int num;

            if(first == false) {
                word += line[0];
                word += line[1];
                if(code != convert(word))
                    break;
                word = "";
            }

            for(int i = 0; i <= line.size(); i++) {

                if(line[i] != 44 && i < line.size()) {

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

void print_total_from_file(int code, string filename) {

    ifstream gradesFile(filename);
    string line;
    char random;
    int good = 0, bad = 0;
    float p;

    bool first = true;

    if(gradesFile.is_open()) {

        while(getline(gradesFile, line)) {

            string word = "";
            int space = 0;
            int num;

            if(!first) {
                word += line[0];
                word += line[1];
                if(code != convert(word))
                    break;
                word = "";
            }

            for(int i = 0; i <= line.size(); i++) {

                if(line[i] != 44 && i < line.size()) {

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

            if(first) {
                
                first = false;

            } else {

                if(random == 0) 
                    good++;
                else
                    bad++;
            }
        }

        p = 100 / (good + bad) * good;

        cout << left
             << setw(6) << "Code"
             << setw(6) << "G"
             << setw(6) << "B"
             << setw(6) << "Total"
             << setw(6) << "%" << endl;
             
        cout << left << fixed << setprecision(1)
             << setw(6) << code
             << setw(6) << good
             << setw(6) << bad
             << setw(6) << good + bad
             << setw(6) << p << endl;

        gradesFile.close();

    } else {

        cerr << "Error occurred when opening file." << endl;

    }

}

int main() {

    // Student S[5];
    // Result R[10];

    // input_students(S);

    // hr();

    // list_students(S);

    // input_results(R, S);

    // hr();

    // list_results(R);

    // hr();

    // print_code_from_file(12, "scores.csv");

    hr();

    print_with_r_from_file(12, "scores.csv");

    hr();

    print_total_from_file(12, "scores.csv");

    hr();

    return 0;
}