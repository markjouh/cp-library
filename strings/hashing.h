mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll MOD = (1ll << 61) - 1;
const ll B = uniform_int_distribution<ll>(0, MOD)(rng);

vector<ll> pow_b = {1};

struct hash_val {
    ll val;
    int len;

    hash_val(ll x, int y) : val(x), len(y) {}

    hash_val operator+(hash_val b) {
        return hash_val((__int128_t(val) * pow_b[b.len] + b.val) % MOD, len + b.len);
    }

    friend bool operator==(const hash_val a, const hash_val b) {
        return a.val == b.val && a.len == b.len;
    }
};

struct hash_string {
    int len;
    vector<ll> h;

    template <class T>
    hash_string(const T &s) : len(sz(s)), h(len + 1) {
        for (int i = 0; i < len; i++) {
            h[i + 1] = (__int128_t(h[i]) * B + s[i]) % MOD;
        }
        while (sz(pow_b) <= len) {
            pow_b.push_back(__int128_t(pow_b.back()) * B % MOD);
        }
    }

    hash_val get(int l, int r) {
        assert(l < ++r);
        return hash_val(((h[r] - __int128_t(h[l]) * pow_b[r - l]) % MOD + MOD) % MOD, r - l);
    }

    hash_val get() {
        return get(0, sz(h) - 2);
    }
};