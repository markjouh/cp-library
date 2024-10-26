namespace hashing {

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll MOD = (1ll << 61) - 1;
const ll B = uniform_int_distribution<ll>(0, MOD)(rng);

vector<ll> pow_b = {1};

struct Hash {
    ll val;
    int len;

    Hash(ll x, int y) : val(x), len(y) {}

    Hash operator+(Hash b) {
        return Hash((__int128_t(val) * pow_b[b.len] + b.val) % MOD, len + b.len);
    }

    friend bool operator==(const Hash a, const Hash b) {
        return a.val == b.val && a.len == b.len;
    }
};

struct StringHash {
    int len;
    vector<ll> h;

    template <class T>
    StringHash(const T &s) : len(sz(s)), h(len + 1) {
        for (int i = 0; i < len; i++) {
            h[i + 1] = (__int128_t(h[i]) * B + s[i]) % MOD;
        }
        while (sz(pow_b) <= len) {
            pow_b.push_back(__int128_t(pow_b.back()) * B % MOD);
        }
    }

    Hash get(int l, int r) {
        assert(l < ++r);
        return Hash(((h[r] - __int128_t(h[l]) * pow_b[r - l]) % MOD + MOD) % MOD, r - l);
    }

    Hash get() {
        return get(0, sz(h) - 2);
    }
};
}

using hashing::Hash;
using hashing::StringHash;