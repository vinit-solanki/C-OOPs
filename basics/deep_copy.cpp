#include <iostream>
using namespace std;

class Student {
public:
    string name;
    double* cgpa;

    Student(string name, double gpa) {
        this->name = name;
        cgpa = new double(gpa);
    }

    // Deep Copy Constructor
    Student(const Student& obj) {
        name = obj.name;
        cgpa = new double(*obj.cgpa);  // separate memory
        cout << "Deep Copy Constructor called\n";
    }

    void print() {
        cout << "Name: " << name << ", CGPA: " << *cgpa << endl;
    }

    // Destructor
    ~Student() {
        delete cgpa;
        cout << "Destructor called for " << name << endl;
    }
};

int main() {
    cout << "----- DEEP COPY DEMO -----\n";

    Student s1("Rahul", 3.8);
    Student s2(s1);   // deep copy

    cout << "Before modifying s1:\n";
    s1.print();
    s2.print();

    *s1.cgpa = 4.0;
    s1.name = "Anita";

    cout << "\nAfter modifying s1:\n";
    s1.print();
    s2.print();   // unaffected

    return 0;
}
