#pragma once

template <class T>
T min_f(T x, T y) {
    return x < y ? x : y;
}
template <class T>
T max_f(T x, T y) {
    return x > y ? x : y;
}

template <class T, auto op = min_f<T>>
struct RMQ {
    int n, log;
    vector<vector<T>> st;

    RMQ() {}
    RMQ(const vector<T> &a) : n(sz(a)), log(__lg(n) + 1) {
        st.resize(log);
        st[0] = a;
        for (int i = 1; i < log; i++) {
            st[i].resize(n - (1 << i) + 1);
            for (int j = 0; j < sz(st[i]); j++) {
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