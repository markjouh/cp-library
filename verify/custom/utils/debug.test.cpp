#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../boilerplate.hpp"
#include "../../../utils/random.hpp"
#include "../../../utils/debug.hpp"

// Just some random stuff, make sure
// the output looks right

int main() {
  const int n = randint(100);
  vec<int> p = randvec<int>(n);
  dbg(p);

  map<int, vector<int>> mp;
  for (int i = 0; i < 100; i++) {
    mp[randint()] = randvec<int>(100);
  }
  dbg(mp);

  array<double, 100> arr = randarr<double, 100>();
  dbg(arr);

  int a, b;
  cin >> a >> b;
  cout << a + b << '\n';
}