#include <bits/stdc++.h>

using namespace std;

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

template<class T, size_t N> using arr = array<T, N>;
template<class T> using vec = vector<T>;

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

template<class T> bool ckmin(T &a, T b) {
    return b < a ? a = b, 1 : 0;
}

template<class T> bool ckmax(T &a, T b) {
    return b > a ? a = b, 1 : 0;
}

template<class T, class U> T bsmin(T lo, T hi, U f) {
    assert(lo <= hi);
    for (T i = 1ll << __lg(++hi - lo); i; i >>= 1) {
        hi -= (hi - i >= lo && f(hi - i)) * i;
    }
    return hi;
}

template<class T, class U> T bsmax(T lo, T hi, U f) {
    assert(lo <= hi);
    for (T i = 1ll << __lg(hi - --lo); i; i >>= 1) {
        lo += (lo + i <= hi && f(lo + i)) * i;
    }
    return lo;
}

template<class T, class U> istream &operator>>(istream &is, pair<T, U> &p) {
    return is >> p.fi >> p.se;
}

template<class T, class U> ostream &operator<<(ostream &os, pair<T, U> &p) {
    return os << p.fi << ' ' << p.se;
}

template<class T> istream &operator>>(istream &is, vec<T> &v) {
    for (auto &x : v) {
        is >> x;
    }
    return is;
}

template<class T> ostream &operator<<(ostream &os, vec<T> &v) {
    bool first = true;
    for (auto &x : v) {
        if (!first) {
            cout << ' ';
        }
        cout << x;
        first = false;
    }
    return os;
}

template<class T, class... U> void re(T&& a, U&&... b) {
    cin >> forward<T>(a);
    (int[]) { (cin >> forward<U>(b), 0)... };
}

template<class T, class... U> void pr(T&& a, U&&... b) {
    cout << forward<T>(a);
    (int[]) { (cout << ' ' << forward<U>(b), 0)... };
    cout << '\n';
}

const int inf = INT_MAX / 2;
const ll infl = LLONG_MAX / 2;

void solve() {
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t = 1;
    // re(t);
    while (t--) {
        solve();
    }
}
