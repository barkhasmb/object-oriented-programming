#include <iostream>
#include <vector>
using namespace std;

inline void hr() {
    cout << "-------------------------------------------------------" << endl;
}

inline void lb() {
    cout << endl;
}

static int mlegs;

class Animal {
    protected:
        int nleg;
    public:
        void setNumberOfLegs(int nleg) {
            this -> nleg = nleg;
            mlegs = (mlegs < nleg) ? nleg : mlegs;
        }
        void isMostLegged() {
            if(nleg == mlegs)
                cout << "I have the most legs: True" << endl;
            else
                cout << "I have the most legs: False" << endl;
        }
};

class Cat: public Animal {};

class Dog: public Animal {};

class Mouse: public Animal {};

int main() {
    Cat cat;
    Dog dog;
    Mouse mouse;

    cat.setNumberOfLegs(1);
    dog.setNumberOfLegs(2);
    mouse.setNumberOfLegs(3);

    cout << "Most legs: " << mlegs << endl;

    cat.isMostLegged();
    dog.isMostLegged();
    mouse.isMostLegged();
    return 0;
}