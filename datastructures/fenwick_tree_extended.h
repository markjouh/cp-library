/* A data structure that uses two fenwick trees in tandem to support both
 * range adds and range queries in O(log(N)).
 * A much smaller and faster alternative to lazy segment trees for this particular
 * use case.
 */

template<class T> struct extended_fenwick {
    int n;
    fenwick_tree<T> inside_pref, outside_pref;

    extended_fenwick(int x) : n(x), inside_pref(n), outside_pref(n) {}

    T sum(int r) {
        return inside_pref.sum(r - 1) + outside_pref.sum(n - r - 1) * (r + 1);
    }

    T sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int r, T v) {
        inside_pref.add(r, v * (r + 1));
        outside_pref.add(n - r - 1, v);
    }

    void add(int l, int r, T v) {
        add(r, v);
        if (l > 0) {
            add(l - 1, T(0) - T(v));
        }
    }
};
