#pragma once

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll H_MOD = (1ll << 61) - 1;
const ll H_BASE = uniform_int_distribution<ll>(0, H_MOD)(rng);

vector<ll> pow_b = {1};

struct Hash {
    ll val;
    int len;

    Hash(ll x, int y) : val(x), len(y) {}

    Hash operator+(Hash b) {
        return Hash((__int128_t(val) * pow_b[b.len] + b.val) % H_MOD, len + b.len);
    }

    friend bool operator==(const Hash &a, const Hash &b) {
        return a.val == b.val && a.len == b.len;
    }
};

struct StringHash {
    int len;
    vector<ll> h;

    template <class T>
    StringHash(const T &s) : len(sz(s)), h(len + 1) {
        for (int i = 0; i < len; i++) {
            h[i + 1] = (__int128_t(h[i]) * H_BASE + s[i]) % H_MOD;
        }
        while (sz(pow_b) <= len) {
            pow_b.push_back(__int128_t(pow_b.back()) * H_BASE % H_MOD);
        }
    }

    Hash get(int l, int r) {
        r++;
        return Hash(((h[r] - __int128_t(h[l]) * pow_b[r - l]) % H_MOD + H_MOD) % H_MOD, r - l);
    }

    Hash get() {
        return get(0, sz(h) - 1);
    }
};