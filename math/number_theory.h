namespace nt {
    vi mn_fac, primes;

    void sieve(int n) {
        mn_fac.resize(n + 1);
        rep(i, 2, n + 1) {
            if (!mn_fac[i]) {
                mn_fac[i] = i;
                primes.pb(i);
                for (ll j = ll(i) * i; j <= n; j += i) {
                    if (!mn_fac[j]) {
                        mn_fac[j] = i;
                    }
                }
            }
        }
    }

    vpi fac(ll x) {
        vpi res;

        if (x <= sz(mn_fac) - 1) {
            while (x > 1) {
                int f = mn_fac[x];
                res.eb(f, 0);
                while (x % f == 0) {
                    x /= f;
                    res.back().se++;
                }
            }
            return res;
        }

        for (int p : primes) {
            if (ll(p) * p > x) {
                break;
            }
            int e = 0;
            while (x % p == 0) {
                x /= p;
                e++;
            }
            if (e) {
                res.eb(p, e);
            }
        }
        if (x > 1) {
            res.eb(x, 1);
        }
        return res;
    }

    vl gen_div(vpi p_fac) {
        vl res = {1};
        for (auto [p, e] : p_fac) {
            int n = sz(res);
            ll mul = 1;
            rep(i, e) {
                mul *= p;
                rep(j, n) {
                    res.pb(res[j] * mul);
                }
            }
        }
        return res;
    }
};
