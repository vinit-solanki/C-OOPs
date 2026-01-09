#include<iostream>
using namespace std;
int main(){
    try {
        cout << "Inside try block" << endl;
        throw 20; // throwing an integer exception
        cout << "This line will not execute" << endl;
    }
    catch (int e) {
        cout << "Caught an integer exception: " << e << endl;
    }

    try{
        int a=10;
        int b;
        cin>>b;
        if(b==0){
            throw "Arithmetic Error, Division by zero!";
        }
        cout<<"Result: "<<a/b<<endl;
    } catch(const char*e){
        cout<<"Caught an exception: "<<e<<endl;
    }
    return 0;
}