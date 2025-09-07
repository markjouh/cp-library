template <class T, auto op, auto id>
struct persistent_segtree {
    int log, tree_sz, updates;
    vector<T> st;
    vector<array<int, 2>> ch;

    persistent_segtree() {}

    persistent_segtree(int n) {
        log = __lg(n) + 1;
        tree_sz = 1 << log;
        st.resize(tree_sz << 1, id());
        ch.resize(tree_sz << 1);
        for (int i = tree_sz - 1; i > 0; i--) {
            ch[i] = {i << 1, i << 1 | 1};
        }
    }

    int get_root(int t = -1) {
        if (t == -1) {
            t = updates;
        }
        return t == 0 ? 1 : tree_sz + (t - 1) * (log - 1) + 1;
    }

    void update(int p, T val) {
        int x = get_root(), tl = 0, tr = tree_sz;
        for (int i = 0; i < log - 1; i++) {
            st.push_back(id());
            int mid = (tl + tr) >> 1;
            if (p < mid) {
                ch.push_back({sz(st), ch[x][1]});
                x = ch[x][0];
                tr = mid;
            } else {
                ch.push_back({ch[x][0], sz(st)});
                x = ch[x][1];
                tl = mid;
            }
        }
        st.push_back(val);
        for (int i = sz(st) - 2; i >= sz(st) - log; i--) {
            st[i] = op(st[ch[i][0]], st[ch[i][1]]);
        }
        updates++;
    }

    T query(int l, int r, int x, int tl, int tr) {
        if (tl >= r || tr <= l) {
            return id();
        }
        if (tl >= l && tr <= r) {
            return st[x];
        }
        int mid = (tl + tr) >> 1;
        return op(query(l, r, ch[x][0], tl, mid), query(l, r, ch[x][1], mid, tr));
    }

    T query(int l, int r, int t = -1) {
        return query(l, r + 1, get_root(t), 0, tree_sz);
    }
};