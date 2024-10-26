template <class T>
struct BIT {
    int n;
    vector<T> ft;

    BIT(int n_) : n(n_), ft(n + 1) {}

    BIT(const vector<T> &a) : n(sz(a)), ft(n + 1) {
        for (int i = 1; i <= n; i++) {
            ft[i] += a[i - 1];
            if (i + (i & -i) <= n) {
                ft[i + (i & -i)] += ft[i];
            }
        }
    }

    void add(int p, T v) {
        for (p++; p <= n; p += p & -p) {
            ft[p] += v;
        }
    }

    T sum(int r) {
        T res = 0;
        for (r++; r > 0; r -= r & -r) {
            res += ft[r];
        }
        return res;
    }

    T sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};