#include<iostream>
using namespace std;
class Person{
    protected:
    string name;
    int age;
    public:
    Person(){
        name = "Unknown";
        age = 0;
        cout<<"Person default constructor called"<<endl;
    }
    void SetDetails(string n, int a){
        name = n;
        age = a;
    }
    void PrintDetails(){
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
    }
    ~Person(){
        cout<<"Person destructor called"<<endl;
    }
};
class Coder: virtual public Person{
    protected:
    bool vibe_coding;
    public:
    void code(){
        cout<<"Coding..."<<endl;
    }
    Coder(){
        cout<<"Coder default constructor called"<<endl;
    }
    ~Coder(){
        cout<<"Coder destructor called"<<endl;
    }
};
class DevOpsEngineer: virtual public Person{
    protected:
    bool vibe_devops;
    public:
    void deploy(){
        cout<<"Deploying..."<<endl;
    }
    DevOpsEngineer(){
        vibe_devops = true;
        cout<<"DevOpsEngineer default constructor called"<<endl;
    }
    ~DevOpsEngineer(){
        cout<<"DevOpsEngineer destructor called"<<endl;
    }
};
class FullStackDeveloper: virtual public Person{
    protected:
    bool vibe_fullstack;
    public:
    FullStackDeveloper(){
        cout<<"FullStackDeveloper default constructor called"<<endl;
    }
    void work(){
        cout<<"FullStackDeveloper working..."<<endl;
    }
    ~FullStackDeveloper(){
        cout<<"FullStackDeveloper destructor called"<<endl;
    }
};
class SoftwareEngineer: public FullStackDeveloper, public DevOpsEngineer, public Coder{
    public:
    void setVibes(){
        vibe_coding = true;
        vibe_devops = true;
        vibe_fullstack = true;
    }
    SoftwareEngineer(){
        cout<<"SoftwareEngineer default constructor called"<<endl;
    }
    void showVibes(){
        cout<<"Vibe Coding: "<<vibe_coding<<endl;
        cout<<"Vibe DevOps: "<<vibe_devops<<endl;
        cout<<"Vibe FullStack: "<<vibe_fullstack<<endl;
    }
    ~SoftwareEngineer(){
        cout<<"SoftwareEngineer destructor called"<<endl;
    }
};
int main(){
    SoftwareEngineer se;
    se.SetDetails("Bob", 30);
    se.PrintDetails();
    cout<<"---------------------"<<endl;
    se.setVibes();
    cout<<"---------------------"<<endl;
    se.showVibes();
    cout<<"---------------------"<<endl;
    se.work();
    cout<<"---------------------"<<endl;
    se.deploy();
    cout<<"---------------------"<<endl;
    se.code();
    cout<<"---------------------"<<endl;
    return 0;
}