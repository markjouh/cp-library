#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G"

#include "../../boilerplate.hpp"
#include "../../../datastructures/fenwick_tree_extended.hpp"

int main() {
    int n, q;
    cin >> n >> q;
    extended_fenwick<ll> ft(n);
    while (q--) {
        bool t;
        int l, r;
        cin >> t >> l >> r;
        l--; r--;
        if (t) {
            cout << ft.sum(l, r) << '\n';
        } else {
            int x;
            cin >> x;
            ft.add(l, r, x);
        }
    }
}