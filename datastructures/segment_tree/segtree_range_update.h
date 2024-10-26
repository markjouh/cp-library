template <class T, auto op, auto id>
struct SegtreeRU {
    int n;
    vector<T> st;

    SegtreeRU(int n_) : n(n_), st(2 * n, id()) {}

    void update(int l, int r, T v) {
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                st[l] = op(st[l], v);
                l++;
            }
            if (r & 1) {
                r--;
                st[r] = op(st[r], v);
            }
        }
    }

    int get(int p) {
        T res = id();
        for (p += n; p > 0; p >>= 1) {
            res = op(res, st[p]);
        }
        return res;
    }
};