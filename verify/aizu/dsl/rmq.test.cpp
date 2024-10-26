#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"

#include "../../../template/template.h"
#include "../../../datastructures/segment_tree/segtree.h"

int op(int x, int y) {
    return x < y ? x : y;
}

int id() {
    return INT_MAX;
}

int main() {
    int n, q;
    cin >> n >> q;
    Segtree<int, op, id> st(n);
    while (q--) {
        bool t;
        int x, y;
        cin >> t >> x >> y;
        if (t) {
            cout << st.query(x, y) << '\n';
        } else {
            st.set(x, y);
        }
    }
}