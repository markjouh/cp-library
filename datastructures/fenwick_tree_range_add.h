template<class T> struct FT {
    int n;
    vec<T> ft;

    FT(int x) : n(x), ft(n + 1) {}

    FT(vec<T> &a) : n(sz(a)), ft(n + 1) {
        rep(i, 1, n + 1) {
            ft[i] += a[i - 1];
            if (i + (i & -i) <= n) {
                ft[i + (i & -i)] += ft[i];
            }
        }
    }

    void add(int r, T v) {
        for (r++; r > 0; r -= r & -r) {
            ft[r] += v;
        }
    }

    void add(int l, int r, T v) {
        upd(r, v);
        upd(l - 1, T(0) - T(v));
    }

    T query(int p) {
        T res = 0;
        for (p++; p <= n; p += p & -p) {
            res += ft[p];
        }
        return res;
    }
};
