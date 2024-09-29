#pragma once

template <class T, auto op, auto t_id, class U, auto mapping, auto comp, auto u_id>
struct LazySegtree {
    LazySegtree(int n_, T v = t_id()) {
        init(n_, v);
        pull_all();
    }

    LazySegtree(const vector<T> &a) {
        init(sz(a), t_id());
        copy(all(a), begin(st) + tree_sz);
        pull_all();
    }

    void set(int p, T v) {
        push_path(p += tree_sz);
        st[p] = v;
        pull_path(p);
    }

    void update(int p, U v) {
        push_path(p += tree_sz);
        st[p] = mapping(st[p], v);
        pull_path(p);
    }

    void update(int l, int r, U v) {
        update(l, r + 1, v, 1, 0, tree_sz);
    }

    T get_all() {
        return st[1];
    }

    T get(int p) {
        push_path(p += tree_sz);
        return st[p];
    }

    T query(int l, int r) {
        return query(l, r + 1, 1, 0, tree_sz);
    }

    template <class F>
    int find_first(F f) {
        T pref = t_id();
        int x = 1;
        while (x < tree_sz) {
            push(x);
            if (f(op(pref, st[x << 1]))) {
                x = x << 1;
            } else {
                pref = op(pref, st[x << 1]);
                x = x << 1 | 1;
            }
        }
        return f(op(pref, st[x])) ? x - tree_sz : n;
    }

    template <class F>
    int find_last(F f) {
        T suff = t_id();
        int x = 1;
        while (x < tree_sz) {
            push(x);
            if (f(st[x << 1 | 1], suff)) {
                x = x << 1 | 1;
            } else {
                suff = op(st[x << 1 | 1], suff);
                x = x << 1;
            }
        }
        return f(op(st[x], suff)) ? x - tree_sz : -1;
    }
    
private:
    int n, log, tree_sz;
    vector<T> st;
    vector<U> lz;

    void init(int n_, T v) {
        n = n_;
        log = __lg(n - 1) + 1;
        tree_sz = 1 << log;
        st.resize(tree_sz << 1, v);
        lz.resize(tree_sz, u_id());
    }

    void pull(int x) {
        st[x] = op(st[x << 1], st[x << 1 | 1]);
    }

    void pull_path(int x) {
        for (int i = 1; i <= log; i++) {
            pull(x >> i);
        }
    }

    void pull_all() {
        for (int i = tree_sz - 1; i > 0; i--) {
            pull(i);
        }
    }

    void apply(int x) {
        st[x] = mapping(st[x], lz[x >> 1]);
        if (x < tree_sz) {
            lz[x] = comp(lz[x], lz[x >> 1]);
        }
    }

    void push(int x) {
        apply(x << 1);
        apply(x << 1 | 1);
        lz[x] = u_id();
    }

    void push_path(int x) {
        for (int i = log; i > 0; i--) {
            push(x >> i);
        }
    }

    void update(int l, int r, U v, int x, int tl, int tr) {
        if (tl >= r || tr <= l) {
            return;
        }
        if (tl >= l && tr <= r) {
            st[x] = mapping(st[x], v);
            if (x < tree_sz) {
                lz[x] = comp(lz[x], v);
            }
            return;
        }
        push(x);
        int mid = (tl + tr) >> 1;
        update(l, r, v, x << 1, tl, mid);
        update(l, r, v, x << 1 | 1, mid, tr);
        pull(x);
    }

    T query(int l, int r, int x, int tl, int tr) {
        if (tl >= r || tr <= l) {
            return t_id();
        }
        if (tl >= l && tr <= r) {
            return st[x];
        }
        push(x);
        int mid = (tl + tr) >> 1;
        return op(query(l, r, x << 1, tl, mid), query(l, r, x << 1 | 1, mid, tr));
    }
};