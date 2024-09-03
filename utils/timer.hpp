#pragma once

chrono::time_point<chrono::high_resolution_clock> timer;

void set_timer() {
  timer = std::chrono::high_resolution_clock::now();
}

ll elapsed() {
  return (chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - timer)).count();
}