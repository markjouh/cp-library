struct RMQ {
    int n, lg;
    vec<vi> rmq;

    RMQ(vi &a) : n(sz(a)), lg(__lg(n) + 1), rmq(lg) {
        rmq[0] = a;
        rep(i, 1, lg) {
            rmq[i].resize(n - (1 << i) + 1);
            rep(j, sz(rmq[i])) {
                rmq[i][j] = min(rmq[i - 1][j], rmq[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    int query(int l, int r) {
        int i = __lg(++r - l);
        return min(rmq[i][l], rmq[i][r - (1 << i)]);
    }
};
