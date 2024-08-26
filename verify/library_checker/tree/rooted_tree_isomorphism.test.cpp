#define PROBLEM "https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification"

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

#include "../../../graphs/tree_isomorphism.hpp"

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        g[p].push_back(i);
    }
    tree_isomorphism iso;
    auto res = iso.gen(g);
    cout << sz(iso.hashes) << '\n';
    for (int x : res) {
        cout << x << ' ';
    }
    cout << '\n';
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