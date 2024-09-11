#pragma once

struct CentroidDecomposition {
  vector<int> cdPar;

  CentroidDecomposition(const vector<vector<int>> &g) : adj(g) {
    cdPar.resize(sz(g));
    blocked.resize(sz(g));
    stSize.resize(sz(g));
    for (int i = 0; i < sz(g); i++) {
      if (stSize[i] == 0) {
        build(i, -1);
      }
    }
    blocked.clear();
    stSize.clear();
  }

private:
  const vector<vector<int>> &adj;
  vector<bool> blocked;
  vector<int> stSize;

  void getSizes(int u, int par) {
    stSize[u] = 1;
    for (int v : adj[u]) {
      if (v != par && !blocked[v]) {
        getSizes(v, u);
        stSize[u] += stSize[v];
      }
    }
  }

  int findCentroid(int u, int par, int treeSize) {
    int nxt = -1;
    for (int v : adj[u]) {
      if (v != par && !blocked[v] && stSize[v] * 2 > treeSize) {
        nxt = v;
        break;
      }
    }
    return nxt == -1 ? u : findCentroid(nxt, u, treeSize);
  }

  void build(int u, int par) {
    getSizes(u, -1);
    const int root = findCentroid(u, -1, stSize[u]);
    cdPar[root] = par;
    blocked[root] = true;
    for (int v : adj[root]) {
      if (!blocked[v]) {
        build(v, root);
      }
    }
  }
};
