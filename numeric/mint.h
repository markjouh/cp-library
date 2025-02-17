template <int MOD>
struct mint {
    int v;
 
    mint(ll x = 0) : v(int(-MOD < x && x < MOD ? x : x % MOD) + (x < 0) * MOD) {}
 
    friend mint pow(mint base, ll exp) {
        mint res = 1;
        while (exp) {
            if (exp & 1) {
                res *= base;
            }
            base *= base;
            exp >>= 1;
        }
        return res;
    }

    mint &operator+=(mint b) {
        v = v + b.v - (v + b.v >= MOD) * MOD;
        return *this;
    }
    mint &operator-=(mint b) {
        v = v - b.v + (v < b.v) * MOD;
        return *this;
    }
    mint &operator*=(mint b) {
        v = int(1ll * v * b.v % MOD);
        return *this;
    }
    mint &operator/=(mint b) {
        v = int(1ll * v * pow(b, MOD - 2).v % MOD);
        return *this;
    }
    friend mint operator+(mint a, mint b) {
        return a += b;
    }
    friend mint operator-(mint a, mint b) {
        return a -= b;
    }
    friend mint operator*(mint a, mint b) {
        return a *= b;
    }
    friend mint operator/(mint a, mint b) {
        return a /= b;
    }
    friend ostream &operator<<(ostream &os, mint a) {
        return os << a.v;
    }
};

// using mi = mint<int(1e9 + 7)>;
// using mi = mint<998244353>;

// vector<mi> fact, inv_fact;

// void gen_fact(int n) {
//     fact.resize(n + 1);
//     inv_fact.resize(n + 1);
//     fact[0] = fact[1] = inv_fact[0] = inv_fact[1] = 1;
//     for (int i = 2; i <= n; i++) {
//         fact[i] = fact[i - 1] * i;
//     }
//     inv_fact[n] = 1 / fact[n];
//     for (int i = n - 1; i >= 2; i--) {
//         inv_fact[i] = inv_fact[i + 1] * (i + 1);
//     }
// }

// mi nck(int n, int k) {
//     if (n < k || k < 0) {
//         return 0;
//     }
//     return fact[n] * inv_fact[k] * inv_fact[n - k];
// }