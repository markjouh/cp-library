struct FT {
    int n;
    vi bit;

    FT(int x) : n(x), bit(n + 1) {}

    FT(vi &a) : n(sz(a)), bit(n + 1) {
        rep(i, 1, n + 1) {
            bit[i] += bit[i - 1];
            if (i + (i & (-i)) <= n) {
                bit[i + (i & (-i))] += bit[i];
            }
        }
    }

    void update(int r, int v) {
        while (r) {
            bit[r] += v;
            r -= r & (-r);
        }
    }

    void update(int l, int r, int v) {
        update(r, v);
        update(l, -v);
    }

    int query(int p) {
        int res = 0;
        for (p++; p <= n; p += p & (-p)) {
            res += bit[p];
        }
        return res;
    }
};
