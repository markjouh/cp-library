#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"

#include "../../../template/template.h"
#include "../../../numeric/sieve_factor.h"

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  sieve(n);
  cout << ssize(primes) << ' ';
  vector<int> res;
  for (int i = b; i < ssize(primes); i += a) {
    res.push_back(primes[i]);
  }
  cout << ssize(res) << '\n';
  for (int x : res) {
    cout << x << ' ';
  }
  cout << '\n';
}