#pragma once

#include <unistd.h>

chrono::time_point<chrono::high_resolution_clock> timer;

void start_timer() {
    timer = std::chrono::high_resolution_clock::now();
}

long long elapsed() {
    return (chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - timer)).count();
}