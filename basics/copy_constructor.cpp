#include<iostream>
using namespace std;
class Strategy{
    private:
    int strategy_id;
    void SetStrategyID(int id){
        strategy_id = id;
    }
    public:
    int order_qty;

    // Parameterized Constructor to initialize order_qty and strategy_id
    Strategy(int qty, int id){
        order_qty = qty;
        SetStrategyID(id);
        cout<<"Strategy object created with Order Quantity: "<<order_qty<<" and Strategy ID: "<<id<<endl;
    }
    
    // Custom Copy Constructor
    Strategy(const Strategy& obj){
        order_qty = obj.order_qty;
        strategy_id = obj.strategy_id;
        cout<<"Copy Constructor called: Created a copy of Strategy object with Order Quantity: "<<order_qty<<" and Strategy ID: "<<strategy_id<<endl;
    }

    void PrintOrderQty(){
        cout<<"Order Quantity: "<<order_qty<<endl;
    }
};
int main(){
    // Creating an object using the parameterized constructor
    Strategy strat1(100, 1);

    // shallow copy constructor provided by the compiler
    // Using the copy constructor to create a new object as a copy of strat1
    Strategy strat2 = strat1; // Default Copy Constructor is called here

    // Displaying order quantities of both objects
    strat1.PrintOrderQty();
    strat2.PrintOrderQty();

    strat1.order_qty = 200; // Modifying strat1's order quantity
    cout<<"After modifying strat1's order quantity:"<<endl;
    strat1.PrintOrderQty();
    strat2.PrintOrderQty(); // strat2's order quantity remains unchanged

    cout<<"Custom Copy Constructor Demonstration:"<<endl;
    // Using the custom copy constructor to create a new object as a copy of strat1
    Strategy strat3(strat1); // Custom Copy Constructor is called here
    strat3.PrintOrderQty();
    
    return 0;
}