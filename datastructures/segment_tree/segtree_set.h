#include "segtree.h"

template <class T, auto op, auto id>
struct segtree_set {
    int n;
    set<int> free;
    set<pair<T, int>> used;
    Segtree<T, op, id> st;

    segtree_set(int n_) : n(n_), st(n) {
        for (int i = 0; i < n; i++) {
            free.insert(i);
        }
    }

    void insert(T x) {
        assert(!free.empty());
        T p = *begin(free);
        free.erase(begin(free));
        st.set(p, x);
        used.emplace(x, p);
    }

    void remove(T x) {
        auto it = used.lower_bound({x, -1});
        assert(it->first == x);
        st.set(it->second, id());
        free.insert(it->second);
        used.erase(it);
    }

    T query() {
        return st.query(0, n - 1);
    }
};