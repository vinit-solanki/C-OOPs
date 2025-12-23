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
    void PrintOrderQty(){
        cout<<"Order Quantity: "<<order_qty<<endl;
    }
};
int main(){
    Strategy strat;
    strat.order_qty = 150;
    strat.PrintOrderQty();
    // The following line would cause a compilation error due to private access
    // strat.SetStrategyID(10); 
    return 0; 
}