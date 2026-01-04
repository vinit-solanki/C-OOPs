#include <iostream>
using namespace std;

static int counter = 0; // static global variable
static void incrementCounter() {
    counter++;
}

void counterFunction() {
    static int count = 0; // initialized only once
    count++;
    cout << "Count: " << count << endl;
}

int main() {
    counterFunction(); // Count: 1
    counterFunction(); // Count: 2
    counterFunction(); // Count: 3
    cout << "Initial static counter: " << counter << endl; // 0
    incrementCounter();
    incrementCounter();
    cout << "Static counter after increment: " << counter << endl; // 2
}
