#pragma once

#include <type_traits>
#include <random>

mt19937_64 rng_engine(chrono::steady_clock::now().time_since_epoch().count());

// Core of random data generation
template <class T>
T my_rand(T lo, T hi) {
    static_assert(is_arithmetic_v<T>, "Invalid type for my_rand()");
    if constexpr (is_integral_v<T>) {
        return uniform_int_distribution<T>(lo, hi)(rng_engine);
    } else {
        return uniform_real_distribution<T>(lo, hi)(rng_engine);
    }
}

// Default value - uniform [0, 1] for reals
template <class T>
constexpr T default_val() {
    if constexpr (is_floating_point_v<T>) {
        return 1;
    } else {
        return numeric_limits<T>::max() / 2;
    }
}

bool rand_bool() {
    return my_rand<int>(0, 1);
}

int rand_int(int lo, int hi) {
    return my_rand<int>(lo, hi);
}

int rand_int(int hi) {
    return rand_int(0, hi - 1);
}

int rand_int() {
    return rand_int(default_val<int>());
}

long long rand_long(long long lo, long long hi) {
    return my_rand<long long>(lo, hi);
}

long long rand_long(long long hi) {
    return rand_long(0, hi);
}

long long rand_long() {
    return rand_long(default_val<long long>());
}

double rand_doub(double lo, double hi) {
    return my_rand<double>(lo, hi);
}

double rand_doub(double hi) {
    return rand_doub(0, hi);
}

double rand_doub() {
    return rand_doub(1);
}

string rand_str(int n, int k) {
    string s(n, ' ');
    for (int i = 0; i < n; i++) {
        s[i] = char('a' + rand_int(k));
    }
    return s;
}

template <class T>
vector<T> rand_vec(int n, T lo, T hi) {
    vector<T> res(n);
    for (int i = 0; i < n; i++) {
        res[i] = my_rand<T>(lo, hi);
    }
    return res;
}

template <class T>
vector<T> rand_vec(int n, T hi) {
    return rand_vec<T>(n, 0, hi);
}

template <class T>
vector<T> rand_vec(int n) {
    return rand_vec<T>(n, default_val<T>());
}

template <class T, size_t N>
array<T, N> rand_arr(T lo, T hi) {
    array<T, N> res;
    for (int i = 0; i < int(N); i++) {
        res[i] = my_rand<T>(lo, hi);
    }
    return res;
}

template <class T, size_t N>
array<T, N> rand_arr(T hi) {
    return rand_arr<T, N>(0, hi);
}

template <class T, size_t N>
array<T, N> rand_arr() {
    return rand_arr<T, N>(default_val<T>());
}

// Uniformly generate trees from random Prufer sequences
vector<pair<int, int>> gen_tree_edges(int n) {
    const vector<int> prufer = rand_vec(n - 2, 0, n - 1);
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

    int x = -1, y = -1;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 1) {
            (x == -1 ? x : y) = i;
        }
    }
    res.emplace_back(x, y);

    return res;
}

// Generate arbitrary graphs by adding extra edges to a spanning tree (probably not uniform, but good enough)
vector<pair<int, int>> gen_graph_edges(int n, int m) {
    assert(m >= n - 1 && m <= 1ll * n * (n - 1) / 2);

    auto res = gen_tree_edges(n);
    set<pair<int, int>> have;
    for (auto [u, v] : res) {
        have.emplace(u, v);
    }

    while (ssize(res) < m) {
        int u = rand_int(n), v = rand_int(n - 1);
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

vector<vector<int>> gen_graph(int n, int m, bool directed = false) {
    vector<vector<int>> g(n);
    for (auto [u, v] : gen_graph_edges(n, m)) {
        if (directed) {
            if (rand_bool()) {
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

vector<vector<pair<int, int>>> gen_weighted_graph(int n, int m, int lo = 1, int hi = default_val<int>(), bool directed = false) {
    vector<vector<pair<int, int>>> g(n);
    for (auto [u, v] : gen_graph_edges(n, m)) {
        const int w = rand_int(lo, hi);
        if (directed) {
            if (rand_bool()) {
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