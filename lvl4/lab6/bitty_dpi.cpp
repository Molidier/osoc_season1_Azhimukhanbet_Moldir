#include <iostream>

extern "C" void notify_counter_nine() {
    std::cout << "Counter reached 9!" << std::endl;
}