#include <iostream>
using namespace std;

inline void hr() {
    cout << "-------------------------------------------------------" << endl;
}

inline void lb() {
    cout << endl;
}

class Phone {
    protected:
        int battery;
    public:
        Phone() {
            battery = 0;
        }
        void charge() {
            battery += 10;
        }
        void powerOn() {
            cout << "*Beep*" << endl;
        }
};

class Android: public Phone {
    public:
    void powerOn() {
        cout << "*Vibration*, *Beep*" << endl;
    }
};

class IOS: public Phone {};

int main() {
    Android android;
    IOS iphone;

    android.charge();
    iphone.charge();

    android.powerOn();
    iphone.powerOn();

    return 0;
}