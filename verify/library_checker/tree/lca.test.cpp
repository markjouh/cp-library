#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "../../../misc/template.h"
#include "../../../graphs/trees/binary_lifting.h"

int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        g[p].push_back(i);
    }
    BinaryLifting bl(g);
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << bl.lca(u, v) << '\n';
    }
}