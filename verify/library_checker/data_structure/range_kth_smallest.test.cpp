#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"

#include "../../../misc/template.h"
#include "../../../datastructures/static/mergesort_tree.h"
#include "../../../numeric/binsearch.h"

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    MergesortTree<int> mt(a);
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        r--;
        cout << bsmin(0, int(1e9), [&](int x) {
            return mt.query(l, r, x + 1) >= k + 1;
        }) << '\n';
    }
}