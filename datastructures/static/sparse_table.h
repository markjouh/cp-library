#pragma once

template <class T, T(*op)(T, T)>
struct SparseTable {
    int n, log;
    vector<vector<T>> table;

    SparseTable(const vector<T> &a) : n(sz(a)), log(__lg(n) + 1) {
        table.resize(log);
        table[0] = a;
        for (int i = 1; i < log; i++) {
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
