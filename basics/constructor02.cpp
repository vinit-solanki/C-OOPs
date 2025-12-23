#include<iostream>
using namespace std;
class Strategy{
    public:
    Strategy(double p, int v, string an, int aid){
        price = p;
        volume = v;
        account_name = an;
        account_id = aid;
    }
    void printMembers(const Strategy& obj){
        cout<<"Price: "<<obj.price<<", Volume: "<<obj.volume<<endl;
        cout<<"Account Name: "<<obj.account_name<<", Account ID: "<<obj.account_id<<endl;
    }

    private:
    double price;
    int volume;
    string account_name;
    int account_id;    
};
int main(){
    Strategy obj(100.5, 200, "John Doe", 12345);
    obj.printMembers(obj);
    delete &obj; // This line is incorrect; obj is not dynamically allocated
    return 0;
}