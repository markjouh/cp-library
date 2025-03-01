#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug>
#else
#define dbg(...)
#endif

using namespace std;
 
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
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pi>;
using vpl = vector<pl>;
 
template <class T>
bool ckmin(T &a, const T b) {
    return b < a ? a = b, 1 : 0; 
}
template <class T>
bool ckmax(T &a, const T b) {
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

template <class T, class = void>
struct is_range : false_type {};
template <class T>
struct is_range<T, void_t<decltype(begin(declval<T>())), decltype(end(declval<T>()))>> : true_type {};
template <class T>
using enable_if_cont = enable_if_t<!is_same<T, string>::value && is_range<T>::value, bool>;

template <class T, class U>
istream &operator>>(istream &is, pair<T, U> &p) {
    is >> p.fi >> p.se;
    return is;
}
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
    os << p.fi << ' ' << p.se;
    return os;
}
template <class T, enable_if_cont<T> = true>
istream &operator>>(istream &is, T &v) {
    for (auto &x : v) {
        is >> x;
    }
    return is;
}
template <class T, enable_if_cont<T> = true>
ostream &operator<<(ostream &os, const T &v) {
    for (int i = 0; i < sz(v); i++) {
        os << v[i];
        if (i != sz(v) - 1) {
            os << (is_range<typename T::value_type>::value ? '\n' : ' ');
        }
    }
    return os;
}

template <class ...T>
void re(T &...a) {
    (cin >> ... >> a);
}
template <class ...T>
void pr(const T &...a) {
    int p = 0;
    ((cout << a << (++p == sizeof...(T) ? '\n' : ' ')), ...);
}
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int INF = 1e9;
const ll INFL = 1e18;

void solve() {
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}