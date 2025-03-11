namespace hashing {

mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());

const uint64_t MOD = (1ll << 61) - 1;
const uint64_t B = uniform_int_distribution<uint64_t>(0, MOD)(mt);

vector<uint64_t> pow_b = {1};

uint64_t add(uint64_t a, uint64_t b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
  return a;
}

uint64_t sub(uint64_t a, uint64_t b) {
  a += MOD - b;
  if (a >= MOD) {
    a -= MOD;
  }
  return a;
}

uint64_t mul(uint64_t a, uint64_t b) {
  uint64_t l1 = (uint32_t) a, h1 = a >> 32, l2 = (uint32_t) b, h2 = b >> 32;
  uint64_t l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
  uint64_t ret = (l & MOD) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
  ret = (ret & MOD) + (ret >> 61);
  ret = (ret & MOD) + (ret >> 61);
  return ret - 1;
}

struct SegHash {
  uint64_t val;
  int len;

  SegHash(uint64_t x, int y) : val(x), len(y) {}

  SegHash operator+(SegHash b) const {
    return SegHash(add(mul(val, pow_b[b.len]), b.val), len + b.len);
  }

  bool operator==(SegHash b) const {
    return val == b.val;
  }
};

struct RollingHash {
  int n;
  vector<uint64_t> h;

  template <class T>
  RollingHash(const T &s) : n(sz(s)), h(n + 1) {
    for (int i = 0; i < n; i++) {
      h[i + 1] = add(mul(h[i], B), s[i]);
    }
    int p = sz(pow_b);
    if (p < n + 1) {
      pow_b.resize(n + 1);
      for (int i = p; i <= n; i++) {
        pow_b[i] = mul(pow_b[i - 1], B);
      }
    }
  }

  SegHash get(int l, int r) const {
    assert(l < ++r);
    return SegHash(sub(h[r], mul(h[l], pow_b[r - l])), r - l);
  }

  SegHash get_all() const {
    return SegHash(h[n], n);
  }
};

} // namespace hashing