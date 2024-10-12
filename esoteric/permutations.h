#pragma once

const ll fact[20] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 6227020800, 87178291200, 1307674368000, 20922789888000, 355687428096000, 6402373705728000, 121645100408832000};

ll perm_to_idx(const vector<int> &p) {
    const int n = sz(p);
    ll ans = 0;
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (p[j] < p[i]) {
                ans += fact[n - i - 1];
            }
        }
    }
    return ans;
}

auto idx_to_perm(int n, ll idx) {
    vector<int> vals(n);
    iota(all(vals), 1);

    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        int rank = idx / fact[n - i - 1];
        idx %= fact[n - i - 1];
        res[i] = vals[rank];
        vals.erase(begin(vals) + rank);
    }
    return res;
}