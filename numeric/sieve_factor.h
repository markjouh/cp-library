#pragma once

vector<int> mn_factor, primes;

void sieve(int n) {
    mn_factor.resize(n + 1);
    for (int i = 2; i <= n; i++) {
        if (!mn_factor[i]) {
            mn_factor[i] = i;
            primes.push_back(i);
            for (ll j = 1ll * i * i; j <= n; j += i) {
                if (!mn_factor[j]) {
                    mn_factor[j] = i;
                }
            }
        }
    }
}

template <class T>
vector<pair<T, int>> factorize(T x) {
    vector<pair<T, int>> res;

    // O(log x) if sieved up to x
    if (x <= sz(mn_factor) - 1) {
        while (x > 1) {
            int y = mn_factor[x];
            res.emplace_back(y, 0);
            while (x % y == 0) {
                x /= y;
                res.back().second++;
            }
        }
        return res;
    }

    // O(sqrt x log x) otherwise, must have sieved to sqrt(x)
    for (int p : primes) {
        if (1ll * p * p > x) {
            break;
        }
        int exp = 0;
        while (x % p == 0) {
            x /= p;
            exp++;
        }
        if (exp) {
            res.emplace_back(p, exp);
        }
    }
    if (x > 1) {
        res.emplace_back(x, 1);
    }
    return res;
}

template <class T>
vector<T> gen_divisors(T x) {
    vector<T> res = {1};
    for (auto [p, exp] : factorize(x)) {
        const int old_size = sz(res);
        T coeff = 1;
        for (int i = 0; i < exp; i++) {
            coeff *= p;
            for (int j = 0; j < old_size; j++) {
                res.push_back(coeff * res[j]);
            }
        }
    }
    return res;
}