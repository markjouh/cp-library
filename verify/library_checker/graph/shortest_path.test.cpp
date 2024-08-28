#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include "../../boilerplate.hpp"
#include "../../../graphs/dijkstras.hpp"

int main() {
  int n, m, s, t;
  cin >> n >> m >> s >> t;
  vector<vector<pii>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].eb(v, w);
  }
  auto [dist, from] = dijkstras<ll>(g, s);
  if (dist[t] != numeric_limits<ll>::max()) {
    cout << dist[t] << ' ';
    vector<pii> path;
    int p = t;
    while (p != s) {
      path.eb(from[p], p);
      p = from[p];
    }
    reverse(all(path));
    cout << sz(path) << '\n';
    for (auto [u, v] : path) {
      cout << u << ' ' << v << '\n';
    }
  } else {
    cout << -1 << '\n';
  }
}