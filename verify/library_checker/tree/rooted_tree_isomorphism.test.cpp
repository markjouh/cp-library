#define PROBLEM "https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification"

#include "../../boilerplate.hpp"
#include "../../../graphs/tree_isomorphism.hpp"

int main() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        g[p].push_back(i);
    }
    tree_isomorphism iso;
    auto res = iso.gen(g);
    cout << sz(iso.hashes) << '\n';
    for (int x : res) {
        cout << x << ' ';
    }
    cout << '\n';
}