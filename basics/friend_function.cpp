#include<iostream>
using namespace std;
class Complex{
    int real, img;
    public:
    Complex(int real=0, int img=0): real(real), img(img) {}
    friend Complex operator+(Complex c1, Complex c2);
    void display(){
        cout<<real<<" + i"<<img<<endl;
    }
};
Complex operator+(Complex c1, Complex c2){
    Complex temp;
    temp.real = c1.real + c2.real;
    temp.img = c1.img + c2.img;
    return temp;
}
int main(){
    Complex c1(2,3), c2(4,5);
    Complex c3 = c1+c2;
    c3.display();
    return 0;
}