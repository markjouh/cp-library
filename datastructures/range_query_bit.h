struct BIT {
    int n;
    vi bit;

    BIT(int x) : n(x), bit(n + 1) {}

    BIT(vi &a) : n(sz(a)), bit(n + 1) {
        rep(i, 1, n + 1) {
            bit[i] += bit[i - 1];
            if (i + (i & (-i)) <= n) {
                bit[i + (i & (-i))] += bit[i];
            }
        }
    }

    int query(int r) {
        int res = 0;
        while (r) {
            res += bit[r];
            r -= r & (-r);
        }
        return res;
    }

    int query(int l, int r) {
        return query(r) - query(l);
    }

    void update(int p, int v) {
        for (p++; p <= n; p += p & (-p)) {
            bit[p] += v;
        }
    }
};
