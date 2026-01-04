#include<iostream>
using namespace std;
class Customer{
    int id;
    string name;
    static int customerCount; // static member variable to keep track of number of customers
    static int total;
    public:
    Customer(int cid, string cname){
        id = cid;
        name = cname;
        customerCount++; // increment customer count whenever a new customer is created
    }
    void deposit(int amount){
        total += amount;
        cout<<"Deposited: "<<amount<<", Total Balance: "<<total<<endl;
    }
    static void displayTotal(){
        cout<<"Total Balance across all customers: "<<total<<endl;
    }
    static int getCustomerCount(){ // static member function to access static member variable
        return customerCount;
    }
    void displayCustomer(){
        cout<<"Customer ID: "<<id<<", Name: "<<name<<endl;
    }
};
int Customer::customerCount = 0; // initialize static member variable
int Customer::total = 0; // initialize static member variable
int main(){
    Customer cust1(1, "John Doe");
    Customer cust2(2, "Jane Smith");
    cust1.displayCustomer();
    cust2.displayCustomer();
    // static method can only access static member variables no other data members or methods
    cout<<"Total Customers: "<<Customer::getCustomerCount()<<endl;
    // cout<<Customer::customerCount<<endl; // Accessing static member variable directly using class name
    // this will cause a compilation error as customerCount is private
    cust1.deposit(100);
    cust2.deposit(200);
    Customer::displayTotal();
    cust1.displayTotal(); // static method can also be called using object
    cust2.displayTotal();
    return 0;
}