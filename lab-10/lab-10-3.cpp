#include <iostream>
using namespace std;

inline void hr() {
    cout << "-------------------------------------------------------" << endl;
}

inline void lb() {
    cout << endl;
}

template <typename type1, typename type2>
void add(type1 a, type2 b) {
    cout << a + b << endl;
}

template <typename type1, int>
void add(type1 a, int b) {
    cout << a + (float)b << endl;
}

template <typename type>
void swapit(type &a, type &b) {
    type temp = a;
    a = b;
    b = temp;
}

class Line {
    int length;
public:
    void setLength(int length) {
        this -> length = length;
    }
    int getLength() {
        return length;
    }
    Line operator+ (const Line &p) {
        Line line;
        line.setLength(this -> length + p.length);
        return line;
    }
    Line operator- (const Line &p) {
        Line line;
        line.setLength(this -> length - p.length);
        if(line.length < 0) 
            line.setLength(0);
        return line;
    }
};

int main() {

    add <int, int> (5, 2);
    add <float, int> (10.0, 4);
    add <float, float> (15.0, 6.0);
    add <int, float> (20, 8.0);

    hr();
    
    float a = 5.2, b = 0.99;
    swapit <float> (a, b);
    cout << a << ", " << b << endl;

    hr();

    Line line1, line2, line3;
    line1.setLength(5);
    line2.setLength(8);
    line3 = line1 - line2;
    cout << line3.getLength() << endl;
    swapit <Line> (line1, line2);
    cout << line1.getLength() << ", " << line2.getLength() << endl;

    return 0;
}