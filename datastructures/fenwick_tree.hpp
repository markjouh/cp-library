#pragma once

template<class T> struct fenwick_tree {
    int n;
    vector<T> tree;

    fenwick_tree(int x) : n(x), tree(n + 1) {}

    fenwick_tree(const vector<T> &a) : n(sz(a)), tree(n + 1) {
        for (int i = 1; i <= n; i++) {
            tree[i] += a[i - 1];
            if (i + (i & -i) <= n) {
                tree[i + (i & -i)] += tree[i];
            }
        }
    }

    void add(int p, T v) {
        assert(p >= 0);
        for (p++; p <= n; p += p & -p) {
            tree[p] += v;
        }
    }

    T sum(int r) {
        assert(r < n);
        T res = 0;
        for (r++; r > 0; r -= r & -r) {
            res += tree[r];
        }
        return res;
    }

    T sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

/**
 * @brief Fenwick Tree (Binary Indexed Tree)
 * @docs docs/datastructures/fenwick_tree.md
 */