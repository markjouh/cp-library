#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../boilerplate.hpp"
#include "../../../graphs/dijkstras.hpp"

// Doesn't measure the quality of the generated graphs,
// just a sanity check.

const int TESTS = 100;
const int INF = INT_MAX / 2;

int main() {
  for (int i = 0; i < TESTS; i++) {
    const int n = randInt(1e2, 1e4), root = randInt(n);
    auto g = genGraph(n, n - 1 + randInt(n));

    vector<int> dist(n, INF);
    queue<int> q;
    dist[root] = 0;
    q.push(root);

    while (sz(q)) {
      int u = q.front();
      q.pop();
      for (int v : g[u]) {
        if (dist[v] == INF) {
          dist[v] = dist[u] + 1;
          q.push(v);
        }
      }
    }
    assert(find(all(dist), INF) == end(dist));
  }

  for (int i = 0; i < TESTS; i++) {
    const int n = randInt(1e2, 1e4), root = randInt(n);
    auto g = genWeightedGraph(n, n - 1 + randInt(n));
    
    auto from = dijkstras<i64>(g, root).se;
    from[root] = root;
    assert(find(all(from), -1) == end(from));
  }

  cerr << "Tests passed" << endl;

  int a, b;
  cin >> a >> b;
  cout << a + b << '\n';
}