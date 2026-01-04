#include "../include/core/ringbuffer.h"
#include "../include/market/market_tick.h"
#include "../include/pipeline/pipeline.h"
#include "../include/core/timestamp.h"
#include <iostream>
#include <iomanip>
using namespace std;

void print_header(){
    cout<<"\n"<<string(80, '=')<<endl;
    cout<<"   HIGH-FREQUENCY TRADING PIPELINE SIMULATOR"<<endl;
    cout<<"   Real-time Market Data Processing & Order Execution"<<endl;
    cout<<string(80, '=')<<"\n"<<endl;
}

void print_section(const string& title){
    cout<<"\n"<<string(80, '-')<<endl;
    cout<<"  "<<title<<endl;
    cout<<string(80, '-')<<endl;
}

void print_tick(int num, const string& type, int price, int qty, uint64_t ts){
    cout<<"    [FEED] Tick #"<<setw(2)<<num<<" | "
        <<"Type: "<<setw(4)<<left<<type<<right
        <<" | Price: "<<setw(4)<<price
        <<" | Qty: "<<setw(3)<<qty
        <<" | Timestamp: "<<ts<<endl;
}

int main(){
    print_header();
    
    print_section("PHASE 1: SYSTEM INITIALIZATION");
    cout<<"[INIT] Creating Ring Buffer (Size: 1024)..."<<endl;
    RingBuffer<MarketTick, 1024> feed;
    cout<<"[INIT] Ring Buffer created successfully"<<endl;
    
    print_section("PHASE 2: MARKET DATA INGESTION");
    cout<<"[DATA] Preparing market tick data..."<<endl;
    
    MarketTick ticks[] = {
        {100, 10, true, now_ns()},
        {102, 15, false, now_ns()},
        {101, 20, true, now_ns()},
        {99, 5, false, now_ns()},
        {98, 25, false, now_ns()},
        {103, 30, true, now_ns()}
    };

    cout<<"[DATA] Pushing "<<(sizeof(ticks)/sizeof(ticks[0]))<<" market ticks to feed...\n"<<endl;
    for(int i = 0; i < sizeof(ticks)/sizeof(ticks[0]); i++){
        const auto& tick = ticks[i];
        print_tick(i+1, tick.is_buy ? "BUY" : "SELL", tick.price, tick.quantity, tick.timestamp_ns);
        feed.push(tick);
    }
    
    print_section("PHASE 3: TRADING PIPELINE INITIALIZATION");
    cout<<"[PIPELINE] Initializing trading components..."<<endl;
    TradingPipeline<1024> pipeline(feed);
    cout<<"[PIPELINE] All components initialized successfully\n"<<endl;
    
    print_section("PHASE 4: PIPELINE EXECUTION");
    cout<<"[PIPELINE] Starting market data processing...\n"<<endl;
    pipeline.run();
    
    print_section("PHASE 5: EXECUTION COMPLETE");
    cout<<"[SYSTEM] Pipeline execution completed successfully"<<endl;
    cout<<"[SYSTEM] All market ticks processed\n"<<endl;
    cout<<string(80, '=')<<"\n"<<endl;
    
    return 0;
}