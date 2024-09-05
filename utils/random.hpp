#pragma once

#include <type_traits>

mt19937_64 rng_64(chrono::steady_clock::now().time_since_epoch().count());

// ----------------------------------------------------
// Section: Basic random data generation
// ----------------------------------------------------

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
    return numeric_limits<T>::max() / 2;
  }
}

// ----------------------------------------------------
//  => Bool wrapper
// ----------------------------------------------------

bool randbool() {
  return rnd<int>(0, 1);
}

// ----------------------------------------------------
//  => Int wrappers
// ----------------------------------------------------

int randint(int lo, int hi) {
  return rnd<int>(lo, hi);
}

int randint(int hi) {
  return randint(0, hi - 1);
}

int randint() {
  return randint(def_val<int>());
}

// ----------------------------------------------------
//  => Long long wrappers
// ----------------------------------------------------

long long randlong(long long lo, long long hi) {
  return rnd<long long>(lo, hi);
}

long long randlong(long long hi) {
  return randlong(0, hi);
}

long long randlong() {
  return randlong(def_val<long long>());
}

// ----------------------------------------------------
//  => Double wrappers
// ----------------------------------------------------

double randdoub(double lo, double hi) {
  return rnd<double>(lo, hi);
}

double randdoub(double hi) {
  return randdoub(0, hi);
}

double randdoub() {
  return randdoub(1);
}

// ----------------------------------------------------
//  => Vector wrappers
// ----------------------------------------------------

template <class T>
vector<T> randvec(int n, T lo, T hi) {
  vector<T> res(n);
  for (int i = 0; i < n; i++) {
    res[i] = rnd<T>(lo, hi);
  }
  return res;
}

template <class T>
vector<T> randvec(int n, T hi) {
  return randvec<T>(n, 0, hi);
}

template <class T>
vector<T> randvec(int n) {
  return randvec<T>(n, def_val<T>());
}

// ----------------------------------------------------
//  => Array wrappers
// ----------------------------------------------------

template <class T, size_t N>
array<T, N> randarr(T lo, T hi) {
  array<T, N> res;
  for (int i = 0; i < N; i++) {
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

// ----------------------------------------------------
// Section: Graph generation from Prufer sequences
// ----------------------------------------------------

vector<pair<int, int>> gen_tree_edges(int n) {
  const vector<int> prufer = randvec(n - 2, 0, n - 1);
  vector<int> deg(n, 1);
  for (int x : prufer) {
    deg[x]++;
  }
  priority_queue<int, vector<int>, greater<>> leaves;
  for (int i = 0; i < n; i++) {
    if (deg[i] == 1) {
      leaves.push(i);
    }
  }

  vector<pair<int, int>> res;
  res.reserve(n - 1);
  for (int v : prufer) {
    int u = leaves.top();
    leaves.pop();

    res.push_back(minmax(u, v));
    deg[u]--, deg[v]--;

    if (deg[v] == 1) {
      leaves.push(v);
    }
  }

  int r1 = -1, r2 = -1;
  for (int i = 0; i < n; i++) {
    if (deg[i] == 1) {
      (r1 == -1 ? r1 : r2) = i;
    }
  }
  res.emplace_back(r1, r2);

  return res;
}

vector<pair<int, int>> gen_graph_edges(int n, int m) {
  assert(m >= n - 1 && m <= 1ll * n * (n - 1) / 2);

  auto res = gen_tree_edges(n);
  set<pair<int, int>> have;
  for (auto [u, v] : res) {
    have.emplace(u, v);
  }

  while (ssize(res) < m) {
    int u = randint(n), v = randint(n - 1);
    v += v >= u;
    if (u > v) {
      swap(u, v);
    }
    if (!have.count({u, v})) {
      res.emplace_back(u, v);
      have.emplace(u, v);
    }
  }
  return res;
}

// ----------------------------------------------------
//  => Adjacency list wrappers
// ----------------------------------------------------

vector<vector<int>> gen_graph(int n, int m, bool dir = false) {
  vector<vector<int>> g(n);
  for (auto [u, v] : gen_graph_edges(n, m)) {
    if (dir) {
      if (randbool()) {
        swap(u, v);
      }
      g[u].push_back(v);
    } else {
      g[u].push_back(v);
      g[v].push_back(u);
    }
  }
  return g;
}

vector<vector<pair<int, int>>> gen_w_graph(int n, int m, int lo = 1, int hi = def_val<int>(), bool dir = false) {
  vector<vector<pair<int, int>>> g(n);
  for (auto [u, v] : gen_graph_edges(n, m)) {
    const int w = randint(lo, hi);
    if (dir) {
      if (randbool()) {
        swap(u, v);
      }
      g[u].emplace_back(v, w);
    } else {
      g[u].emplace_back(v, w);
      g[v].emplace_back(u, w);
    }
  }
  return g;
}