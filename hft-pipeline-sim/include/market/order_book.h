#pragma once
#include "market_tick.h"
#include <iostream>
#include <iomanip>
class OrderBook{
    int best_bid_price = 0;
    int best_ask_price = 0;
    int tick_count = 0;
    public:
    void on_tick(const MarketTick& tick){
        tick_count++;
        int old_bid = best_bid_price;
        int old_ask = best_ask_price;
        
        if(tick.is_buy){
            if(tick.price > best_bid_price){
                best_bid_price = tick.price;
            }
        } else{
            // handle sell tick
            if(best_ask_price == 0 || tick.price < best_ask_price){
                best_ask_price = tick.price;
            }
        }
        
        std::cout<<"    [OrderBook] Tick #"<<std::setw(2)<<tick_count
                 <<" | Type: "<<std::setw(4)<<std::left<<(tick.is_buy ? "BUY" : "SELL")<<std::right
                 <<" | Price: "<<std::setw(4)<<tick.price
                 <<" | Qty: "<<std::setw(3)<<tick.quantity<<std::endl;
        
        if(old_bid != best_bid_price || old_ask != best_ask_price){
            std::cout<<"    [OrderBook] >> BOOK UPDATE | Best Bid: "<<std::setw(4)<<best_bid_price
                     <<" | Best Ask: "<<std::setw(4)<<best_ask_price
                     <<" | Spread: "<<std::setw(4)<<spread()<<std::endl;
        }
    }
    int best_bid() const{
        return best_bid_price;
    }
    int best_ask() const{
        return best_ask_price;
    }
    int spread() const{
        return best_ask_price - best_bid_price;
    }
};