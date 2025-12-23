#include <iostream>
using namespace std;

class StudentShallow {
public:
    string name;
    double* cgpa;

    StudentShallow(string name, double gpa) {
        this->name = name;
        cgpa = new double(gpa);
    }

    // Default copy constructor (shallow copy)
    // pointer is copied, NOT the data
    StudentShallow(const StudentShallow& obj) {
        name = obj.name;
        cgpa = obj.cgpa;  // shallow copy
        cout << "Shallow Copy Constructor called\n";
    }

    void print() {
        cout << "Name: " << name << ", CGPA: " << *cgpa << endl;
    }

    ~StudentShallow() {
        delete cgpa;
        cout << "Destructor called for " << name << endl;
    }
};

int main() {
    cout << "----- SHALLOW COPY DEMO -----\n";

    StudentShallow s1("Rahul", 3.8);
    StudentShallow s2 (s1);   // shallow copy

    cout<< "Before modifying s1's CGPA:\n";
    s1.print();
    s2.print();

    *s1.cgpa = 4.0;

    cout<< "After modifying s1's CGPA:\n";
    s1.print();
    s2.print();   // also changed
    return 0;
}
