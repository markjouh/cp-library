struct EdmondsKarpMaxFlow {
  struct Edge {
    int from, to;
    int c, f;
  };

  int n, s, t;
  vector<vector<int>> g;
  vector<Edge> edges;

  EdmondsKarpMaxFlow(int n_, int s_, int t_) : n(n_), s(s_), t(t_), g(n) {}

  void add(int u, int v, int cap = INT_MAX) {
    g[u].push_back(edges.size());
    edges.push_back({u, v, cap, 0});
    g[v].push_back(edges.size());
    edges.push_back({v, u, 0, 0});
  }

  int max_flow() {
    int res = 0;

    while (true) {
      bool found_path = false;

      vector<int> par(n, -1);
      queue<pair<int, int>> q;
      par[s] = -2;
      q.push({s, INT_MAX});

      while (!q.empty()) {
        auto [u, mn] = q.front();
        q.pop();

        if (u == t) {
          res += mn;
          found_path = true;
          while (u != s) {
            edges[par[u]].f += mn;
            edges[par[u] ^ 1].f -= mn;
            u = edges[par[u]].from;
          }
          break;
        }

        for (int id : g[u]) {
          int v = edges[id].to;
          int r = edges[id].c - edges[id].f;
          if (par[v] == -1 && r > 0) {
            par[v] = id;
            q.push({v, min(mn, r)});
          }
        }
      }

      if (!found_path) {
        break;
      }
    }

    return res;
  }
};