#pragma once

struct CentroidDecomposition {
  vector<int> cdPar;

  CentroidDecomposition(const vector<vector<int>> &g) : adj(g) {
    cdPar.resize(sz(g));
    blocked.resize(sz(g));
    subtreeSize.resize(sz(g));
    for (int i = 0; i < sz(g); i++) {
      if (subtreeSize[i] == 0) {
        build(i, -1);
      }
    }
    blocked.clear();
    subtreeSize.clear();
  }

private:
  const vector<vector<int>> &adj;
  vector<bool> blocked;
  vector<int> subtreeSize;

  void getSizes(int u, int par) {
    subtreeSize[u] = 1;
    for (int v : adj[u]) {
      if (v != par && !blocked[v]) {
        getSizes(v, u);
        subtreeSize[u] += subtreeSize[v];
      }
    }
  }

  int findCentroid(int u, int par, int treeSize) {
    int nxt = -1;
    for (int v : adj[u]) {
      if (v != par && !blocked[v] && subtreeSize[v] * 2 > treeSize) {
        nxt = v;
        break;
      }
    }
    return nxt == -1 ? u : findCentroid(nxt, u, treeSize);
  }

  void build(int u, int par) {
    getSizes(u, -1);
    const int root = findCentroid(u, -1, subtreeSize[u]);
    cdPar[root] = par;
    blocked[root] = true;
    for (int v : adj[root]) {
      if (!blocked[v]) {
        build(v, root);
      }
    }
  }
};
