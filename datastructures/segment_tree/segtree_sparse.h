template <class T, auto op, auto id>
struct SegtreeSparse {
    SegtreeSparse() {}
    
    SegtreeSparse(int n) {
        log = __lg(n) + 1;
        tree_sz = 1 << log;
        st.push_back(id());
        ch.emplace_back(-1, -1);
    }

    void set(int p, T v) {
        buf[0] = idx = 0;
        int tl = 0, tr = tree_sz;
        while (tl + 1 != tr) {
            int mid = (tl + tr) >> 1;
            if (p < mid) {
                buf[idx + 1] = get_l(buf[idx]);
                tr = mid;
            } else {
                buf[idx + 1] = get_r(buf[idx]);
                tl = mid;
            }
            idx++;
        }
        st[buf[idx--]] = v;
        while (idx >= 0) {
            pull(buf[idx--]);
        }
    }

    T query(int l, int r) {
        return get(l, r + 1, 0, 0, tree_sz);
    }

private:
    int log, tree_sz;
    vector<T> st;
    vector<pair<int, int>> ch;

    int buf[32];
    int idx;

    int get_l(int x) {
        if (ch[x].first == -1) {
            ch[x].first = sz(st);
            st.push_back(id());
            ch.emplace_back(-1, -1);
        }
        return ch[x].first;
    }

    int get_r(int x) {
        if (ch[x].second == -1) {
            ch[x].second = sz(st);
            st.push_back(id());
            ch.emplace_back(-1, -1);
        }
        return ch[x].second;
    }

    void pull(int x) {
        if (ch[x].first == -1) {
            st[x] = st[ch[x].second];
        } else if (ch[x].second != -1) {
            st[x] = op(st[ch[x].first], st[ch[x].second]);
        } else {
            st[x] = st[ch[x].first];
        }
    }

    T get(int l, int r, int x, int tl, int tr) {
        if (x == -1 || tl >= r || tr <= l) {
            return id();
        }
        if (tl >= l && tr <= r) {
            return st[x];
        }
        int mid = (tl + tr) >> 1;
        return op(get(l, r, ch[x].first, tl, mid), get(l, r, ch[x].second, mid, tr));
    }
};