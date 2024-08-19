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

    T sum(int r) {
        T res = 0;
        for (r++; r > 0; r -= r & -r) {
            res += ft[r];
        }
        return res;
    }

    T sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int p, T v) {
        for (p++; p <= n; p += p & -p) {
            ft[p] += v;
        }
    }
};
