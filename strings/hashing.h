// https://rng-58.blogspot.com/2017/02/hashing-and-probability-of-collision.html
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll mod = (1ll << 61) - 1;
const ll base = uniform_int_distribution<ll>(1e3, mod - 1e3)(rng);

vector<ll> pow_b = {1};

struct Hash {
    ll val;
    int len;

    Hash(ll x, int y) : val(x), len(y) {}

    Hash operator+(Hash b) {
        return Hash((i128(val) * pow_b[b.len] + b.val) % mod, len + b.len);
    }

    bool operator==(Hash b) {
        return val == b.val && len == b.len;
    }
};

struct StringHash {
    int len;
    vector<ll> hash;

    StringHash(string s) : len(sz(s)), hash(len + 1) {
        rep(i, len) {
            hash[i + 1] = (i128(hash[i]) * base + s[i]) % mod;
        }
        while (sz(pow_b) <= len) {
            pow_b.push_back(i128(pow_b.back()) * base % mod);
        }
    }

    Hash get(int l, int r) {
        return Hash(((hash[r] - i128(hash[l]) * pow_b[r - l]) % mod + mod) % mod, r - l);
    }

    Hash get() {
        return get(0, sz(hash) - 1);
    }
};
