struct RMQ {
    int n;
    vec<vi> rmq;

    RMQ(vi &a) : n(sz(a)), rmq(__lg(n) + 1) {
        rmq[0] = a;
        for (int i = 1; i <= __lg(n); i++) {
            rmq[i].resize(n - (1 << i) + 1);
            for (int j = 0; j + (1 << i) <= n; j++) {
                rmq[i][j] = min(rmq[i - 1][j], rmq[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    int query(int l, int r) {
        int i = __lg(r - l);
        return min(rmq[i][l], rmq[i][r - (1 << i)]);
    }
};
