#pragma once
#include<cstdint>

struct MarketTick{
    int price;
    int quantity;
    bool is_buy; // true for buy, false for sell
    uint64_t timestamp_ns; // timestamp in nanoseconds
};