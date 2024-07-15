mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll MOD = (1ll << 61) - 1;
const ll B = uniform_int_distribution<ll>(999, MOD - 999)(rng);

vl pow_b = {1};

struct SegHash {
    ll val;
    int len;

    SegHash(ll x = 0, int y = 0) : val(x), len(y) {}

    SegHash operator+(SegHash b) {
        while (sz(pow_b) - 1 < b.len) {
            pow_b.pb(i128(pow_b.back()) * B % MOD);
        }
        return SegHash(i128(val) * pow_b[b.len] + b.val % MOD, len + b.len);
    }

    bool operator==(SegHash b) {
        return val == b.val && len == b.len;
    }
};
