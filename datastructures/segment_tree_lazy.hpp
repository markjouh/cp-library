#pragma once

struct lazy_segtree {
    using item_t = pair<int, int>;
    using lazy_t = int;

    // Identity element, null update tag
    const item_t id = {INF, 1};
    const lazy_t lz_id = 0;

    // Associative merge operation
    item_t merge(item_t a, item_t b) {
        if (a.first == b.first) {
            return {a.first, a.second + b.second};
        } else {
            return a.first < b.first ? a : b;
        }
    }

    // Applying a lazy tag to a full segment
    void apply(int x, lazy_t v) {
        lazy[x] += v;
    }

    // Consuming and propagating a lazy tag
    void push(int x, int tl, int tr) {
        if (lazy[x] != lz_id) {
            tree[x].first += lazy[x];
            if (tl + 1 != tr) {
                lazy[2 * x + 1] += lazy[x];
                lazy[2 * x + 2] += lazy[x];
            }
            lazy[x] = lz_id;
        }
    }

    lazy_segtree(int x) {
        init(x);
    }

    lazy_segtree(const vector<item_t> &a) {
        init(sz(a));
        build(a, 0, 0, n);
    }

    item_t query(int l, int r) {
        return query(l, r + 1, 0, 0, n);
    }

    void update(int l, int r, int v) {
        update(l, r + 1, v, 0, 0, n);
    }

private:
    int n;
    vector<item_t> tree;
    vector<lazy_t> lazy;

    void init(int sz) {
        n = 1;
        while (n < sz) {
            n *= 2;
        }
        tree.resize(2 * n, id);
        lazy.resize(2 * n, lz_id);
    }

    void build(const vector<item_t> &a, int x, int tl, int tr) {
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

    item_t query(int l, int r, int x, int tl, int tr) {
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
            apply(x, v);
            push(x, tl, tr);
            return;
        }
        int mid = (tl + tr) / 2;
        update(l, r, v, 2 * x + 1, tl, mid);
        update(l, r, v, 2 * x + 2, mid, tr);
        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }
};