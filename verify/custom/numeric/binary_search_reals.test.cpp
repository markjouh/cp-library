#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../../misc/template.h"
#include "../../../numeric/binsearch_reals.h"

const int T = 1e6;
const double MXV = 1e12, ERR = 1e-3;

void test() {
    // Search for exact double value, should have no ERR
    const double t1 = rand_doub(1e100);
    double left = bsmax_reals(0, 1e100, [&](double x) {
        return x <= t1;
    });
    assert(left == t1);
    double right = bsmin_reals(0, 1e100, [&](double x) {
        return x >= t1;
    });
    assert(right == t1);

    // Try computing sqrt
    const double t2 = rand_doub(MXV);
    double sqrt_val = bsmax_reals(0, MXV, [&](double x) {
        return x * x <= t2;
    });
    double sqrt_prod = sqrt_val * sqrt_val;
    assert(sqrt_prod <= t2 && t2 - sqrt_prod < ERR);

    // Try computing cbrt
    const double t3 = rand_doub(MXV);
    double cbrt_val = bsmax_reals(0, MXV, [&](double x) {
        return x * x * x <= t3;
    });
    double cbrt_prod = cbrt_val * cbrt_val * cbrt_val;
    assert(cbrt_prod <= t3 && t3 - cbrt_prod < ERR);
}

int main() {
    for (int i = 0; i < T; i++) {
        test();
    }
    cerr << "Tests passed\n";

    int a, b;
    cin >> a >> b;
    cout << a + b << '\n';
}