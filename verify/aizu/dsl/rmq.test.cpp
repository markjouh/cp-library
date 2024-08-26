#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"

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

#include "../../../datastructures/segment_tree.hpp"

int op(int x, int y) {
    return x < y ? x : y;
}

int id() {
    return numeric_limits<int>::max();
}

void solve() {
    int n, q;
    cin >> n >> q;
    segment_tree<int, op, id> st(n);
    while (q--) {
        bool t;
        int x, y;
        cin >> t >> x >> y;
        if (t) {
            cout << st.query(x, y) << '\n';
        } else {
            st.set(x, y);
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