#include <iostream>
#include <vector>
using namespace std;

inline void hr() {
    cout << "-------------------------------------------------------" << endl;
}

inline void lb() {
    cout << endl;
}

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

int main() {
    Player p1("Bolt", 9.46);
    Player p2("Fox", 9.44);
    if(compareRating(p1, p2)) 
        p1.print();
    else
        p2.print();
    return 0;
}