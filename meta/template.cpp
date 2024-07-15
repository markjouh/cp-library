using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
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

template<class T> using vec = vector<T>;
template<class T, size_t N> using arr = array<T, N>;

using ll = long long;
using ld = long double;
using i128 = __int128_t;

using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vb = vec<bool>;
using vi = vec<int>; 
using vl = vec<ll>;
using vd = vec<ld>;
using vs = vec<string>;
using vpi = vec<pi>;
using vpl = vec<pl>;

template<class T> bool ckmin(T &a, const T b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T b) { return b > a ? a = b, 1 : 0; }

const int inf = INT_MAX / 2;
const ll infl = LLONG_MAX / 2;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::badbit | ios::failbit);
}

/* READ THE PROBLEM STATEMENT CAREFULLY
 * PAY ATTENTION TO THE SAMPLES
 * It's probably not as complicated as you think
 * Don't get stuck on one idea for too long
 * Print output tables, try random stuff
 */
