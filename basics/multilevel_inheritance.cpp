#include<iostream>
using namespace std;
class Grandparent {
    protected:
    string family_name;
    public:
    Grandparent() {
        family_name = "Unknown";
        cout << "Grandparent default constructor called" << endl;
    }
    void SetFamilyName(string name) {
        family_name = name;
    }
    void PrintFamilyName() {
        cout << "Family Name: " << family_name << endl;
    }
    ~Grandparent() {
        cout << "Grandparent destructor called" << endl;
    }
};
class Parent : public Grandparent {
    protected:
    string parent_name;
    public:
    Parent() {
        parent_name = "Unknown";
        cout << "Parent default constructor called" << endl;
    }
    void SetParentName(string name) {
        parent_name = name;
    }
    void PrintParentName() {
        cout << "Parent Name: " << parent_name << endl;
    }
    ~Parent() {
        cout << "Parent destructor called" << endl;
    }
};
class Child : public Parent {
    protected:
    string child_name;
    public:
    Child() {
        child_name = "Unknown";
        cout << "Child default constructor called" << endl;
    }
    void SetChildName(string name) {
        child_name = name;
    }
    void PrintChildName() {
        cout << "Child Name: " << child_name << endl;
    }
    ~Child() {
        cout << "Child destructor called" << endl;
    }
};  
int main(){
    Child c;
    c.SetFamilyName("Smith");
    c.SetParentName("John Smith");
    c.SetChildName("Emily Smith");
    cout << "---------------------" << endl;
    c.PrintFamilyName();
    c.PrintParentName();
    c.PrintChildName();
    cout << "---------------------" << endl;
    
    return 0;
}