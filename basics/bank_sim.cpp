#include<iostream> 
using namespace std;
class Customer{
    double* balance;
    string address;
    string phone_number;
    public:
    int acc_no;
    string name;
    string acc_type;
    Customer(int acc_no, string name, string acc_type){
        this->acc_no = acc_no;
        this->name = name;
        this->acc_type = acc_type;
        balance = new double(0); // dynamically allocate memory for balance
        cout<<"Account created for "<<name<<", Account No: "<<acc_no<<", Type: "<<acc_type<<endl;
    }
     void deposit(double amount){
        if(amount > 0){
            *balance += amount;
            cout<<"Deposited: "<<amount<<", New Balance: "<<*balance<<endl;
        } else{
            cout<<"Deposit amount must be a valid positive number!"<<endl;
        }
    }
    bool withdraw(double amount){
        if(amount > 0 && amount <= *balance){
            *balance -= amount;
            cout<<"Withdrew: "<<amount<<", New Balance: "<<*balance<<endl;
            return true;
        } else{
            cout<<"Insufficient funds or invalid amount!"<<endl;
            return false;
        }
    }
    void displayBankInfo(){
        cout<<"Welcome to the No-Bank!"<<endl;
        cout<<"Account No. -"<<acc_no<<", Name - "<<name<<", Type - "<<acc_type<<endl;
    }
    static void displayBankPolicy(){
        cout<<"Bank Policy: No hidden charges, No minimum balance requirement."<<endl;
    }
    void setAddress(string addr){
        address = addr;
    }
    void setPhoneNumber(string phone){
        phone_number = phone;
    }
    void getBalance(){
        cout<<"Current Balance: "<<*balance<<endl;
    }
    void getAccountDetails(string password){
        if(password != "secure123"){
            cout<<"Access Denied: Incorrect Password"<<endl;
            return;
        }
        cout<<"Account Details:"<<endl;
        cout<<"Account No: "<<acc_no<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Account Type: "<<acc_type<<endl;
        cout<<"Balance: "<<*balance<<endl;
        cout<<"Address: "<<address<<endl;
        cout<<"Phone Number: "<<phone_number<<endl;
    }
};
class Bank{
    static int totalCustomers;
    public:
    static void showBankInfo(){
        cout<<"Welcome to the No-Bank! We value your trust."<<endl;
    }
    Bank(){
        totalCustomers++;
        cout<<"New customer added. Total customers: "<<totalCustomers<<endl;
    }
    Bank(string bankName, string branch, string ifscCode){
        totalCustomers++;
        cout<<"Bank Name: "<<bankName<<", Branch: "<<branch<<", IFSC Code: "<<ifscCode<<" Created!"<<endl;
    }
    static int getTotalCustomers(){
        return totalCustomers;
    }
};
int Bank::totalCustomers = 0; // initialize static member variable
int main(){
    Bank::showBankInfo();
    Bank bank1("No-Bank", "Main Branch", "NB0001");
    cout<<endl;
    Customer cust1(1001, "Alice", "Savings");
    cout<<endl;
    cust1.setAddress("456 Elm St, Townsville");
    cust1.setPhoneNumber("9876543210");
    cout<<endl;
    cust1.deposit(1500);
    cout<<endl;
    cust1.withdraw(500);
    cout<<endl;
    cust1.getBalance();
    cout<<endl;
    cust1.getAccountDetails("secure123"); // correct password
    Customer cust2(1002, "Bob", "Checking");
    cout<<endl;
    cust2.deposit(2000);
    cout<<endl;
    cust2.withdraw(2500); // insufficient funds
    cout<<endl;
    cust2.getBalance();
    cout<<endl;
    cust2.getAccountDetails("wrongpass"); // incorrect password
    cout<<endl;
    Bank::showBankInfo();
    cout<<endl;
    cout<<"Total Customers in Bank: "<<Bank::getTotalCustomers()<<endl;
    return 0;
}