#include<iostream>
using namespace std;
class Complex{
    double real;
    double img;
    public:
    Complex(){
        real = 0;
        img = 0;
    }
    Complex(double real, double img){
        this->real = real;
        this->img = img;
    }
    void display(){
        cout << real << " + " << img << "i" << endl;
    }
    Complex operator+(Complex &C){
        Complex c3;
        c3.real = real + C.real;
        c3.img = img + C.img;
        return c3;
    }
    Complex operator-(Complex &C){
        Complex c3;
        c3.real = real - C.real;
        c3.img = img - C.img;
        return c3;
    }
    Complex operator*(Complex &C){
        Complex c3;
        // (a+ib)*(c+id) = (ac - bd) + i(ad + bc)
        c3.real = real * C.real - img*c3.img;
        c3.img = real*C.img + img*c3.real;
        return c3;
    }
    Complex operator/(Complex &C){
        Complex c3;
        // (a+ib)/(c+id) = [(ac + bd) + i(bc - ad)] / (c^2 + d^2)
        double denom = C.real*C.real + C.img*C.img;
        c3.real = (real * C.real + img * C.img) / denom;
        c3.img = (img * C.real - real * C.img) / denom;
        return c3;
    }
};
int main(){
    Complex c1(3, 4);
    Complex c2(1, 2);
    Complex c3 = c1 + c2;
    Complex c4 = c1 - c2;
    Complex c5 = c1 * c2;
    cout << "c1: ";
    c1.display();
    cout << "c2: ";
    c2.display();
    cout << "c1 + c2: ";
    c3.display();
    cout << "c1 - c2: ";
    c4.display();
    cout << "c1 * c2: ";
    c5.display();
    Complex c6 = c1 / c2;
    cout << "c1 / c2: ";
    c6.display();
    return 0;
}