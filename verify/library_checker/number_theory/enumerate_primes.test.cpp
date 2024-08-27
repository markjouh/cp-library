#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"

#include "../../boilerplate.hpp"
#include "../../../numeric/number_theory.hpp"

using namespace number_theory;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    sieve(n);
    cout << sz(primes) << ' ';
    vector<int> res;
    for (int i = b; i < sz(primes); i += a) {
        res.push_back(primes[i]);
    }
    cout << sz(res) << '\n';
    for (int x : res) {
        cout << x << ' ';
    }
    cout << '\n';
}