// https://codeforces.com/contest/342/submission/307361210

struct CentroidDecomp {
  int root;
  vector<int> par;
  vector<vector<int>> tree;

  CentroidDecomp(const vector<vector<int>> &g_) : g(g_) {
    const int n = g.size();
    par.resize(n);
    blocked.resize(n);
    st_size.resize(n);
    for (int i = 0; i < n; i++) {
      if (st_size[i] == 0) {
        build(i, -1);
      }
    }
    blocked.clear();
    st_size.clear();

    tree.resize(n);
    for (int i = 0; i < n; i++) {
      if (par[i] == -1) {
        root = i;
      } else {
        tree[par[i]].push_back(i);
      }
    }
  }

private:
  const vector<vector<int>> &g;
  vector<bool> blocked;
  vector<int> st_size;

  void get_sizes(int u, int u_par) {
    st_size[u] = 1;
    for (int v : g[u]) {
      if (v != u_par && !blocked[v]) {
        get_sizes(v, u);
        st_size[u] += st_size[v];
      }
    }
  }

  int get_centroid(int u, int u_par, int tree_sz) {
    int nxt = -1;
    for (int v : g[u]) {
      if (v != u_par && !blocked[v] && st_size[v] * 2 > tree_sz) {
        nxt = v;
        break;
      }
    }
    return nxt == -1 ? u : get_centroid(nxt, u, tree_sz);
  }
  
  void build(int u, int u_par) {
    get_sizes(u, -1);
    const int cent = get_centroid(u, -1, st_size[u]);
    par[cent] = u_par;
    blocked[cent] = true;
    for (int v : g[cent]) {
      if (!blocked[v]) {
        build(v, cent);
      }
    }
  }
};
