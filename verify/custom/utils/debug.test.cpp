#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../boilerplate.hpp"
#include "../../../utils/debug.hpp"

// Just some random stuff, make sure
// the output looks right

int main() {
  const int n = randInt(100);
  vector<int> p = randVec<int>(n);
  dbg(p);

  map<int, vector<int>> mp;
  for (int i = 0; i < 100; i++) {
    mp[randInt()] = randVec<int>(100);
  }
  dbg(mp);

  array<double, 100> arr = randArr<double, 100>();
  dbg(arr);

  int a, b;
  cin >> a >> b;
  cout << a + b << '\n';
}