#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>

#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif

using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) int(size(x))

using ll = long long;
using db = double;

template<class T> bool ckmin(T &a, const T b) {
    return b < a ? a = b, 1 : 0;
}

template<class T> bool ckmax(T &a, const T b) {
    return b > a ? a = b, 1 : 0;
}

#include "../../datastructures/fenwick_tree.hpp"

void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    fenwick_tree<ll> ft(a);
    while (q--) {
        bool t;
        int x, y;
        cin >> t >> x >> y;
        if (t) {
            cout << ft.sum(x, y - 1) << '\n';
        } else {
            ft.add(x, y);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}