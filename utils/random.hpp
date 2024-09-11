#pragma once

#include <type_traits>

// ----------------------------------------------------
// Basic random data generation
// ----------------------------------------------------

mt19937_64 rngEngine(chrono::steady_clock::now().time_since_epoch().count());

template <class T>
T myRand(T lo, T hi) {
  static_assert(is_arithmetic_v<T>, "Invalid type for myRand()");
  if constexpr (is_integral_v<T>) {
    return uniform_int_distribution<T>(lo, hi)(rngEngine);
  } else {
    return uniform_real_distribution<T>(lo, hi)(rngEngine);
  }
}

template <class T>
constexpr T defaultVal() {
  if constexpr (is_floating_point_v<T>) {
    return 1;
  } else {
    return numeric_limits<T>::max() / 2;
  }
}

bool randBool() {
  return myRand<int>(0, 1);
}

int randInt(int lo, int hi) {
  return myRand<int>(lo, hi);
}

int randInt(int hi) {
  return randInt(0, hi - 1);
}

int randInt() {
  return randInt(defaultVal<int>());
}

long long randLong(long long lo, long long hi) {
  return myRand<long long>(lo, hi);
}

long long randLong(long long hi) {
  return randLong(0, hi);
}

long long randLong() {
  return randLong(defaultVal<long long>());
}

double randDoub(double lo, double hi) {
  return myRand<double>(lo, hi);
}

double randDoub(double hi) {
  return randDoub(0, hi);
}

double randDoub() {
  return randDoub(1);
}

template <class T>
vector<T> randVec(int n, T lo, T hi) {
  vector<T> res(n);
  for (int i = 0; i < n; i++) {
    res[i] = myRand<T>(lo, hi);
  }
  return res;
}

template <class T>
vector<T> randVec(int n, T hi) {
  return randVec<T>(n, 0, hi);
}

template <class T>
vector<T> randVec(int n) {
  return randVec<T>(n, defaultVal<T>());
}

template <class T, size_t N>
array<T, N> randArr(T lo, T hi) {
  array<T, N> res;
  for (int i = 0; i < N; i++) {
    res[i] = myRand<T>(lo, hi);
  }
  return res;
}

template <class T, size_t N>
array<T, N> randArr(T hi) {
  return randArr<T, N>(0, hi);
}

template <class T, size_t N>
array<T, N> randArr() {
  return randArr<T, N>(defaultVal<T>());
}

// ----------------------------------------------------
// Graph generation from Prufer sequences
// ----------------------------------------------------

vector<pair<int, int>> genTreeEdges(int n) {
  const vector<int> prufer = randVec(n - 2, 0, n - 1);
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

  int rootA = -1, rootB = -1;
  for (int i = 0; i < n; i++) {
    if (deg[i] == 1) {
      (rootA == -1 ? rootA : rootB) = i;
    }
  }
  res.emplace_back(rootA, rootB);

  return res;
}

vector<pair<int, int>> genGraphEdges(int n, int m) {
  assert(m >= n - 1 && m <= 1ll * n * (n - 1) / 2);

  auto res = genTreeEdges(n);
  set<pair<int, int>> have;
  for (auto [u, v] : res) {
    have.emplace(u, v);
  }

  while (ssize(res) < m) {
    int u = randInt(n), v = randInt(n - 1);
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

vector<vector<int>> genGraph(int n, int m, bool dir = false) {
  vector<vector<int>> g(n);
  for (auto [u, v] : genGraphEdges(n, m)) {
    if (dir) {
      if (randBool()) {
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

vector<vector<pair<int, int>>> genWeightedGraph(int n, int m, int lo = 1, int hi = defaultVal<int>(), bool dir = false) {
  vector<vector<pair<int, int>>> g(n);
  for (auto [u, v] : genGraphEdges(n, m)) {
    const int w = randInt(lo, hi);
    if (dir) {
      if (randBool()) {
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