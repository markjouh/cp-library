#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../boilerplate.hpp"
#include "../../../utils/random.hpp"
#include "../../../utils/debug.hpp"

// Just some random stuff, make sure
// the output looks right

int main() {
  const int n = randint(100);
  vector<int> p(n);
  iota(all(p), 0);
  shuffle_array(p);
  dbg(p);

  map<int, vector<int>> mp;
  for (int i = 0; i < 100; i++) {
    shuffle_array(p);
    mp[randint(100)] = p;
  }
  dbg(mp);

  array<double, 100> arr;
  for (int i = 0; i < 100; i++) {
    arr[i] = randreal();
  }
  dbg(arr);

  int a, b;
  cin >> a >> b;
  cout << a + b << '\n';
}