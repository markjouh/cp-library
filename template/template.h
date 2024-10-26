#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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
 
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define sz(x) int(size(x))
 
#define acc accumulate
#define mne min_element
#define mxe max_element
#define lb lower_bound
#define ub upper_bound
 
#define pb push_back
#define eb emplace_back
#define pbk pop_back
#define ins insert
#define era erase
 
#define fi first
#define se second
 
template <class T, size_t N> using arr = array<T, N>;
template <class T> using vec = vector<T>;
template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
using ll = long long;
using ld = long double;
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

const int INF = INT_MAX / 2;
const ll INFL = LLONG_MAX / 2;

// void solve() {
// }

// int main() {
//     cin.tie(0)->sync_with_stdio(0);
//     cin.exceptions(cin.failbit);

//     int t = 1;
//     // cin >> t;
//     while (t--) {
//         solve();
//     }
// }