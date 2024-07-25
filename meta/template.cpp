#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...)
#endif

#define arg4(a, b, c, d, ...) d

#define rep3(i, l, r) for (int i = int(l); i < int(r); i++)
#define rep2(i, n) rep3(i, 0, n)
#define rep(...) arg4(__VA_ARGS__, rep3, rep2) (__VA_ARGS__)

#define per3(i, l, r) for (int i = int(r) - 1; i >= int(l); i--)
#define per2(i, n) per3(i, 0, n)
#define per(...) arg4(__VA_ARGS__, per3, per2) (__VA_ARGS__)

#define bg(x) begin(x)
#define ed(x) end(x)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) int(size(x))
#define ft(x) (x).front()
#define bk(x) (x).back()

#define lgf(x) int(__lg(x))
#define lgc(x) (lgf(x) + (((x) & (x - 1)) != 0))
#define bit(x, i) (((x) >> (i)) & 1)

#define acc accumulate
#define mne min_element
#define mxe max_element
#define lb lower_bound
#define ub upper_bound
#define ook order_of_key
#define fbo find_by_order

#define pf push_front
#define pb push_back
#define eb emplace_back
#define pft pop_front
#define pbk pop_back
#define ins insert
#define era erase

#define fi first
#define se second

template<class T, size_t N> using arr = array<T, N>;
template<class T> using vec = vector<T>;
template<class T> using prq = priority_queue<T>;
template<class T> using prqg = priority_queue<T, vec<T>, greater<T>>;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

using ll = long long;
using ld = long double;
using i128 = __int128_t;
using str = string;

using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vb = vec<bool>;
using vi = vec<int>; 
using vl = vec<ll>;
using vd = vec<ld>;
using vs = vec<str>;
using vpi = vec<pi>;
using vpl = vec<pl>;

using vvi = vec<vi>;
using vvl = vec<vl>;
using vvpi = vec<vpi>;
using vvpl = vec<vpl>;

template<class T> int pct(T x) { return is_same_v<T, int> ? __builtin_popcount(x) : __builtin_popcountll(x); }
template<class T> bool ckmin(T &a, T b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, T b) { return b > a ? a = b, 1 : 0; }
template<class T> void remdup(vec<T> &a) { sort(all(a)); a.resize(unique(all(a)) - bg(a)); }

void set_io(str s = "") {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::badbit | ios::failbit);
    cout << setprecision(12) << fixed;
#ifndef LOCAL
    if (sz(s)) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
#endif
}

const int inf = INT_MAX / 2;
const ll infl = LLONG_MAX / 2;

void solve() {
}

int main() {
    set_io();
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
