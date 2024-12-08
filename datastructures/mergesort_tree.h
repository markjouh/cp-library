#include "ordered_set.h"

template <class T>
struct mergesort_tree {
    int n;
    vector<ordered_set<pair<T, int>>> st;
 
    mergesort_tree(const vector<T> &a) : n(sz(a)), st(2 * n) {
        for (int i = 0; i < n; i++) {
            for (int p = i + n; p > 0; p >>= 1) {
                st[p].insert({a[i], i});
            }
        }
    }
 
    int query(int l, int r, T v) {
        int res = 0;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                res += st[l++].order_of_key({v, 0});
            }
            if (r & 1) {
                res += st[--r].order_of_key({v, 0});
            }
        }
        return res;
    }
 
    void set(int p, T v) {
        const auto old = *begin(st[p + n]);
        for (p += n; p > 0; p >>= 1) {
            st[p].erase(old);
            st[p].insert(v);
        }
    }
};