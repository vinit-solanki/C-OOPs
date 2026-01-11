#include <iostream>
using namespace std;

/* ================= BASE CLASS ================= */
class Animal {
protected:
    string name;

public:
    Animal(string n = "Animal") : name(n) {
        cout << "Animal constructor called\n";
    }

    virtual void sound() {
        cout << "Animal makes a sound\n";
    }

    virtual void eat() {
        cout << name << " is eating\n";
    }

    virtual ~Animal() {
        cout << "Animal destructor called\n";
    }
};

/* ================= INTERMEDIATE CLASSES ================= */
/* Virtual inheritance solves the diamond problem */

class Mammal : virtual public Animal {
public:
    Mammal() {
        cout << "Mammal constructor called\n";
    }

    void mammalFeature() {
        cout << name << " is warm-blooded\n";
    }
    void eat() override {
        cout << name << " the mammal is eating\n";
    }
};

class Pet : virtual public Animal {
public:
    Pet() {
        cout << "Pet constructor called\n";
    }

    void petFeature() {
        cout << name << " is friendly\n";
    }
    void eat() override {
        cout << name << " the pet is eating\n";
    }
};

/* ================= DERIVED CLASS ================= */

class Dog : public Mammal, public Pet {
public:
    // MOST DERIVED CLASS initializes virtual base
    Dog(string n) : Animal(n) {
        cout << "Dog constructor called\n";
    }

    void sound() override {
        cout << name << " barks: Woof Woof!\n";
    }

    void eat() override {
        cout << name << " the dog is eating\n";
    }

    void dogFeature() {
        cout << name << " guards the house\n";
    }

    ~Dog() {
        cout << "Dog destructor called\n";
    }
};

/* ================= MAIN FUNCTION ================= */

int main() {
    cout << "\n----- DIAMOND INHERITANCE DEMO -----\n\n";

    Dog d("Buddy");

    cout << "\n--- Calling methods ---\n";
    d.sound();           // Dog override
    d.Pet::eat();             // Animal (only ONE copy)
    d.mammalFeature();   // Mammal method
    d.petFeature();      // Pet method
    d.dogFeature();      // Dog method

    cout << "\n--- Polymorphism test ---\n";
    Animal* a = &d;
    a->sound();          // Dynamic binding → Dog::sound()
    a->eat();            // Animal::eat()

    cout << "\n--- Program End ---\n";
    return 0;
}
