/* Hashes strings according to the scheme described in rng-58's blog.
 * https://rng-58.blogspot.com/2017/02/hashing-and-probability-of-collision.html
 * `str_hash(S)`: O(|S|)
 * `str_hash::get(l, r)`: O(1), returns a hash object
 * `hash`: An object representing a substring. Can be joined with `+` and compared in O(1), but not split further.
 */

#pragma once

namespace hashing {

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll H_MOD = (1ll << 61) - 1;
const ll H_BASE = uniform_int_distribution<ll>(0, H_MOD)(rng);

vector<ll> pow_b = {1};

struct hash {
    ll val;
    int len;

    hash(ll x, int y) : val(x), len(y) {}

    hash operator+(hash b) {
        return hash((__int128_t(val) * pow_b[b.len] + b.val) % H_MOD, len + b.len);
    }

    bool operator==(hash b) {
        return val == b.val && len == b.len;
    }
};

struct str_hash {
    int len;
    vector<ll> hashes;

    template<class T> str_hash(const T &s) : len(sz(s)), hashes(len + 1) {
        for (int i = 0; i < len; i++) {
            hashes[i + 1] = (__int128_t(hashes[i]) * H_BASE + s[i]) % H_MOD;
        }
        while (sz(pow_b) <= len) {
            pow_b.push_back(__int128_t(pow_b.back()) * H_BASE % H_MOD);
        }
    }

    hash get(int l, int r) {
        return hash(((hashes[r] - __int128_t(hashes[l]) * pow_b[r - l]) % H_MOD + H_MOD) % H_MOD, r - l);
    }

    hash get() {
        return get(0, sz(hashes) - 1);
    }
};
}
