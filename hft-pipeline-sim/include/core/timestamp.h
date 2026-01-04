// This ensures the header is included only once per translation unit, avoiding redefinition errors.
#pragma once 
// Including the chrono library for time-related functions and types.
#include<chrono>
// Including the cstdint library for fixed-width integer types.
#include<cstdint>
using namespace std;
using namespace std::chrono;
// Function to get the current timestamp in nanoseconds using steady_clock for high-resolution timing.
inline uint64_t now_ns(){
    return chrono::duration_cast<chrono::nanoseconds>(
        chrono::steady_clock::now().time_since_epoch()
    ).count();
}