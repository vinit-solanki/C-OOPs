#include<iostream>  
using namespace std;
class Strategy{
    private:
    // private members (if any) can be defined here
    int strategy_id;
    void SetStrategyID(int id){
        strategy_id = id;
    }
    public:
    int order_qty;
    int garbage_value; // uninitialized member
    void PrintOrderQty(){
        cout<<"Order Quantity: "<<order_qty<<endl;
    }
};

int main(){
    // automatic allocation / Stack allocation
    Strategy strat1, strat2;
    strat1.order_qty = 100;
    strat2.order_qty = 200;
    strat1.PrintOrderQty();
    strat2.PrintOrderQty(); 
    // no need to free memory for stack allocated objects

    // garbage value demonstration
    cout<<"Garbage Value of strat1: "<<strat1.garbage_value<<endl;

    // dynamic allocation / Heap allocation
    Strategy* strat3 = new Strategy();
    strat3->order_qty = 300;
    strat3->PrintOrderQty();
    // alternative syntax
    (*strat3).order_qty = 400; 
    (*strat3).PrintOrderQty();
    delete strat3; // free the allocated memory
    return 0;
}