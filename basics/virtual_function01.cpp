#include<iostream>
using namespace std;

class Shape{
    public:
    virtual int area() = 0; // pure virtual function
    // this will cause ambiguity 
    // since both int and double area() cannot be resolved
    // virtual double area() = 0; // pure virtual function for double
    virtual void display() = 0; // pure virtual function
    virtual ~Shape(){
        cout<<"Shape destructor called"<<endl;
    }
};

class Circle: public Shape{
    int radius;
    public:
    Circle(int r): radius(r) {}
    Circle(double r): radius(r) {} // constructor
    int area() override {
        return 3.14 * radius * radius;
    }
    // this will cause ambiguity
    // double area() override {}
    int getRadius() {
        return radius;
    }
    void display() {
        cout << "Radius: " << radius << ", Area: " << area() << endl;
    }
    void setRadius(int r) {
        radius = r;
    }
};

class Rectangle: public Shape{
    int width, height;
    public:
    Rectangle(int w, int h): width(w), height(h) {}
    Rectangle(double w, double h): width(w), height(h) {} // square constructor

    int area() override {
        return width * height;
    }
    // this will cause ambiguity 
    // double area() override {
    //     return static_cast<double>(width) * static_cast<double>(height);
    // }
    int getWidth() {
        return width;
    }
    int getHeight() {
        return height;
    }
    void display() {
        cout << "Width: " << width << ", Height: " << height << ", Area: " << area() << endl;
    }
    void setWidth(int w) {
        width = w;
    }
    void setHeight(int h) {
        height = h;
    }
    ~Rectangle(){
        cout<<"Rectangle destructor called"<<endl;
    }
};

void printArea(Shape* shape){
    cout<<"Area: "<<shape->area()<<endl;
}

int main(){
    Shape* shape1 = new Circle(5);
    printArea(shape1);
    shape1->display();
    delete shape1;

    Shape* shape2 = new Rectangle(4, 6);
    shape2->area();
    shape2->display();
    delete shape2;

    return 0;
}