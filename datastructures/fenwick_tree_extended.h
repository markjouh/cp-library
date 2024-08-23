/* A data structure that uses two fenwick trees in conjunction to support both
 * range adds and range updates in log(N).
 * A much smaller and faster alternative to lazy segment trees for this particular
 * use case.
 */

template<class T> struct extended_fenwick {
    int n;
    fenwick_tree<T> in, out;

    extended_fenwick(int x) : n(x), in(n), out(n) {}

    T sum(int r) {
        return in.sum(r - 1) + out.sum(n - r - 1) * (r + 1);
    }

    T sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int r, T v) {
        in.add(r, v * (r + 1));
        out.add(n - r - 1, v);
    }

    void add(int l, int r, T v) {
        add(r, v);
        if (l > 0) {
            add(l - 1, T(0) - T(v));
        }
    }
};
