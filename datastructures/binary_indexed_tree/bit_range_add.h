template <class T>
struct BITRU {
    int n;
    vector<T> ft;

    BITRU(int n_) : n(n_), ft(n + 1) {}

    BITRU(const vector<T> &a) : n(sz(a)), ft(n + 1) {
        for (int i = 0; i < n; i++) {
            ft[i + 1] += a[i];
            ft[i] -= a[i];
        }
        for (int i = n; i >= 1; i--) {
            ft[i - (i & -i)] += ft[i];
        }
    }

    void add(int r, T v) {
        for (r++; r > 0; r -= r & -r) {
            ft[r] += v;
        }
    }

    void add(int l, int r, T v) {
        add(r, v);
        add(l - 1, T(0) - v);
    }

    T get(int p) {
        T res = 0;
        for (p++; p <= n; p += p & -p) {
            res += ft[p];
        }
        return res;
    }
};