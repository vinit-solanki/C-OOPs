#include <iostream>
using namespace std;

class Point {
public:
    int x, y;

    Point(int a, int b) : x(a), y(b) {}

    Point operator+(Point& p) {
        return Point(x + p.x, y + p.y);
    }
};

int main() {
    Point p1(2, 3), p2(4, 5);
    Point p3 = p1 + p2;
    cout << p3.x << " " << p3.y << endl;
}
