namespace number_theory {
    vi mn_fac, primes;

    void sieve(int n) {
        mn_fac.resize(n + 1);
        rep(i, 2, n + 1) {
            if (!mn_fac[i]) {
                mn_fac[i] = i;
                primes.pb(i);
                for (ll j = 1ll * i * i; j <= n; j += i) {
                    if (!mn_fac[j]) {
                        mn_fac[j] = i;
                    }
                }
            }
        }
    }

    vpi factor(int num) {
        vpi res;

        if (num <= sz(mn_fac) - 1) {
            while (num > 1) {
                int fac = mn_fac[num];
                res.eb(fac, 0);
                while (num % fac == 0) {
                    num /= fac;
                    res.back().se++;
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
                res.eb(p, exp);
            }
        }
        if (num > 1) {
            res.eb(num, 1);
        }
        return res;
    }

    vi gen_divs(vpi prime_facs) {
        vi res = {1};
        for (auto [p, exp] : prime_facs) {
            const int prev_layer = sz(res);
            int coeff = 1;
            rep(i, exp) {
                coeff *= p;
                rep(j, prev_layer) {
                    res.pb(coeff * res[j]);
                }
            }
        }
        return res;
    }
};
