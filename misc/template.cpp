#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include <utils>
#else
#define dbg(...)
#endif

#define all(x) begin(x), end(x)
#define sz(x) int(size(x))

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

template <class T>
bool ckmin(T &a, const T &b) {
  return b < a ? a = b, 1 : 0;
}

template <class T>
bool ckmax(T &a, const T &b) {
  return b > a ? a = b, 1 : 0;
}

void solve() {
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}