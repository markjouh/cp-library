/* Uses 2 fenwick trees to support both range updates and range queries.
 * `add(l, r, v)`, `sum(l, r)`: O(log(r))
 */

#pragma once
#include "fenwick_tree.hpp"

template<class T> struct extended_fenwick {
    int n;
    fenwick_tree<T> inside, outside;

    extended_fenwick(int x) : n(x), inside(n), outside(n) {}

    T sum(int r) {
        return inside.sum(r - 1) + outside.sum(n - r - 1) * (r + 1);
    }

    T sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int r, T v) {
        inside.add(r, v * (r + 1));
        outside.add(n - r - 1, v);
    }

    void add(int l, int r, T v) {
        add(r, v);
        if (l > 0) {
            add(l - 1, T(0) - T(v));
        }
    }
};
