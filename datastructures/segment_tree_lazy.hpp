/* A standard segment tree with lazy updates.
 * `segment_tree(x)`: O(N)`
 * `update(l, r, v)`, `query(l, r)`: O(log(N))
 */

#pragma once

template<class T> struct lazy_segtree {
    const T id = 0;
    const T lz_id = 0;

    T merge(T a, T b) {
        return a + b;
    }

    void push(int x, int tl, int tr) {
        if (lazy[x] != lz_id) {
            tree[x] += (tr - tl) * lazy[x]; // Make sure this checks out!
            if (tl + 1 != tr) {
                lazy[2 * x + 1] += lazy[x];
                lazy[2 * x + 2] += lazy[x];
            }
            lazy[x] = lz_id;
        }
    }

    // Modify above ^^

    lazy_segtree(int x) {
        init(x);
    }

    lazy_segtree(const vector<T> &a) {
        init(sz(a));
        build(a, 0, 0, n);
    }

    T query(int l, int r) {
        return query(l, r + 1, 0, 0, n);
    }

    void update(int l, int r, int v) {
        update(l, r + 1, v, 0, 0, n);
    }

    // int walk() {
    //     return walk(0, 0, n);
    // }

private:
    int n;
    vector<T> tree, lazy;

    void init(int sz) {
        n = 1;
        while (n < sz) {
            n *= 2;
        }
        tree.resize(2 * n, id);
        lazy.resize(2 * n, lz_id);
    }

    void build(vector<T> &a, int x, int tl, int tr) {
        if (tl + 1 == tr) {
            if (tl < sz(a)) {
                tree[x] = a[tl];
            }
            return;
        }
        int mid = (tl + tr) / 2;
        build(a, 2 * x + 1, tl, mid);
        build(a, 2 * x + 2, mid, tr);
        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    T query(int l, int r, int x, int tl, int tr) {
        push(x, tl, tr);
        if (tl >= r || tr <= l) {
            return id;
        }
        if (tl >= l && tr <= r) {
            return tree[x];
        }
        int mid = (tl + tr) / 2;
        return merge(query(l, r, 2 * x + 1, tl, mid), query(l, r, 2 * x + 2, mid, tr));
    }

    void update(int l, int r, int v, int x, int tl, int tr) {
        push(x, tl, tr);
        if (tl >= r || tr <= l) {
            return;
        }
        if (tl >= l && tr <= r) {
            lazy[x] += v;
            push(x, tl, tr);
            return;
        }
        int mid = (tl + tr) / 2;
        update(l, r, v, 2 * x + 1, tl, mid);
        update(l, r, v, 2 * x + 2, mid, tr);
        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
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
};
