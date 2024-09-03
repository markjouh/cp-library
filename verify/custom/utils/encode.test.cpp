#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../boilerplate.hpp"
#include "../../../utils/random.hpp"
#include "../../../utils/encode.hpp"

const int TESTS = 1000;

int main() {
  rep(i, TESTS) {
    array<int, 2500> arr;
    rep(j, 2500) {
      arr[j] = randint(1, inf<>);
    }
    auto enc = encode<decltype(arr), 5>(arr);
    auto dec = decode<decltype(arr), 5>(enc);
    assert(arr == dec);
  }

  rep(i, TESTS) {
    array<array<int, 50>, 50> arr;
    rep(j, 50) {
      rep(k, 50) {
        arr[j][k] = randint(1, inf<>);
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