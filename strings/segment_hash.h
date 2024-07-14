mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll mod = (1ll << 61) - 1;
const ll base = uniform_int_distribution<ll>(999, mod - 999)(rng);

vl pwb = {1};

struct seg_hash {
    ll val;
    int len;

    seg_hash(ll x = 0, int y = 0) : val(x), len(y) {}

    seg_hash operator+(seg_hash b) {
        while (sz(pwb) - 1 < b.len) {
            pwb.pb(i128(pwb.back()) * base % mod);
        }
        return seg_hash(i128(val) * pwb[b.len] + b.val % mod, len + b.len);
    }

    bool operator==(seg_hash b) {
        return val == b.val && len == b.len;
    }
};
