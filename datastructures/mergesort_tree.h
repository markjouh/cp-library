struct MergeTree {
    int n;
    vec<oset<int>> mt;

    MergeTree(int x) : n(x), mt(n + 1) {}

    void add(int p, int v) {
        for (p++; p <= n; p += p & -p) {
            mt[p].ins(v);
        }
    }

    void rem(int p, int v) {
        for (p++; p <= n; p += p & -p) {
            mt[p].era(v);
        }
    }

    int query(int r, int v) {
        int res = 0;
        for (r++; r > 0; r -= r & -r) {
            res += mt[r].order_of_key(v);
        }
        return res;
    }

    int query(int l, int r, int v) {
        return query(r, v) - query(l - 1, v);
    }
};
