#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include <utils>
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

#define all(x) begin(x), end(x)
#define sz(x) int(size(x))

#define pb push_back
#define eb emplace_back
#define fi first
#define se second

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

template <class T> using vec = vector<T>;
using vb = vec<bool>;
using vi = vec<int>; 
using vl = vec<ll>;
using vd = vec<ld>;
using vs = vec<string>;
using vpi = vec<pi>;
using vpl = vec<pl>;

template <class T, size_t N> using arr = array<T, N>;
template <size_t N> using ai = array<int, N>;
template <size_t N> using al = array<ll, N>;

template <class T>
bool ckmin(T &a, T b) {
    return b < a ? a = b, 1 : 0; 
}
template <class T>
bool ckmax(T &a, T b) {
    return b > a ? a = b, 1 : 0;
}

template <class T, class U>
T bsmin(T lo, T hi, U f) {
    assert(lo <= hi);
    hi++;
    for (T i = T(1) << __lg(hi - lo); i > 0; i >>= 1) {
        hi -= (hi - i >= lo && f(hi - i)) * i;
    }
    return hi;
}
template <class T, class U>
T bsmax(T lo, T hi, U f) {
    assert(lo <= hi);
    lo--;
    for (T i = T(1) << __lg(hi - lo); i > 0; i >>= 1) {
        lo += (lo + i <= hi && f(lo + i)) * i;
    }
    return lo;
}

const int INF = 1e9;
const ll INFL = 1e18;

// void solve() {
// }

// int32_t main() {
//     cin.tie(0)->sync_with_stdio(0);
//     cin.exceptions(cin.failbit);

//     int t = 1;
//     // cin >> t;
//     while (t--) {
//         solve();
//     }

//     return 0;
// }