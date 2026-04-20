#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../../template/template.h"
#include "../../../numeric/fraction.h"

using i128 = __int128_t;

int sgn(i128 x) { return (x > 0) - (x < 0); }

int brute_cmp(int64_t a, int64_t b, int64_t c, int64_t d) {
  if (b < 0) { a = -a; b = -b; }
  if (d < 0) { c = -c; d = -d; }
  return sgn(i128(a) * d - i128(c) * b);
}

int64_t gcd_(int64_t a, int64_t b) { return b == 0 ? a : gcd_(b, a % b); }

pair<int64_t, int64_t> brute_reduce(int64_t n, int64_t d) {
  assert(d != 0);
  if (d < 0) { n = -n; d = -d; }
  int64_t g = gcd_(n < 0 ? -n : n, d);
  return {n / g, d / g};
}

void check_cmp(Frac a, Frac b, int expect) {
  assert((a < b) == (expect < 0));
  assert((a > b) == (expect > 0));
  assert((a == b) == (expect == 0));
  assert((a != b) == (expect != 0));
  assert((a <= b) == (expect <= 0));
  assert((a >= b) == (expect >= 0));
}

void check_arith(int64_t na, int64_t da, int64_t nb, int64_t db) {
  Frac a(na, da), b(nb, db);

  Frac sum = a + b;
  Frac want_sum(na * db + nb * da, da * db);
  check_cmp(sum, want_sum, 0);

  Frac diff = a - b;
  Frac want_diff(na * db - nb * da, da * db);
  check_cmp(diff, want_diff, 0);

  Frac prod = a * b;
  Frac want_prod(na * nb, da * db);
  check_cmp(prod, want_prod, 0);

  if (nb != 0) {
    Frac quot = a / b;
    Frac want_quot(na * db, da * nb);
    check_cmp(quot, want_quot, 0);
  }

  Frac neg = -a;
  check_cmp(neg, Frac(-na, da), 0);

  Frac c = a;
  c += b;
  check_cmp(c, sum, 0);
  c = a;
  c -= b;
  check_cmp(c, diff, 0);
  c = a;
  c *= b;
  check_cmp(c, prod, 0);
  if (nb != 0) {
    c = a;
    c /= b;
    check_cmp(c, a / b, 0);
  }
}

int main() {
  mt19937_64 rng(99999);

  // Basic constructor and denominator sign normalization
  {
    Frac f(1, 2);
    assert(f.num == 1 && f.den == 2);
    Frac g(-1, 2);
    assert(g.num == -1 && g.den == 2);
    Frac h(1, -2);
    assert(h.num == -1 && h.den == 2);
    Frac i(-1, -2);
    assert(i.num == 1 && i.den == 2);
    Frac zero;
    assert(zero.num == 0 && zero.den == 1);
  }

  // Reduction
  {
    Frac f(6, 8);
    f.reduce();
    assert(f.num == 3 && f.den == 4);
    Frac g(-6, 8);
    g.reduce();
    assert(g.num == -3 && g.den == 4);
    Frac h(0, 5);
    h.reduce();
    assert(h.num == 0 && h.den == 1);
    Frac k(15, 5);
    k.reduce();
    assert(k.num == 3 && k.den == 1);
  }

  // Comparisons: known pairs
  check_cmp(Frac(1, 2), Frac(1, 3), 1);
  check_cmp(Frac(1, 3), Frac(1, 2), -1);
  check_cmp(Frac(1, 2), Frac(2, 4), 0);
  check_cmp(Frac(-1, 2), Frac(1, 2), -1);
  check_cmp(Frac(-1, 2), Frac(-1, 3), -1);
  check_cmp(Frac(0), Frac(0, 5), 0);

  // Large values near int64 range, comparisons via 128-bit
  {
    int64_t big = 1LL << 40;
    check_cmp(Frac(big, big + 1), Frac(big + 1, big + 2), -1);
    check_cmp(Frac(big, 1), Frac(big - 1, 1), 1);
  }

  // Output format
  {
    ostringstream os;
    os << Frac(3, 4);
    assert(os.str() == "3/4");
  }
  {
    ostringstream os;
    os << Frac(-3, 4);
    assert(os.str() == "-3/4");
  }

  // Random small arithmetic
  for (int iter = 0; iter < 5000; iter++) {
    int64_t na = int64_t(rng() % 40) - 20;
    int64_t da;
    do {
      da = int64_t(rng() % 40) - 20;
    } while (da == 0);
    int64_t nb = int64_t(rng() % 40) - 20;
    int64_t db;
    do {
      db = int64_t(rng() % 40) - 20;
    } while (db == 0);
    check_arith(na, da, nb, db);
  }

  // Random comparisons with moderate values
  for (int iter = 0; iter < 5000; iter++) {
    int64_t na = int64_t(rng() % 2001) - 1000;
    int64_t da;
    do {
      da = int64_t(rng() % 2001) - 1000;
    } while (da == 0);
    int64_t nb = int64_t(rng() % 2001) - 1000;
    int64_t db;
    do {
      db = int64_t(rng() % 2001) - 1000;
    } while (db == 0);
    Frac a(na, da), b(nb, db);
    int expect = brute_cmp(na, da, nb, db);
    check_cmp(a, b, expect);
  }

  // Random comparisons with large int64 (stress test 128-bit path)
  for (int iter = 0; iter < 5000; iter++) {
    int64_t mx = 1LL << 30;
    auto rand_range = [&](int64_t lo, int64_t hi) -> int64_t {
      return lo + int64_t(rng() % (hi - lo + 1));
    };
    int64_t na = rand_range(-mx, mx);
    int64_t da;
    do {
      da = rand_range(-mx, mx);
    } while (da == 0);
    int64_t nb = rand_range(-mx, mx);
    int64_t db;
    do {
      db = rand_range(-mx, mx);
    } while (db == 0);
    Frac a(na, da), b(nb, db);
    int expect = brute_cmp(na, da, nb, db);
    check_cmp(a, b, expect);
  }

  // Sort a sequence of fractions
  {
    vector<Frac> v;
    for (int n = -5; n <= 5; n++) {
      for (int d = 1; d <= 6; d++) {
        v.emplace_back(n, d);
      }
    }
    sort(v.begin(), v.end());
    for (int i = 1; i < (int)v.size(); i++) {
      assert(!(v[i] < v[i - 1]));
    }
  }

  // Zero handling
  {
    Frac zero(0, 5);
    Frac half(1, 2);
    check_cmp(zero + half, half, 0);
    check_cmp(half - half, zero, 0);
    check_cmp(zero * half, zero, 0);
    check_cmp(zero / half, zero, 0);
  }

  // Reduction via random
  for (int iter = 0; iter < 2000; iter++) {
    int64_t n = int64_t(rng() % 400001) - 200000;
    int64_t d;
    do {
      d = int64_t(rng() % 400001) - 200000;
    } while (d == 0);
    Frac f(n, d);
    f.reduce();
    auto [wn, wd] = brute_reduce(n, d);
    assert(f.num == wn && f.den == wd);
  }

  int a, b;
  cin >> a >> b;
  cout << a + b << '\n';
}
