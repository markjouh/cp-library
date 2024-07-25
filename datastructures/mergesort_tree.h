struct MergeTree {
    int n;
    vec<oset<int>> mt;

    MergeTree(int x) : n(x), mt(n + 1) {}

    void add(int p, int v) {
        for (p++; p <= n; p += p & (-p)) {
            mt[p].ins(v);
        }
    }

    void rem(int p, int v) {
        for (p++; p <= n; p += p & (-p)) {
            mt[p].era(v);
        }
    }

    int query(int r, int v) {
        int res = 0;
        while (r) {
            res += mt[r].ook(v);
            r -= r & (-r);
        }
        return res;
    }

    int query(int l, int r, int v) {
        return query(r, v) - query(l, v);
    }
};
