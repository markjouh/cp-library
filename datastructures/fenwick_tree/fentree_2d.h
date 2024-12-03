#include "fentree.h"

template <class T>
struct fentree_2d {
    int n;
    vector<fentree<T>> ft;

    fenwick_tree_2d(int n_, int m) : n(n_), ft(n + 1, fentree<T>(m)) {}

    void add(int r, int c, T v) {
        for (r++; r <= n; r += r & -r) {
            ft[r].add(c, v);
        }
    }

    T sum(int r, int c) {
        if (r < 0 || c < 0) {
            return 0;
        }
        T res = 0;
        for (r++; r > 0; r -= r & -r) {
            res += ft[r].sum(c);
        }
        return res;
    }

    T sum(int r1, int c1, int r2, int c2) {
        return sum(r2, c2) - sum(r2, c1 - 1) - sum(r1 - 1, c2) + sum(r1 - 1, c1 - 1);
    }
};