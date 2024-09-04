#pragma once

#include <type_traits>

mt19937_64 rng_64(chrono::steady_clock::now().time_since_epoch().count());

template <class T = int>
T rnd(T lo, T hi) {
  static_assert(is_arithmetic_v<T>, "Invalid type for rnd()");
  if constexpr (is_integral_v<T>) {
    return uniform_int_distribution<T>(lo, hi)(rng_64);
  } else {
    return uniform_real_distribution<T>(lo, hi)(rng_64);
  }
}

template <class T = int>
vec<T> rnd_vec(int n, T lo, T hi) {
  vec<T> res(n);
  rep(i, n) {
    res[i] = rnd<T>(lo, hi);
  }
  return res;
}

vec<pii> rnd_tree_edges(int n) {
  const vec<int> prufer = rnd_vec(n - 2, 0, n - 1);
  vec<int> deg(n, 1);
  for (int x : prufer) {
    deg[x]++;
  }
  priority_queue<int, vec<int>, greater<>> leaves;
  rep(i, n) {
    if (deg[i] == 1) {
      leaves.push(i);
    }
  }

  vec<pii> res;
  res.reserve(n - 1);
  for (int v : prufer) {
    int u = leaves.top();
    leaves.pop();

    res.pb(minmax(u, v));
    deg[u]--, deg[v]--;

    if (deg[v] == 1) {
      leaves.push(v);
    }
  }

  int r1 = -1, r2 = -1;
  rep(i, n) {
    if (deg[i] == 1) {
      (r1 == -1 ? r1 : r2) = i;
    }
  }
  assert(r2 != -1);
  res.eb(r1, r2);

  return res;
}

vec<pii> rnd_graph_edges(int n, int m) {
  assert(m >= n - 1 && m <= 1ll * n * (n - 1) / 2);

  auto res = rnd_tree_edges(n);
  set<pii> have;
  for (auto [u, v] : res) {
    have.emplace(u, v);
  }

  while (sz(res) < m) {
    int u = rnd<>(0, n - 1), v = rnd<>(0, n - 2);
    v += v >= u;
    if (u > v) {
      swap(u, v);
    }
    if (!have.count({u, v})) {
      res.eb(u, v);
      have.emplace(u, v);
    }
  }
  return res;
}

vec<vec<int>> rnd_graph(int n, int m, bool directed = false) {
  vec<vec<int>> g(n);
  for (auto [u, v] : rnd_graph_edges(n, m)) {
    if (directed) {
      if (rnd<>(0, 1)) {
        swap(u, v);
      }
      g[u].pb(v);
    } else {
      g[u].pb(v);
      g[v].pb(u);
    }
  }
  return g;
}

vec<vec<pii>> rnd_wgraph(int n, int m, int lo = 1, int hi = inf<>, bool directed = false) {
  vec<vec<pii>> g(n);
  for (auto [u, v] : rnd_graph_edges(n, m)) {
    const int w = rnd<>(lo, hi);
    if (directed) {
      if (rnd<>(0, 1)) {
        swap(u, v);
      }
      g[u].eb(v, w);
    } else {
      g[u].eb(v, w);
      g[v].eb(u, w);
    }
  }
  return g;
}