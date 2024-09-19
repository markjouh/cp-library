#pragma once

ll madd(ll a, ll b, ll mod) {
    return (a + b) % mod;
}

ll msub(ll a, ll b, ll mod) {
    return ((a - b) % mod + mod) % mod;
}

ll mmul(ll a, ll b, ll mod) {
    return (a % mod) * (b % mod) % mod;
}

ll binpow(ll base, ll exp, ll mod) {
  ll res = 1;
  while (exp) {
      if (exp & 1) {
          res = res * base % mod;
      }
      base = base * base % mod;
      exp >>= 1;
  }
  return res;
}

// Compute gcd and coefficients x, y such that ax + by = gcd(a, b)
ll extended_gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll g = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

// Compute mod inverse for any a coprime to mod
ll mod_inverse(ll a, ll mod) {
    ll x, y;
    ll g = extended_gcd(a, mod, x, y);
    if (g != 1) {
        return -1;
    } else {
        return (x % mod + mod) % mod;
    }
}