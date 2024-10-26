template <class T, auto op, auto id>
struct SegtreeRU {
    int n;
    vector<T> st;

    SegtreeRU(int n_) : n(n_), st(2 * n, id()) {}

    void update(int l, int r, T v) {
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                ckmax(st[l++], v);
            }
            if (r & 1) {
                ckmax(st[--r], v);
            }
        }
    }

    int get(int p) {
        T res = id();
        for (p += n; p > 0; p >>= 1) {
            ckmax(res, st[p]);
        }
        return res;
    }
};