mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll mod = (1ll << 61) - 1;
const ll base = uniform_int_distribution<ll>(999, mod - 999)(rng);

vl pow_b = {1};

struct StringHash {
    vl h;

    StringHash(string s = "") {
        h.resize(sz(s) + 1);
        rep(i, sz(s)) {
            h[i + 1] = (i128(h[i]) * base + s[i]) % mod;
        }
        while (sz(pow_b) - 1 < sz(s)) {
            pow_b.pb(i128(pow_b.back()) * base % mod);
        }
    }

    ll get(int l, int r) {
        return ((h[r] - i128(h[l]) * pow_b[r - l]) % mod + mod) % mod;
    }
};
