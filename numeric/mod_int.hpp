#pragma once

template<int MOD> struct mod_int {
    int v;
 
    mod_int(ll x = 0) : v(int(-MOD < x && x < MOD ? x : x % MOD) + (x < 0) * MOD) {}
 
    friend mod_int pow(mod_int base, int exp) {
        mod_int res = 1;
        while (exp) {
            if (exp & 1) {
                res *= base;
            }
            base *= base;
            exp >>= 1;
        }
        return res;
    }
 
    mod_int &operator+=(mod_int b) {
        if ((v += b.v) >= MOD) {
            v -= MOD;
        }
        return *this;
    }
 
    mod_int &operator-=(mod_int b) {
        if ((v -= b.v) < 0) {
            v += MOD;
        }
        return *this;
    }
 
    mod_int &operator*=(mod_int b) {
        v = int(1ll * v * b.v % MOD);
        return *this;
    }
 
    mod_int &operator/=(mod_int b) {
        v = int(1ll * v * pow(b, MOD - 2).v % MOD);
        return *this;
    }
 
    friend mod_int operator+(mod_int a, mod_int b) {
        return a += b;
    }
 
    friend mod_int operator-(mod_int a, mod_int b) {
        return a -= b;
    }
 
    friend mod_int operator*(mod_int a, mod_int b) {
        return a *= b;
    }
 
    friend mod_int operator/(mod_int a, mod_int b) {
        return a /= b;
    }
 
    friend ostream &operator<<(ostream &os, mod_int a) {
        return os << a.v;
    }
};
