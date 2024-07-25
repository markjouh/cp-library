struct FT {
    int n;
    vi ft;

    FT(int x) : n(x), ft(n + 1) {}

    FT(vi &a) : n(sz(a)), ft(n + 1) {
        rep(i, 1, n + 1) {
            ft[i] += a[i - 1];
            if (i + (i & -i) <= n) {
                ft[i + (i & -i)] += ft[i];
            }
        }
    }

    int query(int r) {
        int res = 0;
        for (r++; r > 0; r -= r & -r) {
            res += ft[r];
        }
        return res;
    }

    int query(int l, int r) {
        return query(r) - query(l - 1);
    }

    void upd(int p, int v) {
        for (p++; p <= n; p += p & -p) {
            ft[p] += v;
        }
    }
};
