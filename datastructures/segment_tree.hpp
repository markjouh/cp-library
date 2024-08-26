/* A data structure that stores an array of objects with an identity element
 * and associative binary operator.
 * `segment_tree(x)`: O(N)
 * `update(x, y)`, `query(x, y)`: O(log(N))
 */

template<class T, T(*op)(T, T), T(*id)()> struct segment_tree {
    int n;
    vector<T> tree;

    segment_tree(int sz) : n(sz), tree(2 * n, id()) {}

    segment_tree(const vector<T> &a) : n(sz(a)), tree(2 * n) {
        copy(begin(a), end(a), begin(tree) + n);
        for (int i = n - 1; i > 0; i--) {
            tree[i] = op(tree[i << 1], tree[i << 1 | 1]);
        }
    }

    T query(int l, int r) {
        T ls = id(), rs = id();
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                ls = op(ls, tree[l++]);
            }
            if (r & 1) {
                rs = op(tree[--r], rs);
            }
        }
        return op(ls, rs);
    }

    void set(int p, T val) {
        for (tree[p += n] = val, p >>= 1; p > 0; p >>= 1) {
            tree[p] = op(tree[p << 1], tree[p << 1 | 1]);
        }
    }
};
