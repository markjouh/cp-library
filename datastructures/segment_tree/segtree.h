template <class T, auto op, auto id>
struct Segtree {
    int n;
    vector<T> st;

    Segtree(int n_) : n(n_), st(2 * n, id()) {}

    Segtree(const vector<T> &a) : n(sz(a)), st(2 * n) {
        copy(all(a), begin(st) + n);
        for (int i = n - 1; i > 0; i--) {
            st[i] = op(st[i << 1], st[i << 1 | 1]);
        }
    }

    T get(int p) {
        return st[p + n];
    }

    T query(int l, int r) {
        T ls = id(), rs = id();
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                ls = op(ls, st[l++]);
            }
            if (r & 1) {
                rs = op(st[--r], rs);
            }
        }
        return op(ls, rs);
    }

    void set(int p, T val) {
        for (st[p += n] = val, p >>= 1; p > 0; p >>= 1) {
            st[p] = op(st[p << 1], st[p << 1 | 1]);
        }
    }
};