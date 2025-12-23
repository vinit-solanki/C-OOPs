#include <iostream>
using namespace std;

class Animal {
private:
    void privateMethod() {
        cout << "This is a private method of Animal" << endl;
    }

protected:
    // protected so child classes can use / override it
    virtual void makeSound() {
        privateMethod();   // private usable inside same class
        cout << "Some generic animal sound" << endl;
    }

public:
    void eat() {
        cout << "Eating..." << endl;
    }

    void sleep() {
        cout << "Sleeping..." << endl;
    }

    // Always good practice for base class
    virtual ~Animal() {}
};

/*
    Cat --> Animal <-- Dog
    This is HIERARCHICAL INHERITANCE
*/

/*
    Dog : protected Animal
    public members of Animal become protected in Dog
*/
class Dog : protected Animal {
protected:
    // Proper overriding (virtual + same signature)
    void makeSound() override {
        cout << "Bark Bark" << endl;
    }

public:
    void dogActions() {
        makeSound();   // OK (own + overridden)
        eat();         // OK (became protected)
        sleep();       // OK (became protected)
    }
};

/*
    Cat : private Animal
    public + protected members of Animal become private in Cat
*/
class Cat : private Animal {
public:
    void makeSound() {
        cout << "Meow Meow" << endl;
    }

    void catActions() {
        makeSound();   // own function
        eat();         // accessible inside class
        sleep();       // accessible inside class
    }
};

// Multi-Level Inheritance 
class Puppy : public Dog {
public:
    void puppyActions() {
        cout<<"Puppy Actions:"<<endl;
        makeSound();   // OK (inherited protected)
        eat();         // OK (inherited protected)
    }
};
int main() {
    cout << "----- INHERITANCE DEMO -----\n\n";

    Dog dog;
    dog.dogActions();

    cout << endl;

    Cat cat;
    cat.catActions();

    cout << endl;
    Puppy puppy;
    puppy.puppyActions();
    
    return 0;
}
