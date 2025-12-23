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
    // Default Constructor
    Strategy(){}

    // Non-Parameterized Constructor
    Strategy(){
        order_qty = 0;
        strategy_id = 0;
        cout<<"Default Strategy object created with Order Quantity: "<<order_qty<<" and Strategy ID: "<<strategy_id<<endl;
    }
    
    // Parametrized-Constructor to initialize order_qty and strategy_id
    Strategy(int qty, int id){
        order_qty = qty;
        SetStrategyID(id);
        cout<<"Strategy object created with Order Quantity: "<<order_qty<<" and Strategy ID: "<<id<<endl;
    }
    
    void PrintOrderQty(){
        cout<<"Order Quantity: "<<order_qty<<endl;
    }
};
int main(){
    Strategy defaultStrat; // Calls Default Constructor
    Strategy strat1(100, 1);
    Strategy strat2(200, 2);
    strat1.PrintOrderQty();
    strat2.PrintOrderQty();
    return 0;
}