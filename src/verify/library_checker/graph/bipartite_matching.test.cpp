#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

#include "../../../template/template.h"
#include "../../../graphs/bipartite_matching.h"

int main() {
  int L, R, M;
  cin >> L >> R >> M;

  vector<vector<int>> ls_adj(L);
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    ls_adj[u].push_back(v);
  }

  vector<int> rs_match(R, -1);

  cout << bipartite_matching(ls_adj, rs_match) << '\n';

  for (int i = 0; i < R; i++) {
    if (rs_match[i] != -1) {
      cout << rs_match[i] << ' ' << i << '\n';
    }
  }
}