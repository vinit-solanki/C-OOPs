#include<iostream>
using namespace std;
class Student{
    string address;
    int phone_number;
    int* account_balance; // dynamically allocated member
    public:
    string name;
    int age;
    int roll_no;
    string grade;
    Student(){
        account_balance = new int(0); // allocate memory and initialize to 0
    }
    void PrintDetails(){
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Roll Number: "<<roll_no<<endl;
        cout<<"Grade: "<<grade<<endl;
    }
    void setAddress(string addr){
        address = addr;
    }
    void setPhoneNumber(int phone){
        phone_number = phone;
    }
    void setAddressAndPhone(string addr, int phone){
        address = addr;
        phone_number = phone;
    }
    void setAccountBalance(int amount){
        *account_balance = amount;
    }
    void getAccountBalance(){
        cout<<"Account Balance: "<<*account_balance<<endl;
    }
    void PrintAddressAndPhone(){
        cout<<"Address: "<<address<<endl;
        cout<<"Phone Number: "<<phone_number<<endl;
    }
    void printAllDetails(string password){
        if(password != "admin123"){
            cout<<"Access Denied: Incorrect Password"<<endl;
            return;
        }
        PrintDetails();
        PrintAddressAndPhone();
        getAccountBalance();
    }
    ~Student(){
        delete account_balance; // free dynamically allocated memory
    }
};
int main(){
    Student student1;
    student1.name = "Alice";
    student1.age = 20;
    student1.roll_no = 101;
    student1.grade = "A";
    student1.setAddress("123 Main St, Cityville");
    student1.setPhoneNumber(1234567890);
    student1.printAllDetails("admin123"); // correct password
    student1.printAllDetails("wrongpass"); // incorrect password
    student1.setAccountBalance(5000);
    student1.getAccountBalance();
    return 0;
}