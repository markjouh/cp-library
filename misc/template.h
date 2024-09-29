#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include <utils>
#else
#define dbg(...)
#endif

#define all(x) begin(x), end(x)
#define sz(x) int(size(x))

using ll = long long;
using ld = long double;

template <class T>
bool ckmin(T &a, T b) {
    return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T &a, T b) {
    return b > a ? a = b, 1 : 0;
}