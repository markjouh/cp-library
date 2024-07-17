struct RollbackDSU {
    vi a;
    vpi hist;

    RollbackDSU(int n) : a(n, -1) {}

    int find(int x) {
        return a[x] < 0 ? x : find(a[x]);
    }

    int size(int x) {
        return -a[find(x)];
    }

    void undo() {
        rep(i, 2) {
            auto [x, v] = hist.back();
            hist.pop_back();
            a[x] = v;
        }
    }

    bool join(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return 0;
        }
        if (a[x] > a[y]) {
            swap(x, y);
        }
        hist.eb(x, a[x]);
        hist.eb(y, a[y]);
        a[x] += a[y];
        a[y] = x;
        return 1;
    }
};
