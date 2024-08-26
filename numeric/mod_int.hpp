#pragma once

const int MOD = 1000000007;
// const int MOD = 998244353;

struct mint {
    int v;
 
    mint(ll x = 0) : v(int(-MOD < x && x < MOD ? x : x % MOD) + (x < 0) * MOD) {}
 
    friend mint pow(mint base, int exp) {
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
        if ((v += b.v) >= MOD) {
            v -= MOD;
        }
        return *this;
    }
 
    mint &operator-=(mint b) {
        if ((v -= b.v) < 0) {
            v += MOD;
        }
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
