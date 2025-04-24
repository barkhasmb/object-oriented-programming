#include <iostream>
#include <vector>
using namespace std;

inline void hr() {
    cout << "-------------------------------------------------------" << endl;
}

inline void lb() {
    cout << endl;
}

class Shape {
    public:
        virtual void draw() = 0;
        virtual ~Shape() {}
};

class Triangle: public Shape {
    public:
        void draw() override {
            cout << "Triangle" << endl;
        }
        ~Triangle() {}
};

class Rectangle: public Shape {
    public:
        void draw() override {
            cout << "Rectangle" << endl;
        }
        ~Rectangle() {}
};

class Circle: public Shape {
    public:
        void draw() override {
            cout << "Circle" << endl;
        }
        ~Circle() {}
};

int main() {
    vector<Shape *> shapes;

    for(int i = 0; i < 3; i++) {
        shapes.push_back(new Triangle);
    }
    for(int i = 0; i < 3; i++) {
        shapes.push_back(new Circle);
    }
    for(int i = 0; i < 3; i++) {
        shapes.push_back(new Rectangle);
    }

    for(Shape * shape : shapes) {
        shape -> draw();
    }

    return 0;
}