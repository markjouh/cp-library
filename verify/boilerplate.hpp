#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define all(x) begin(x), end(x)
#define sz(x) int(size(x))
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template <class T>
bool ckmin(T &a, const T &b) {
  return b < a ? a = b, 1 : 0;
}

template <class T>
bool ckmax(T &a, const T &b) {
  return b > a ? a = b, 1 : 0;
}

const int INF = INT_MAX / 2;
const ll INFLL = LLONG_MAX / 2;

struct InitIO {
    InitIO() {
        cin.tie(0)->sync_with_stdio(0);
        cin.exceptions(cin.failbit);
        cout << setprecision(10) << fixed;
    }
} init_io;