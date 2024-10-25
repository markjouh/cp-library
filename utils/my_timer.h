#ifndef MY_TIMER_H
#define MY_TIMER_H

#include <cassert>
#include <chrono>
#include <climits>
#include <iostream>
#include <map>
#include <unistd.h>
#include <thread>

#include "my_random.h"

namespace timer {

using namespace std;
using namespace chrono;

time_point<high_resolution_clock> timer;

void start() {
    timer = high_resolution_clock::now();
}

long long get_ns() {
    return duration_cast<nanoseconds>(high_resolution_clock::now() - timer).count();
}
long long get_ms() {
    return duration_cast<milliseconds>(high_resolution_clock::now() - timer).count();
}

void sleep_ns(long long ns) {
    this_thread::sleep_for(chrono::nanoseconds(ns));
}
void sleep_ms(long long ms) {
    this_thread::sleep_for(chrono::milliseconds(ms));
}

};

#endif // MY_TIMER_H