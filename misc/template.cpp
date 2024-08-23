#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) int(size(x))

using ll = long long;
using ld = long double;

template<class T> bool ckmin(T &a, const T b) {
    return b < a ? a = b, 1 : 0;
}

template<class T> bool ckmax(T &a, const T b) {
    return b > a ? a = b, 1 : 0;
}

template<class T, class U> T bsmin(T lo, T hi, U f) {
    assert(lo <= hi);
    hi++;
    for (T i = T(1) << __lg(hi - lo); i > 0; i >>= 1) {
        hi -= (hi - i >= lo && f(hi - i)) * i;
    }
    return hi;
}

template<class T, class U> T bsmax(T lo, T hi, U f) {
    assert(lo <= hi);
    lo--;
    for (T i = T(1) << __lg(hi - lo); i > 0; i >>= 1) {
        lo += (lo + i <= hi && f(lo + i)) * i;
    }
    return lo;
}

void solve() {
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
