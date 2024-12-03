#ifndef RANDOM_H
#define RANDOM_H

#include <cassert>
#include <chrono>
#include <queue>
#include <random>
#include <set>
#include <type_traits>

namespace cp_utils {

using namespace std;

using ll = long long;

mt19937_64 twister(chrono::steady_clock::now().time_since_epoch().count());

template <class T>
T unifint(T lo, T hi) {
    return uniform_int_distribution<T>(lo, hi)(twister);
}
template <class T>
T unifreal(T lo, T hi) {
    return uniform_real_distribution<T>(lo, hi)(twister);
}

uint32_t xorshift32_state = twister() % UINT_MAX;

uint32_t xorshift32() {
    uint32_t x = xorshift32_state;
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    return xorshift32_state = x;
}

int randint(int mod) {
    return xorshift32() % mod;
}
int randint(int lo, int hi) {
    return lo + (lo < hi ? randint(hi - lo) : 0);
}

string randstr(int n, int k) {
    string s(n, ' ');
    for (int i = 0; i < n; i++) {
        s[i] = char('a' + randint(k));
    }
    return s;
}

template <class T>
void randshuf(T l, T r) {
    shuffle(l, r, twister);
}

template <class T>
vector<T> randvec(int n, T lo, T hi) {
    vector<T> res(n);
    for (int i = 0; i < n; i++) {
        res[i] = unifint<T>(lo, hi);
    }
    return res;
}

template <class T>
vector<T> randvec(int n, T mod) {
    return randvec<T>(n, 0, mod - 1);
}

auto gen_tree_edges(int n) {
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

    int x = -1, y = -1;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 1) {
            (x == -1 ? x : y) = i;
        }
    }
    res.emplace_back(x, y);

    return res;
}

auto gen_graph_edges(int n, int m) {
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

auto gen_graph(int n, int m, bool dir = false) {
    vector<vector<int>> g(n);
    for (auto [u, v] : gen_graph_edges(n, m)) {
        if (dir) {
            if (randint(1)) {
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

auto gen_tree(int n, bool dir = false) {
    return gen_graph(n, n - 1, dir);
}

auto gen_weighted_graph(int n, int m, int min_w = 1, int max_w = 100, bool dir = false) {
    vector<vector<pair<int, int>>> g(n);
    for (auto [u, v] : gen_graph_edges(n, m)) {
        const int w = randint(min_w, max_w);
        if (dir) {
            if (randint(1)) {
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

auto gen_weighted_tree(int n, int min_w = 1, int max_w = 100, bool dir = false) {
    return gen_weighted_graph(n, n - 1, min_w, max_w, dir);
}

} // namespace cp_utils

#endif // RANDOM_H