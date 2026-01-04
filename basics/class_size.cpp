#include <iostream>
using namespace std;
class Empty{

};
class Simple{
    int a;
};
class Padding{
    int a;
    char b;
    // compiler adds 3 bytes of padding here for alignment
};
class Complex{
    int a;
    double b;
    char c;
    // compiler adds padding to align double and overall structure
};
class Alignment1{
    int a;
    double b;
    char c;
};
class Alignment2{
    double b;
    char c;
    int a;
};
int main(){
    Empty e1;
    cout<<sizeof(e1)<<endl; // typically 1 byte
    Simple s1;
    cout<<sizeof(s1)<<endl; // typically 4 bytes (4 for int)
    Padding p1;
    cout<<sizeof(p1)<<endl; // typically 8 bytes (4 for int + 1 for char + 3 padding)
    Complex c1;
    cout<<sizeof(c1)<<endl; // typically 24 bytes (4 for int + 4 padding + 8 for double + 1 for char + 7 padding)
    Alignment1 a1;
    cout<<sizeof(a1)<<endl; // typically 24 bytes (4 for int + 4 padding + 8 for double + 1 for char + 7 padding)
    Alignment2 a2;
    cout<<sizeof(a2)<<endl; // typically 16 bytes (8 for double + 1 for char + 3 padding + 4 for int)
    return 0;
}