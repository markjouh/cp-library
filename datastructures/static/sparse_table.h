#pragma once

template <class T, auto op>
struct RMQ {
    int n, log;
    vector<vector<T>> st;

    RMQ() {}
    RMQ(const vector<T> &a) : n(sz(a)), log(__lg(n) + 1) {
        st.resize(log);
        st[0] = a;
        rep(i, 1, log) {
            st[i].resize(n - (1 << i) + 1);
            rep(j, sz(st[i])) {
                st[i][j] = op(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    T query(int l, int r) {
        assert(l <= r);
        int i = __lg(++r - l);
        return op(st[i][l], st[i][r - (1 << i)]);
    }
};