#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../../misc/template.h"
#include "../../../graphs/topsort.h"

const int N = 500, T = 100;

void test() {
    int m = rand_int(N - 1, N * (N - 1) / 2);

    auto edges = gen_graph_edges(N, m);
    vector<vector<int>> g(N);
    for (auto &[u, v] : edges) {
        g[u].push_back(v);
    }

    auto result = topsort(g);
    vector<int> pos(sz(result));
    for (int i = 0; i < sz(result); i++) {
        pos[result[i]] = i;
    }

    assert(sz(result) == N);
    for (auto [u, v] : edges) {
        assert(pos[u] < pos[v]);
    }
}

int main() {
    for (int i = 0; i < T; i++) {
        test();
    }

    cerr << "All tests passed\n";
    int a_, b_;
    cin >> a_ >> b_;
    cout << a_ + b_ << '\n';
}
