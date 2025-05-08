#include <iostream>
#include <vector>
#include "myHeader.h"
using namespace std;

class Player {
    string name;
    float score;
    public:
        Player(string name = "", float score = 0) {
            this -> name = name;
            this -> score = score;
        }
        friend bool compareRating(Player& p1, Player& p2);
        void print() {
            cout << name << ": " << score << endl;
        }
};

bool compareRating(Player& p1, Player& p2) {
    return p1.score > p2.score;
}

class Lab14Task3: public Task {
    public:
        void process() override {
            cout << "*TASK-3*" << endl;
            Player p1("Bolt", 9.46);
            Player p2("Fox", 9.44);
            if(compareRating(p1, p2)) 
                p1.print();
            else
                p2.print();
        }
};
