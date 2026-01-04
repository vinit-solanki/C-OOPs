#pragma once
#include<iostream>
#include<iomanip>
#include "../core/timestamp.h"
using namespace std;
class OrderSender{
    mutable int orders_sent = 0;
    public:
    OrderSender(){
        std::cout<<"[OrderSender] Initialized and ready to execute orders"<<std::endl;
    }
    void send_buy(int price, int quantity, uint64_t decision_ts) const{
        orders_sent++;
        uint64_t send_ts = now_ns();
        uint64_t latency_ns = send_ts - decision_ts;
        double latency_us = latency_ns / 1000.0;
        
        std::cout<<"    +--- [ORDER EXECUTION #"<<orders_sent<<"] "<<std::string(28, '-')<<"+"<<std::endl;
        std::cout<<"    | Type:      BUY"<<std::string(41, ' ')<<"|"<<std::endl;
        std::cout<<"    | Price:     "<<price<<std::string(43, ' ')<<"|"<<std::endl;
        std::cout<<"    | Quantity:  "<<quantity<<std::string(43, ' ')<<"|"<<std::endl;
        std::cout<<"    | Latency:   "<<std::fixed<<std::setprecision(2)<<latency_us<<" us ("<<latency_ns<<" ns)";
        int padding = 56 - 13 - std::to_string((int)latency_us).length() - std::to_string(latency_ns).length() - 11;
        if(padding > 0) std::cout<<std::string(padding, ' ');
        std::cout<<"|"<<std::endl;
        std::cout<<"    +"<<std::string(56, '-')<<"+"<<std::endl;
    }
    int get_orders_sent() const { return orders_sent; }
};