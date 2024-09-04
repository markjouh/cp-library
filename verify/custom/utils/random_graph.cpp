#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../boilerplate.hpp"
#include "../../../utils/random.hpp"
#include "../../../graphs/dijkstras.hpp"

// Doesn't measure the quality of the generated graphs,
// just a sanity check.

const int TESTS = 100;

int main() {
  rep(i, TESTS) {
    const int n = rnd<>(1e2, 1e4), root = rnd<>(0, n - 1);
    auto g = rnd_graph(n, n - 1 + rnd<>(1, n));

    vec<int> dist(n, inf<>);
    queue<int> q;
    dist[root] = 0;
    q.push(root);

    while (sz(q)) {
      int u = q.front();
      q.pop();
      for (int v : g[u]) {
        if (dist[v] == inf<>) {
          dist[v] = dist[u] + 1;
          q.push(v);
        }
      }
    }
    assert(find(all(dist), inf<>) == end(dist));
  }

  rep(i, TESTS) {
    const int n = rnd<>(1e2, 1e4), root = rnd<>(0, n - 1);
    auto g = rnd_wgraph(n, n - 1 + rnd<>(1, n));
    
    auto from = dijkstras<ll>(g, root).se;
    from[root] = root;
    assert(find(all(from), -1) == end(from));
  }

  cerr << "Tests passed" << endl;

  int a, b;
  cin >> a >> b;
  cout << a + b << '\n';
}