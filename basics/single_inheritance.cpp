#include<iostream>
using namespace std;
class Human{
    protected:
    string name;
    string phone_number;
    public:
    char gender;
    Human(){
        name = "Unknown";
        phone_number = "000-000-0000";
        cout<<"Human default constructor called"<<endl;
    }
    void SetDetails(string n, string p){
        name = n;
        phone_number = p;
    }
    void PrintDetails(){
        cout<<"Name: "<<name<<endl;
        cout<<"Phone Number: "<<phone_number<<endl;
    }
    ~Human(){
        cout<<"Human destructor called"<<endl;
    }
};
class Student: public Human{
    public:
    int student_id;
    Student(){
        student_id = 0;
        cout<<"Student default constructor called"<<endl;
    }
    Student(int id, string name, string phone_number, char gender){
        student_id = id;
        SetDetails(name, phone_number);
        this->gender = gender;
    }
    void PrintStudentInfo(){
        cout<<"Student ID: "<<student_id<<endl;
        PrintDetails();
        cout<<"Gender: "<<gender<<endl;
    }
    ~Student(){
        cout<<"Student destructor called"<<endl;
    }
};
int main(){
    Student stu1;
    cout<<"---------------------"<<endl;
    stu1.PrintStudentInfo();
    Student stu2(101, "Alice", "123-456-7890", 'F');
    cout<<"---------------------"<<endl;
    stu2.PrintStudentInfo();
    cout<<"---------------------"<<endl;
    return 0;
}