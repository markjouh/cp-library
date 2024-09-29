#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include "../../../misc/template.h"
#include "../../../datastructures/binary_indexed_tree/bit.h"

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        g[p].push_back(i);
    }
    
    int time = 0;
    vector<int> tin(n), tout(n);

    auto dfs = [&](auto &&self, int u, int par) -> void {
        tin[u] = time++;
        for (int v : g[u]) {
            if (v != par) {
                self(self, v, u);
            }
        }
        tout[u] = time;
    };

    dfs(dfs, 0, -1);

    BIT<ll> ft(n);
    for (int i = 0; i < n; i++) {
        ft.add(tin[i], a[i]);
    }
    while (q--) {
        bool t;
        int u;
        cin >> t >> u;
        if (t) {
            cout << ft.sum(tin[u], tout[u] - 1) << '\n';
        } else {
            int x;
            cin >> x;
            ft.add(tin[u], x);
        }
    }
}