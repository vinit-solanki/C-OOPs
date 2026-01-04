#pragma once
#include "../core/ringbuffer.h"
#include "../market/market_tick.h"
#include "../market/order_book.h"
#include "../strategy/strategy.h"
#include "../risk/risk_manager.h"
#include "../execution/order_sender.h"
#include "../core/timestamp.h"

template <int FEED_SIZE>
class TradingPipeline{
    private:
    RingBuffer<MarketTick, FEED_SIZE> &feed;
    OrderBook order_book;
    Strategy strategy;
    RiskManager risk_manager;
    OrderSender order_sender;
    int ticks_processed = 0;
    public:
    explicit TradingPipeline(RingBuffer<MarketTick, FEED_SIZE> &feed)
        : feed(feed), strategy(2), risk_manager(100) {
        std::cout<<"[TradingPipeline] Component initialization:"<<std::endl;
        std::cout<<"[TradingPipeline] - Feed Buffer Size: "<<FEED_SIZE<<std::endl;
        std::cout<<"[TradingPipeline] - OrderBook: Ready"<<std::endl;
    }
    void run(){
        std::cout<<"[PIPELINE] Starting main processing loop...\n"<<std::endl;
        
        MarketTick tick;
        while (feed.pop(tick)){
            ticks_processed++;
            std::cout<<"\n"<<std::string(80, '-')<<std::endl;
            std::cout<<"  PROCESSING TICK #"<<ticks_processed<<std::endl;
            std::cout<<std::string(80, '-')<<std::endl;
            
            // Step 1: Update Order Book
            order_book.on_tick(tick);
            
            // Step 2: Strategy Evaluation
            if(strategy.evaluate(order_book)){
                int order_quantity = 10;
                
                // Step 3: Risk Check
                if(risk_manager.allow_order(order_quantity)){
                    // Step 4: Order Execution
                    order_sender.send_buy(tick.price, order_quantity, tick.timestamp_ns);
                    risk_manager.on_order_filled(order_quantity);
                } else {
                    std::cout<<"    [Pipeline]  [!] Order BLOCKED by risk manager"<<std::endl;
                }
            } else {
                std::cout<<"    [Pipeline]  [X] No trading signal - standing by"<<std::endl;
            }
        }
        
        std::cout<<"\n"<<std::string(80, '=')<<std::endl;
        std::cout<<"[PIPELINE] Processing Summary:"<<std::endl;
        std::cout<<"  - Total Ticks Processed: "<<ticks_processed<<std::endl;
        std::cout<<std::string(80, '=')<<"\n"<<std::endl;
    }
};