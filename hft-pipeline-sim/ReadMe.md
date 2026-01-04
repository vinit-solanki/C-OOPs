# HFT Trading Pipeline Simulation (C++)

This repository contains a low-latency C++ simulation of a typical
high-frequency trading execution pipeline.

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