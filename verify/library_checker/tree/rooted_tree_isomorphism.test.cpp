#define PROBLEM "https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification"

#include "../../../misc/template.h"
#include "../../../graphs/tree/tree_isomorphism.h"

int main() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        g[p].push_back(i);
    }
    TreeIsomorphism iso;
    auto res = iso.gen(g);
    cout << sz(iso.hashes) << '\n';
    for (int x : res) {
        cout << x << ' ';
    }
    cout << '\n';
}