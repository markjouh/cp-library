#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../boilerplate.hpp"
#include "../../../utils/encode.hpp"

const int TESTS = 1000;

int main() {
  for (int i = 0; i < TESTS; i++) {
    array<int, 2500> arr;
    for (int j = 0; j < 2500; j++) {
      arr[j] = randInt(1e9);
    }
    auto enc = encode<decltype(arr), 5>(arr);
    auto dec = decode<decltype(arr), 5>(enc);
    assert(arr == dec);
  }

  for (int i = 0; i < TESTS; i++) {
    array<array<int, 50>, 50> arr;
    for (int j = 0; j < 50; j++) {
      for (int k = 0; k < 50; k++) {
        arr[j][k] = randInt(1e9);
      }
    }
    auto enc = encode<decltype(arr), 5>(arr);
    auto dec = decode<decltype(arr), 5>(enc);
    assert(arr == dec);
  }

  cerr << "Tests passed\n";

  int a, b;
  cin >> a >> b;
  cout << a + b << '\n';
}