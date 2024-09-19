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
#define f first
#define s second

using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;

template <class T>
bool ckmin(T &a, const T &b) {
    return b < a ? a = b, 1 : 0;
}

template <class T>
bool ckmax(T &a, const T &b) {
    return b > a ? a = b, 1 : 0;
}

struct InitIO {
    InitIO() {
        cin.tie(0)->sync_with_stdio(0);
        cin.exceptions(cin.failbit);
        cout << setprecision(10) << fixed;
    }
} init_io;