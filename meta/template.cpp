#include <bits/stdc++.h>
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

#define bg(x) begin(x)
#define ed(x) end(x)
#define all(x) bg(x), ed(x)
#define rall(x) rbegin(x), rend(x)

#define ft(x) (x).front()
#define bk(x) (x).back()
#define sz(x) int(size(x))

#define pf push_front
#define pb push_back
#define eb emplace_back
#define pft pop_front
#define pbk pop_back
#define ins insert
#define era erase
#define fi first
#define se second

template<class T> using vec = vector<T>;
template<class T, size_t N> using arr = array<T, N>;

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

template<class T> bool ckmin(T &a, T b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, T b) { return b > a ? a = b, 1 : 0; }

const int inf = INT_MAX / 2;
const ll infl = LLONG_MAX / 2;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::badbit | ios::failbit);
}

/* DON'T MISREAD THE PROBLEM
 * It's probably not as complicated as you think
 * Don't get stuck on one idea for too long
 */
