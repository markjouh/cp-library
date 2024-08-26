/* A data structure that stores an array of objects with an associative and
 * idempotent binary operator.
 * `sparse_table(x)`: O(N * log(N))
 * `query(l, r)`: O(1)
 */

#pragma once

template<class T, T(*op)(T, T)> struct sparse_table {
    int n, lg;
    vector<vector<T>> table;

    sparse_table(const vector<T> &a) : n(sz(a)), lg(__lg(n) + 1), table(lg) {
        table[0] = a;
        for (int i = 1; i < lg; i++) {
            table[i].resize(n - (1 << i) + 1);
            for (int j = 0; j < sz(table[i]); j++) {
                table[i][j] = op(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    T query(int l, int r) {
        assert(l <= r);
        int i = __lg(++r - l);
        return op(table[i][l], table[i][r - (1 << i)]);
    }
};
