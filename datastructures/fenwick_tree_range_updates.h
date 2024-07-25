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

    void upd(int r, int v) {
        for (r++; r > 0; r -= r & -r) {
            ft[r] += v;
        }
    }

    void upd(int l, int r, int v) {
        upd(r, v);
        upd(l - 1, -v);
    }

    int query(int p) {
        int res = 0;
        for (p++; p <= n; p += p & -p) {
            res += ft[p];
        }
        return res;
    }
};
