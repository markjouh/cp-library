template<class T, bool use_max = false> struct RMQ {
    int n, lg;
    vec<vec<T>> rmq;

    T merge(T a, T b) {
        if constexpr (use_max) {
            return max(a, b);
        } else {
            return min(a, b);
        }
    }

    RMQ(vec<T> &a) : n(sz(a)), lg(__lg(n) + 1), rmq(lg) {
        rmq[0] = a;
        rep(i, 1, lg) {
            rmq[i].resize(n - (1 << i) + 1);
            rep(j, sz(rmq[i])) {
                rmq[i][j] = merge(rmq[i - 1][j], rmq[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    T query(int l, int r) {
        assert(l <= r);
        int i = __lg(++r - l);
        return merge(rmq[i][l], rmq[i][r - (1 << i)]);
    }
};
