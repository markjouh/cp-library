template<class T> struct LazyST {
    int n;
    vec<T> st, lz;

    const T id = 0;
    const T lz_id = 0;

    T merge(T a, T b) {
        return a + b;
    }

    void push(int x, int tl, int tr) {
        if (lz[x] != lz_id) {
            st[x] += (tr - tl) * lz[x];
            if (tl + 1 != tr) {
                lz[2 * x + 1] += lz[x];
                lz[2 * x + 2] += lz[x];
            }
            lz[x] = lz_id;
        }
    }

    LazyST(int sz) {
        init(sz);
    }

    LazyST(vec<T> &a) {
        init(sz(a));
        build(a, 0, 0, n);
    }

    void init(int sz) {
        n = 1;
        while (n < sz) {
            n *= 2;
        }
        st.resize(2 * n, id);
        lz.resize(2 * n, lz_id);
    }

    void build(vec<T> &a, int x, int tl, int tr) {
        if (tl + 1 == tr) {
            if (tl < sz(a)) {
                st[x] = a[tl];
            }
            return;
        }
        int mid = (tl + tr) / 2;
        build(a, 2 * x + 1, tl, mid);
        build(a, 2 * x + 2, mid, tr);
        st[x] = merge(st[2 * x + 1], st[2 * x + 2]);
    }

    T query(int l, int r, int x, int tl, int tr) {
        push(x, tl, tr);
        if (tl >= r || tr <= l) {
            return id;
        }
        if (tl >= l && tr <= r) {
            return st[x];
        }
        int mid = (tl + tr) / 2;
        return merge(query(l, r, 2 * x + 1, tl, mid), query(l, r, 2 * x + 2, mid, tr));
    }

    T query(int l, int r) {
        return query(l, r + 1, 0, 0, n);
    }

    void update(int l, int r, int v, int x, int tl, int tr) {
        push(x, tl, tr);
        if (tl >= r || tr <= l) {
            return;
        }
        if (tl >= l && tr <= r) {
            lz[x] += v;
            push(x, tl, tr);
            return;
        }
        int mid = (tl + tr) / 2;
        update(l, r, v, 2 * x + 1, tl, mid);
        update(l, r, v, 2 * x + 2, mid, tr);
        st[x] = merge(st[2 * x + 1], st[2 * x + 2]);
    }

    void update(int l, int r, int v) {
        update(l, r + 1, v, 0, 0, n);
    }

    // int walk(int x, int tl, int tr) {
    //     push(x, tl, tr);
    //     if (tl + 1 == tr) {
    //         return tl;
    //     }
    //     int mid = (tl + tr) / 2;
    //     push(2 * x + 1, tl, mid);
    //     push(2 * x + 2, mid, tr);
    //     if (...) {
    //         return walk(2 * x + 1, tl, mid);
    //     } else {
    //         return walk(2 * x + 2, mid, tr);
    //     }
    // }

    // int walk() {
    //     return walk(0, 0, n);
    // }
};
