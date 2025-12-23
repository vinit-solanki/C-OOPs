#include<iostream>
using namespace std;

class BankAccount {
    private:
        double balance;
    public:
    BankAccount(int initialBalance){
        if(initialBalance >=0){
            balance = initialBalance;
        } else{
            balance = 0;
        }
    }
    void deposit(double amount){
        if(amount > 0){
            balance += amount;
        }
    }
    bool withdraw(double amount){
        if(amount > 0 && amount <= balance){
            balance -= amount;
            return true;
        }
        return false;
    }
    double getBalance() {
        return balance;
    }
};

int main(){
    BankAccount* acc1 = new BankAccount(1000);
    acc1->deposit(500);
    if(acc1->withdraw(200)){
        cout << "Withdrawal successful!" << endl;
    } else {
        cout << "Insufficient funds!" << endl;
    }
    cout << "Current Balance: Rs." << acc1->getBalance() << endl;
}