#include<iostream>
#include<vector>
using namespace std;

class Animal{
    public:
    void speak(){
        cout<<"Animal speaks"<<endl;
    }
    // Pure virtual function example
    virtual void eat() = 0;
    // Virtual destructor
    ~Animal(){
        cout<<"Animal destructor called"<<endl;
    }
};

class Dog: public Animal{
    public:
    void speak() {
        cout<<"Dog barks"<<endl;
    }

    // compulsory override of pure virtual function
    void eat() override {
        cout<<"Dog eats"<<endl;
    }
    ~Dog(){
        cout<<"Dog destructor called"<<endl;
    }
};
class AnimalClass{
    public:
    virtual void speak(){
        cout<<"Animal speaks"<<endl;
    }
    virtual ~AnimalClass(){} // Virtual destructor
};
class Cat: public AnimalClass{ // virtual public wont make any difference here
    public:
    void speak() override {
        cout<<"Cat meows"<<endl;
    }
    ~Cat(){
        cout<<"Cat destructor called"<<endl;
    }
};
int main(){
    Dog dog;
    Animal* animalPtr;
    animalPtr = &dog;
    // Calls the base class method because speak is not virtual
    animalPtr->speak(); // Output: Animal speaks
    animalPtr->eat();   // Output: Dog eats

    Cat cat;
    AnimalClass* animalClassPtr;
    animalClassPtr = &cat;
    // Calls the overridden method in Cat class
    animalClassPtr->speak(); // Output: Cat meows
    return 0;
}