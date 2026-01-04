#pragma once
#include <iostream>
/*
a template is a language feature that allows you to write generic, type-independent code. 
Instead of writing the same logic separately for int, float, double, or user-defined types, 
you write the logic once, and the compiler generates the appropriate type-specific code at compile time.
*/
template<typename T, int SIZE>
class RingBuffer {
    public:
    bool push(const T& item) {
        int next = (head + 1) % SIZE;
        if(next == tail){
            return false; // Buffer is full
        }
        buffer[head] = item;
        head = next;
        items_pushed++;
        return true;
    }
    bool pop(T& item){
        if(tail == head){
            return false; // Buffer is empty
        }
        item = buffer[tail];
        tail = (tail + 1) % SIZE;
        items_popped++;
        return true;
    }
    int get_size() const {
        return (head >= tail) ? (head - tail) : (SIZE - tail + head);
    }
    int get_items_pushed() const { return items_pushed; }
    int get_items_popped() const { return items_popped; }
    private:
    T buffer[SIZE];
    int head = 0;
    int tail = 0;
    int items_pushed = 0;
    int items_popped = 0;
};
