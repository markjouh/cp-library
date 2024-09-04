#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../boilerplate.hpp"
#include "../../../utils/random.hpp"
#include "../../../utils/debug.hpp"

// Just some random stuff, make sure
// the output looks right

int main() {
  const int n = rnd<>(0, 100);
  vec<int> p = rnd_vec<>(n, 1, 100);
  dbg(p);

  map<int, vector<int>> mp;
  for (int i = 0; i < 100; i++) {
    mp[rnd<>(1, 100)] = rnd_vec(100, 1, 100);
  }
  dbg(mp);

  array<double, 100> arr;
  for (int i = 0; i < 100; i++) {
    arr[i] = rnd<double>(0, 1);
  }
  dbg(arr);

  int a, b;
  cin >> a >> b;
  cout << a + b << '\n';
}