#pragma once
#include "../market/order_book.h"
#include <iostream>

class Strategy{
    int max_spread;
    mutable int evaluations = 0;
    mutable int signals_generated = 0;
    public:
    explicit Strategy(int max_spread){
        this->max_spread = max_spread;
        std::cout<<"[Strategy] Initialized with max_spread = "<<max_spread<<std::endl;
    }
    bool evaluate(const OrderBook& book) const{
        evaluations++;
        std::cout<<"    [Strategy]  Eval #"<<std::setw(2)<<evaluations<<" | ";
        
        if(book.best_bid() == 0 || book.best_ask() == 0){
            std::cout<<"Status: SKIP (Insufficient market data)"<<std::endl;
            return false;
        }
        
        int current_spread = book.spread();
        bool signal = current_spread <= max_spread;
        
        if(signal){
            signals_generated++;
            std::cout<<"Status: [OK] SIGNAL | Spread: "<<std::setw(3)<<current_spread
                     <<" <= "<<max_spread<<" (Threshold)"<<std::endl;
        } else {
            std::cout<<"Status: [--] NO SIGNAL | Spread: "<<std::setw(3)<<current_spread
                     <<" > "<<max_spread<<" (Threshold)"<<std::endl;
        }
        
        return signal;
    }
    int get_evaluations() const { return evaluations; }
    int get_signals() const { return signals_generated; }
};