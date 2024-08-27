#pragma once
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>

#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif

using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) int(size(x))

using ll = long long;
using db = double;

template<class T> bool ckmin(T &a, const T b) {
    return b < a ? a = b, 1 : 0;
}

template<class T> bool ckmax(T &a, const T b) {
    return b > a ? a = b, 1 : 0;
}

struct init_io {
    init_io() {
        cin.tie(0)->sync_with_stdio(0);
        cin.exceptions(cin.failbit);
        cout << setprecision(10) << fixed;
    }
} init_io_;