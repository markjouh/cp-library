#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../boilerplate.hpp"
#include "../../../utils/random.hpp"
#include "../../../numeric/binary_search_reals.hpp"

const int TESTS = 1e6;
const double MXV = 1e12, ERROR = 1e-3;

void test() {
  // Search for exact double value, should have no error
  const double t1 = randreal<double>(inf<double>);
  double left = bsmax_reals(0, inf<double>, [&](double x) {
    return x <= t1;
  });
  assert(left == t1);
  double right = bsmin_reals(0, inf<double>, [&](double x) {
    return x >= t1;
  });
  assert(right == t1);

  // Try computing sqrt
  const double t2 = randreal<double>(MXV);
  double sqrt_val = bsmax_reals(0, MXV, [&](double x) {
    return x * x <= t2;
  });
  double sqrt_res = sqrt_val * sqrt_val;
  assert(sqrt_res <= t2 && t2 - sqrt_res < ERROR);

  // Try computing cbrt
  const double t3 = randreal<double>(MXV);
  double cbrt_val = bsmax_reals(0, MXV, [&](double x) {
    return x * x * x <= t3;
  });
  double cbrt_res = cbrt_val * cbrt_val * cbrt_val;
  assert(cbrt_res <= t3 && t3 - cbrt_res < ERROR);
}

int main() {
  for (int i = 0; i < TESTS; i++) {
    test();
  }
  cerr << "Tests passed\n";

  int a, b;
  cin >> a >> b;
  cout << a + b << '\n';
}