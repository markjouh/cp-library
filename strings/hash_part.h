mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll mod = (1ll << 61) - 1;
const ll base = uniform_int_distribution<ll>(999, mod - 999)(rng);

vl pwb = {1};

struct hsh {
    ll val;
    int len;

    hsh(ll x = 0, int y = 0) : val(x), len(y) {}

    hsh operator+(hsh b) {
        while (sz(pwb) - 1 < b.len) {
            pwb.pb(__int128_t(pwb.back()) * base % mod);
        }
        return hsh(__int128_t(val) * pwb[b.len] + b.val % mod, len + b.len);
    }

    bool operator==(hsh b) {
        return val == b.val && len == b.len;
    }
};
