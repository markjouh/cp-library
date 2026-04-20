#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../../template/template.h"
#include "../../../numeric/binsearch_reals.h"

// For a monotone predicate f that is true for x <= t and false for x > t,
// bsmax_reals(lo, hi, f) should return the largest representable double in [lo, hi]
// with f(x) == true (or lo if f(lo) is false — actually lo is returned when no x satisfies).
//
// bsmin_reals is the mirror. Our implementation steps over bit-patterns of the double,
// so the result is the best double representation of the boundary.

int main() {
  mt19937_64 rng(777);

  // sqrt(2) — classic case
  {
    double r = bsmax_reals(0.0, 2.0, [](double x) { return x * x <= 2.0; });
    assert(abs(r - sqrt(2.0)) < 1e-15);
    // Adjacent bit pattern should cross the predicate.
    uint64_t bits = reinterpret_cast<uint64_t &>(r);
    double next;
    uint64_t next_bits = bits + 1;
    memcpy(&next, &next_bits, sizeof(next));
    assert(!(next * next <= 2.0));
  }

  // cbrt(10)
  {
    double r = bsmin_reals(0.0, 10.0, [](double x) { return x * x * x >= 10.0; });
    assert(abs(r - cbrt(10.0)) < 1e-14);
  }

  // Monotonic linear predicate: x <= 3.14
  {
    double target = 3.14;
    double lo_bound = bsmax_reals(-10.0, 10.0, [&](double x) { return x <= target; });
    assert(lo_bound <= target);
    assert(lo_bound == target || (nextafter(lo_bound, INFINITY) > target));
  }

  // Many random targets against a simple predicate x^2 >= t
  for (int iter = 0; iter < 500; iter++) {
    double t = double(rng() % 10000) / 100.0;  // [0, 100)
    double r = bsmin_reals(0.0, 100.0, [&](double x) { return x * x >= t; });
    double want = sqrt(t);
    assert(abs(r - want) < 1e-10 + 1e-10 * want);
    assert(r * r >= t || abs(r * r - t) < 1e-10);
  }

  // Boundary cases
  {
    // Predicate always true
    double r = bsmax_reals(0.0, 1.0, [](double) { return true; });
    assert(r >= 1.0 || abs(r - 1.0) < 1e-15);
    double r2 = bsmin_reals(0.0, 1.0, [](double) { return true; });
    assert(r2 <= 0.0 || abs(r2 - 0.0) < 1e-15);
  }

  // The implementation assumes same-sign non-negative endpoints (bit pattern
  // is monotone on non-negative doubles). Only test in that regime.

  // Small interval — should converge to the exact endpoint of the predicate
  {
    double r = bsmax_reals(0.5, 0.5000001, [](double x) { return x <= 0.5000001; });
    assert(r >= 0.5 && r <= 0.5000001 + 1e-15);
  }

  // Wider range stress (non-negative)
  for (int iter = 0; iter < 500; iter++) {
    double lo = double(rng() % 1000000) * 1.0;
    double hi = lo + 1.0 + double(rng() % 1000000) * 1.0;
    double t = lo + (hi - lo) * (double(rng() % 10000) / 10000.0);
    double r = bsmax_reals(lo, hi, [&](double x) { return x <= t; });
    assert(r <= t + 1e-9 * max(1.0, abs(t)));
    double r2 = bsmin_reals(lo, hi, [&](double x) { return x >= t; });
    assert(r2 >= t - 1e-9 * max(1.0, abs(t)));
  }

  // Precision: interval spanning 0 — tricky for bit representation
  {
    double r = bsmin_reals(0.0, 1.0, [](double x) { return x >= 0.0; });
    assert(r == 0.0);
  }

  // Root of x^3 - x - 1 in [1, 2] (plastic number) ~ 1.3247179...
  {
    double r = bsmin_reals(1.0, 2.0, [](double x) { return x * x * x - x - 1 >= 0; });
    const double expect = 1.3247179572447460;
    assert(abs(r - expect) < 1e-12);
  }

  int a, b;
  cin >> a >> b;
  cout << a + b << '\n';
}
