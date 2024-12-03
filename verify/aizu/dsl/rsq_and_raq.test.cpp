#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G"

#include "../../../template/template.h"
#include "../../../datastructures/fenwick_tree/dual_fentree.h"

int main() {
    int n, q;
    cin >> n >> q;
    dual_fentree<ll> ft(n);
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