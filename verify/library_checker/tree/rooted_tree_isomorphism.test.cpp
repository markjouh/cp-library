#define PROBLEM "https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification"

#include "../../../misc/template.h"
#include "../../../graphs/trees/tree_hashing.h"

int main() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        g[p].push_back(i);
    }
    TreeHashing iso;
    auto res = iso.add(g);
    cout << sz(iso.hash) << '\n';
    for (int x : res) {
        cout << x << ' ';
    }
    cout << '\n';
}