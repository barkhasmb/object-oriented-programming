#include <iostream>
using namespace std;

inline void hr() {
    cout << "-------------------------------------------------------" << endl;
}

inline void lb() {
    cout << endl;
}

class Rectangle {
    protected:
        int width, height;
    public:
        void setRectangle(int width, int height) {
            this -> width = width;
            this -> height = height;
        }
        void display() {
            cout << "W = " << width 
                 << ", H = " << height << endl;
        }
};

class RectangleArea: public Rectangle {
    public:
    void display() {
        cout << "Area = " << width * height << endl;
    }
};

int main() {
    RectangleArea r_area;

    r_area.setRectangle(14, 20);
    r_area.Rectangle::display();
    r_area.display();

    return 0;
}