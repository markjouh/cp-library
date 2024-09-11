#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../boilerplate.hpp"
#include "../../../numeric/binary_search_reals.hpp"

const int TESTS = 1e6;
const double MXV = 1e12, ERROR = 1e-3;

void test() {
  // Search for exact double value, should have no error
  const double t1 = randDoub(inf<double>);
  double left = bsmaxReals(0, inf<double>, [&](double x) {
    return x <= t1;
  });
  assert(left == t1);
  double right = bsminReals(0, inf<double>, [&](double x) {
    return x >= t1;
  });
  assert(right == t1);

  // Try computing sqrt
  const double t2 = randDoub(MXV);
  double sqrtVal = bsmaxReals(0, MXV, [&](double x) {
    return x * x <= t2;
  });
  double sqrtProd = sqrtVal * sqrtVal;
  assert(sqrtProd <= t2 && t2 - sqrtProd < ERROR);

  // Try computing cbrt
  const double t3 = randDoub(MXV);
  double cbrtVal = bsmaxReals(0, MXV, [&](double x) {
    return x * x * x <= t3;
  });
  double cbrtProd = cbrtVal * cbrtVal * cbrtVal;
  assert(cbrtProd <= t3 && t3 - cbrtProd < ERROR);
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