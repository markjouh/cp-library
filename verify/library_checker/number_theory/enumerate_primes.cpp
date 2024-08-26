#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"

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

#include "../../../numeric/number_theory.hpp"

using namespace number_theory;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    sieve(n);
    cout << sz(primes) << ' ';
    vector<int> res;
    for (int i = b; i < sz(primes); i += a) {
        res.push_back(primes[i]);
    }
    cout << sz(res) << '\n';
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