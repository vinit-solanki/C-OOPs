#include<iostream>
using namespace std;
class Animal {
    int price;
    protected:
    string origin;
    int age;
    int weight;
    public:
    void getPrice(string password){
        if(password == "admin123"){
            cout << "Price: " << price << endl;
        }
        else{
            cout << "Access Denied: Incorrect Password" << endl;
        }
    }
    string name;
    string color;
    Animal(){
        cout << "Animal default constructor called" << endl;
        origin = "Unknown";
        age = 0;
        weight = 0;
        name = "Unknown";
        color = "Unknown";
        price=0;
    }
    void setPrice(string password, int p){
        if(password == "admin123"){
            price = p;
        }
        else{
            cout << "Access Denied: Incorrect Password" << endl;
        }
    }
    void SetDetails(string o, int a, int w){
        origin = o;
        age = a;
        weight = w;
    }
    void PrintDetails(){
        cout << "Origin: " << origin << endl;
        cout << "Age: " << age << endl;
        cout << "Weight: " << weight << endl;
        cout << "Name: " << name << endl;
        cout << "Color: " << color << endl;
    }
    ~Animal(){
        cout << "Animal destructor called" << endl;
    }
};

class Dog : public Animal {
    public:
    string breed;
    Dog(){
        breed = "Unknown";
        cout << "Dog default constructor called" << endl;
    }
    void SetDogInfo(string o, int a, int w, string n, string c, string b){
        SetDetails(o, a, w);
        name = n;
        color = c;
        breed = b;
    }
    void PrintDogInfo(){
        PrintDetails();
        cout << "Breed: " << breed << endl;
    }
    ~Dog(){
        cout << "Dog destructor called" << endl;
    }
};

class Puppy : public Dog {
    public:
    string puppy_name;
    Puppy(){
        puppy_name = "Unknown";
        cout << "Puppy default constructor called" << endl;
    }
    void SetPuppyInfo(string o, int a, int w, string n, string c, string b, string pn){
        SetDogInfo(o, a, w, n, c, b);
        puppy_name = pn;
    }
    void PrintPuppyInfo(){
        PrintDogInfo();
        cout << "Puppy Name: " << puppy_name << endl;
    }
    ~Puppy(){
        cout << "Puppy destructor called" << endl;
    }
};

int main(){
    Puppy pup;
    pup.SetPuppyInfo("USA", 1, 10, "Buddy", "Brown", "Labrador", "Max");
    cout << "---------------------" << endl;
    pup.PrintPuppyInfo();
    pup.setPrice("admin123", 500);
    pup.getPrice("admin123");
    cout << "---------------------" << endl;
    return 0;
}