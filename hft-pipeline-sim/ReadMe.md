# HFT Trading Pipeline Simulation (C++)
This repository contains a low-latency C++ simulation of a typical high-frequency trading execution pipeline.
---
## Sample Input
```cpp
MarketTick ticks[] = {
    {100, 10, true, now_ns()},
    {102, 15, false, now_ns()},
    {101, 20, true, now_ns()},
    {99, 5, false, now_ns()},
    {98, 25, false, now_ns()},
    {103, 30, true, now_ns()}
};
```

## Sample Output

<details>
<summary>Console run (g++ build + execution)</summary>

```text
PS D:\Code-X\C++ OOPs\hft-pipeline-sim> g++ .\src\main.cpp -o main
PS D:\Code-X\C++ OOPs\hft-pipeline-sim> .\src\main.exe
================================================================================
HIGH-FREQUENCY TRADING PIPELINE SIMULATOR
Real-time Market Data Processing & Order Execution
================================================================================
--------------------------------------------------------------------------------
PHASE 1: SYSTEM INITIALIZATION
--------------------------------------------------------------------------------
[INIT] Creating Ring Buffer (Size: 1024)...
[INIT] Ring Buffer created successfully
--------------------------------------------------------------------------------
PHASE 2: MARKET DATA INGESTION
--------------------------------------------------------------------------------
[DATA] Preparing market tick data...
[DATA] Pushing 6 market ticks to feed...
[FEED] Tick # 1 | Type: BUY | Price: 100 | Qty: 10 | Timestamp: 1767702981664757000
[FEED] Tick # 2 | Type: SELL | Price: 102 | Qty: 15 | Timestamp: 1767702981664757000
[FEED] Tick # 3 | Type: BUY | Price: 101 | Qty: 20 | Timestamp: 1767702981664757000
[FEED] Tick # 4 | Type: SELL | Price: 99 | Qty: 5 | Timestamp: 1767702981664757000
[FEED] Tick # 5 | Type: SELL | Price: 98 | Qty: 25 | Timestamp: 1767702981664757000
[FEED] Tick # 6 | Type: BUY | Price: 103 | Qty: 30 | Timestamp: 1767702981664757000
--------------------------------------------------------------------------------
PHASE 3: TRADING PIPELINE INITIALIZATION
--------------------------------------------------------------------------------
[PIPELINE] Initializing trading components...
[Strategy] Initialized with max_spread = 2
[RiskManager] Initialized with max_position = 100
[OrderSender] Initialized and ready to execute orders
[TradingPipeline] Component initialization:
[TradingPipeline] - Feed Buffer Size: 1024
[TradingPipeline] - OrderBook: Ready
[PIPELINE] All components initialized successfully
--------------------------------------------------------------------------------
PHASE 4: PIPELINE EXECUTION
--------------------------------------------------------------------------------
[PIPELINE] Starting market data processing...
[PIPELINE] Starting main processing loop...
--------------------------------------------------------------------------------
PROCESSING TICK #1
--------------------------------------------------------------------------------
[OrderBook] Tick # 1 | Type: BUY | Price: 100 | Qty: 10
[OrderBook] >> BOOK UPDATE | Best Bid: 100 | Best Ask: 0 | Spread: -100
[Strategy] Eval # 1 | Status: SKIP (Insufficient market data)
[Pipeline] [X] No trading signal - standing by
--------------------------------------------------------------------------------
PROCESSING TICK #2
--------------------------------------------------------------------------------
[OrderBook] Tick # 2 | Type: SELL | Price: 102 | Qty: 15
[OrderBook] >> BOOK UPDATE | Best Bid: 100 | Best Ask: 102 | Spread: 2
[Strategy] Eval # 2 | Status: [OK] SIGNAL | Spread: 2 <= 2 (Threshold)
[RiskMgr] Check # 1 | Order: 10 | Position: 0/100 | Result: [OK] APPROVED
+--- [ORDER EXECUTION #1] ----------------------------+
| Type: BUY                                          |
| Price: 102                                         |
| Quantity: 10                                       |
| Latency: 37298.00 us (37298000 ns)                 |
+--------------------------------------------------------+
[RiskMgr] >> FILL CONFIRM | Qty: 10 | New Position: 10 | Available: 90
--------------------------------------------------------------------------------
PROCESSING TICK #3
--------------------------------------------------------------------------------
[OrderBook] Tick # 3 | Type: BUY | Price: 101 | Qty: 20
[OrderBook] >> BOOK UPDATE | Best Bid: 101 | Best Ask: 102 | Spread: 1
[Strategy] Eval # 3 | Status: [OK] SIGNAL | Spread: 1 <= 2 (Threshold)
[RiskMgr] Check # 2 | Order: 10 | Position: 10/100 | Result: [OK] APPROVED
+--- [ORDER EXECUTION #2] ----------------------------+
| Type: BUY                                          |
| Price: 101                                         |
| Quantity: 10                                       |
| Latency: 61201.00 us (61201000 ns)                 |
+--------------------------------------------------------+
[RiskMgr] >> FILL CONFIRM | Qty: 10 | New Position: 20 | Available: 80
--------------------------------------------------------------------------------
PROCESSING TICK #4
--------------------------------------------------------------------------------
[OrderBook] Tick # 4 | Type: SELL | Price: 99 | Qty: 5
[OrderBook] >> BOOK UPDATE | Best Bid: 101 | Best Ask: 99 | Spread: -2
[Strategy] Eval # 4 | Status: [OK] SIGNAL | Spread: -2 <= 2 (Threshold)
[RiskMgr] Check # 3 | Order: 10 | Position: 20/100 | Result: [OK] APPROVED
+--- [ORDER EXECUTION #3] ----------------------------+
| Type: BUY                                          |
| Price: 99                                          |
| Quantity: 10                                       |
| Latency: 93454.00 us (93454000 ns)                 |
+--------------------------------------------------------+
[RiskMgr] >> FILL CONFIRM | Qty: 10 | New Position: 30 | Available: 70
--------------------------------------------------------------------------------
PROCESSING TICK #5
--------------------------------------------------------------------------------
[OrderBook] Tick # 5 | Type: SELL | Price: 98 | Qty: 25
[OrderBook] >> BOOK UPDATE | Best Bid: 101 | Best Ask: 98 | Spread: -3
[Strategy] Eval # 5 | Status: [OK] SIGNAL | Spread: -3 <= 2 (Threshold)
[RiskMgr] Check # 4 | Order: 10 | Position: 30/100 | Result: [OK] APPROVED
+--- [ORDER EXECUTION #4] ----------------------------+
| Type: BUY                                          |
| Price: 98                                          |
| Quantity: 10                                       |
| Latency: 122080.00 us (122080000 ns)               |
+--------------------------------------------------------+
[RiskMgr] >> FILL CONFIRM | Qty: 10 | New Position: 40 | Available: 60
--------------------------------------------------------------------------------
PROCESSING TICK #6
--------------------------------------------------------------------------------
[OrderBook] Tick # 6 | Type: BUY | Price: 103 | Qty: 30
[OrderBook] >> BOOK UPDATE | Best Bid: 103 | Best Ask: 98 | Spread: -5
[Strategy] Eval # 6 | Status: [OK] SIGNAL | Spread: -5 <= 2 (Threshold)
[RiskMgr] Check # 5 | Order: 10 | Position: 40/100 | Result: [OK] APPROVED
+--- [ORDER EXECUTION #5] ----------------------------+
| Type: BUY                                          |
| Price: 103                                         |
| Quantity: 10                                       |
| Latency: 141728.00 us (141728000 ns)               |
+--------------------------------------------------------+
[RiskMgr] >> FILL CONFIRM | Qty: 10 | New Position: 50 | Available: 50
================================================================================
[PIPELINE] Processing Summary:
- Total Ticks Processed: 6
================================================================================
--------------------------------------------------------------------------------
PHASE 5: EXECUTION COMPLETE
--------------------------------------------------------------------------------
[SYSTEM] Pipeline execution completed successfully
[SYSTEM] All market ticks processed
================================================================================
```

</details>
---

## Pipeline
Market Data → Order Book → Strategy → Risk → Order Send

## Design Principles
- No heap allocation in hot path
- No virtual dispatch
- Deterministic control flow
- Data-oriented design
- Explicit latency measurement

## Purpose
This project focuses on **system architecture and execution flow**,
not on trading profitability or strategy complexity.

Inspired by real-world HFT infrastructure design.