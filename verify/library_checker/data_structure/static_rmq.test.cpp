#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../../../template/template.h"
#include "../../../datastructures/static/sparse_table.h"

int op(int x, int y) {
    return x < y ? x : y;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sparse_table<int, op> rmq(a);
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << rmq.query(l, r - 1) << '\n';
    }
}