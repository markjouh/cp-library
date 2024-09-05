#pragma once

#include <type_traits>

mt19937_64 rng_64(chrono::steady_clock::now().time_since_epoch().count());

template <class T>
T rnd(T lo, T hi) {
  static_assert(is_arithmetic_v<T>, "Invalid type for rnd()");
  if constexpr (is_integral_v<T>) {
    return uniform_int_distribution<T>(lo, hi)(rng_64);
  } else {
    return uniform_real_distribution<T>(lo, hi)(rng_64);
  }
}

template <class T>
constexpr T def_val() {
  if constexpr (is_floating_point_v<T>) {
    return 1;
  } else {
    return inf<T>;
  }
}

/* ---- Boolean wrapper ---- */

bool randbool() {
  return rnd<int>(0, 1);
}

/* ---- Int wrappers ---- */

int randint(int lo, int hi) {
  return rnd<int>(lo, hi);
}

int randint(int hi) {
  return randint(0, hi - 1);
}

int randint() {
  return randint(inf<int>);
}

/* ---- Long long wrappers ---- */

ll randlong(ll lo, ll hi) {
  return rnd<ll>(lo, hi);
}

ll randlong(ll hi) {
  return randlong(0, hi);
}

ll randlong() {
  return randlong(inf<ll>);
}

/* ---- Double wrappers ---- */

double randdoub(double lo, double hi) {
  return rnd<double>(lo, hi);
}

double randdoub(double hi) {
  return randdoub(0, hi);
}

double randdoub() {
  return randdoub(1);
}

/* ---- Vector wrappers ---- */

template <class T>
vec<T> randvec(int n, T lo, T hi) {
  vec<T> res(n);
  rep(i, n) {
    res[i] = rnd<T>(lo, hi);
  }
  return res;
}

template <class T>
vec<T> randvec(int n, T hi) {
  return randvec<T>(n, 0, hi);
}

template <class T>
vec<T> randvec(int n) {
  return randvec<T>(n, def_val<T>());
}

/* ---- Array wrappers ---- */

template <class T, size_t N>
array<T, N> randarr(T lo, T hi) {
  array<T, N> res;
  rep(i, N) {
    res[i] = rnd<T>(lo, hi);
  }
  return res;
}

template <class T, size_t N>
array<T, N> randarr(T hi) {
  return randarr<T, N>(0, hi);
}

template <class T, size_t N>
array<T, N> randarr() {
  return randarr<T, N>(def_val<T>());
}

/* ---- Graph generation from Prufer sequences ---- */

vec<pii> gen_tree_edges(int n) {
  const vec<int> prufer = randvec(n - 2, 0, n - 1);
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

vec<pii> gen_graph_edges(int n, int m) {
  assert(m >= n - 1 && m <= 1ll * n * (n - 1) / 2);

  auto res = gen_tree_edges(n);
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

vec<vec<int>> gen_graph(int n, int m, bool directed = false) {
  vec<vec<int>> g(n);
  for (auto [u, v] : gen_graph_edges(n, m)) {
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

vec<vec<pii>> gen_w_graph(int n, int m, int lo = 1, int hi = inf<>, bool directed = false) {
  vec<vec<pii>> g(n);
  for (auto [u, v] : gen_graph_edges(n, m)) {
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