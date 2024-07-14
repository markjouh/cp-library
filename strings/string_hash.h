mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll mod = (1ll << 61) - 1;
const ll base = uniform_int_distribution<ll>(999, mod - 999)(rng);

vl pwb = {1};

struct str_hash {
    vl h;

    str_hash(string s = "") {
        h.resize(sz(s) + 1);
        rep(i, sz(s)) {
            h[i + 1] = (i128(h[i]) * base + s[i]) % mod;
        }
        while (sz(pwb) - 1 < sz(s)) {
            pwb.pb(i128(pwb.back()) * base % mod);
        }
    }

    ll get(int l, int r) {
        return ((h[r] - i128(h[l]) * pwb[r - l]) % mod + mod) % mod;
    }
};
