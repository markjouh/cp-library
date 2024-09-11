#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include <unistd.h>

#include "../../boilerplate.hpp"

// Kind of pointless, but I'll write a test for
// completionism's sake...

const int TESTS = 10;

int main() {
  for (int i = 0; i < TESTS; i++) {
    const int randMs = randInt(50, 500);
    startTimer();
    usleep(randMs * 1000);
    assert(abs(elapsed() - randMs) < 10);
  }

  cerr << "Tests passed\n";

  int a, b;
  cin >> a >> b;
  cout << a + b << '\n';
}