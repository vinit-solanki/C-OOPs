#include <iostream>
using namespace std;

class Animal {
protected:
    string name;

public:
    Animal(string n = "Animal") : name(n) {}

    virtual void sound() {
        cout << "Animal makes a sound" << endl;
    }

    void eat() {
        cout << name << " is eating" << endl;
    }

    virtual ~Animal() {}
};


class Swimmer {
public:
    void swim() {
        cout << "Swimming..." << endl;
    }
};

class Runner {
public:
    void run() {
        cout << "Running..." << endl;
    }
};

// Duck has multiple parents
class Duck : public Animal, public Swimmer, public Runner {
public:
    Duck(string n = "Duck") : Animal(n) {}

    void sound() override {
        cout << name << " quacks" << endl;
    }
};

int main(){
    cout << "----- MULTIPLE INHERITANCE DEMO -----\n\n";

    Duck daffy("Daffy Duck");
    daffy.eat();      // from Animal
    daffy.swim();     // from Swimmer
    daffy.run();      // from Runner
    daffy.sound();    // overridden in Duck

    return 0;
}