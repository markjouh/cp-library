#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../../../misc/template.h"
#include "../../../datastructures/binary_indexed_tree/bit.h"

int main() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    BIT<ll> ft(a);
    while (q--) {
        bool t;
        int x, y;
        cin >> t >> x >> y;
        if (t) {
            cout << ft.sum(x, y - 1) << '\n';
        } else {
            ft.add(x, y);
        }
    }
}