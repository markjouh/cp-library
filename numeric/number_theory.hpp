/* A standard prime sieve and number theory helpers.
 * `sieve(N)`: O(N * log(log(N)))
 * `factor(k)`: O(log(k)) if sieve is run up to k, O(sqrt(k) / log(k)) otherwise
 * `gen_divisors(k)`: O(#divisors), bounded by ~cbrt(k)
 */

#pragma once

namespace number_theory {

vector<int> mn_fac, primes;

void sieve(int n) {
    mn_fac.resize(n + 1);
    for (int i = 2; i <= n; i++) {
        if (!mn_fac[i]) {
            mn_fac[i] = i;
            primes.push_back(i);
            for (ll j = 1ll * i * i; j <= n; j += i) {
                if (!mn_fac[j]) {
                    mn_fac[j] = i;
                }
            }
        }
    }
}

vector<pair<int, int>> factor(int num) {
    vector<pair<int, int>> res;

    if (num <= sz(mn_fac) - 1) {
        while (num > 1) {
            int fac = mn_fac[num];
            res.emplace_back(fac, 0);
            while (num % fac == 0) {
                num /= fac;
                res.back().second++;
            }
        }
        return res;
    }

    for (int p : primes) {
        if (1ll * p * p > num) {
            break;
        }
        int exp = 0;
        while (num % p == 0) {
            num /= p;
            exp++;
        }
        if (exp) {
            res.emplace_back(p, exp);
        }
    }
    if (num > 1) {
        res.emplace_back(num, 1);
    }
    return res;
}

vector<int> gen_divisors(vector<pair<int, int>> prime_facs) {
    vector<int> res = {1};
    for (auto [p, exp] : prime_facs) {
        const int prev_layer = sz(res);
        int coeff = 1;
        for (int i = 0; i < exp; i++) {
            coeff *= p;
            for (int j = 0; j < prev_layer; j++) {
                res.push_back(coeff * res[j]);
            }
        }
    }
    return res;
}
};
