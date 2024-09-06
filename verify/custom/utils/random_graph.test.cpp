#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../boilerplate.hpp"
#include "../../../graphs/dijkstras.hpp"

// Doesn't measure the quality of the generated graphs,
// just a sanity check.

const int TESTS = 100;

int main() {
  for (int i = 0; i < TESTS; i++) {
    const int n = randint(1e2, 1e4), root = randint(n);
    auto g = gen_graph(n, n - 1 + randint(n));

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

  for (int i = 0; i < TESTS; i++) {
    const int n = randint(1e2, 1e4), root = randint(n);
    auto g = gen_w_graph(n, n - 1 + randint(n));
    
    auto from = dijkstras<ll>(g, root).se;
    from[root] = root;
    assert(find(all(from), -1) == end(from));
  }

  cerr << "Tests passed" << endl;

  int a, b;
  cin >> a >> b;
  cout << a + b << '\n';
}