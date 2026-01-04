#pragma once
#include <iostream>
class RiskManager{
    int position_limit=0;
    int max_position;
    mutable int checks_performed = 0;
    mutable int orders_approved = 0;
    mutable int orders_rejected = 0;
    public:
    explicit RiskManager(int max_position){
        this->max_position = max_position;
        std::cout<<"[RiskManager] Initialized with max_position = "<<max_position<<std::endl;
    }
    bool allow_order(int quantity) const{
        checks_performed++;
        bool allowed = (position_limit + quantity <= max_position);
        
        std::cout<<"    [RiskMgr]   Check #"<<std::setw(2)<<checks_performed
                 <<" | Order: "<<std::setw(3)<<quantity
                 <<" | Position: "<<std::setw(3)<<position_limit<<"/"<<std::setw(3)<<max_position
                 <<" | Result: "<<(allowed ? "[OK] APPROVED" : "[XX] REJECTED")<<std::endl;
        
        if(allowed){
            orders_approved++;
        } else {
            orders_rejected++;
        }
        
        return allowed;
    }
    void on_order_filled(int quantity){
        position_limit += quantity;
        std::cout<<"    [RiskMgr]   >> FILL CONFIRM | Qty: "<<std::setw(3)<<quantity
                 <<" | New Position: "<<std::setw(3)<<position_limit
                 <<" | Available: "<<std::setw(3)<<(max_position - position_limit)<<std::endl;
    }
    int get_position() const { return position_limit; }
    int get_checks() const { return checks_performed; }
    int get_approved() const { return orders_approved; }
    int get_rejected() const { return orders_rejected; }
};