#include <iostream>
using namespace std;

class Point {
public:
    int x, y;

    Point(int a, int b) : x(a), y(b) {}

    Point operator+(Point& p) {
        return Point(x + p.x, y + p.y);
    }
    Point operator+=(Point& p) {
        x += p.x;
        y += p.y;
        return *this;
    }
};

int main() {
    Point p1(2, 3), p2(4, 5);
    Point p3 = p1 + p2;
    cout << p3.x << " " << p3.y << endl;
    p1 += p2;
    cout<<"After p1 += p2: ";
    cout << p1.x << " " << p1.y << endl;
    return 0;
}
