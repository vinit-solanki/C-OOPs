#include<iostream> 
#include<exception>
#include<string>
using namespace std;

class InvalidRuntimeError: public runtime_error{
    public:
    InvalidRuntimeError(const string &errMsg): runtime_error(errMsg){}
};
class Customer{
    string name;
    int balance, acc_num;
    public:
    Customer(string name, int balance, int acc_num){
        this->name = name;
        this->balance = balance;
        this->acc_num = acc_num;
    }
    void deposit(int amt){
        if(amt<=0){
            throw InvalidRuntimeError("Deposit must be greater than zero");
        }
        balance += amt;
        cout<<"Amount deposited successfully. New balance: "<<balance<<endl;
    }
    void withdraw(int amt){
        if(amt<=0){
            throw InvalidRuntimeError("Withdrawal amount must be greater than zero");
        } else if(amt>balance){
            throw InvalidRuntimeError("Insufficient balance for withdrawal!");
        } else{
            balance -= amt;
            cout<<"Amount withdrawn successfully. New balance: "<<balance<<endl;
        }
    }
    void display(){
        cout<<"Customer Name: "<<name<<endl;
        cout<<"Account Number: "<<acc_num<<endl;
        cout<<"Balance: "<<balance<<endl;
    }
};

int main(){
    Customer c1("Alice", 5000, 123456);
    c1.display();
    cout<<"-------------------------"<<endl;
    try{
        c1.deposit(1500);
    } catch(const InvalidRuntimeError &e){
        cout<<"Runtime Error: "<<e.what()<<endl;
    } catch(const char *e){
        cout<<"Caught an exception: "<<e<<endl;
    } catch(...){
        cout<<"An unknown error occurred during transaction."<<endl;
    }
    cout<<"--------------------------"<<endl;
    try{
        c1.withdraw(7000);
    } catch(const InvalidRuntimeError &e){
        cout<<"Runtime Error: "<<e.what()<<endl;
    } catch(const char *e){
        cout<<"Caught an exception: "<<e<<endl;
    } catch(...){
        cout<<"An unknown error occurred during transaction."<<endl;
    }
    cout<<"--------------------------"<<endl;
    c1.deposit(500);
    cout<<"Program continues after exception handling."<<endl;
    return 0;
}