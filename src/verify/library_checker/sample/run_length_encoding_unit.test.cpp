#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../../template/template.h"
#include "../../../strings/run_length_encoding.h"

template <class T>
vector<pair<typename T::value_type, int>> brute(const T &a) {
  using V = typename T::value_type;
  vector<pair<V, int>> res;
  for (auto x : a) {
    if (res.empty() || res.back().first != x) {
      res.emplace_back(x, 1);
    } else {
      res.back().second++;
    }
  }
  return res;
}

template <class T>
void check(const T &a) {
  auto got = rle(a);
  auto want = brute(a);
  assert(got == want);
}

int main() {
  mt19937_64 rng(12345);

  // Single element
  check(string("a"));
  check(vector<int>{0});
  check(vector<int>{-1});
  check(vector<int>{INT_MAX});

  // Two elements
  check(string("aa"));
  check(string("ab"));

  // All same
  for (int n : {2, 3, 5, 10, 100, 1000}) {
    check(string(n, 'x'));
    check(vector<int>(n, 42));
  }

  // All different
  for (int n : {2, 3, 5, 26}) {
    string s;
    for (int i = 0; i < n; i++) s += char('a' + i);
    check(s);
  }
  {
    vector<int> v(1000);
    iota(v.begin(), v.end(), -500);
    check(v);
  }

  // Alternating runs
  for (int n : {10, 100, 1000}) {
    vector<int> v;
    for (int i = 0; i < n; i++) v.push_back(i & 1);
    check(v);
  }

  // Long runs separated
  for (int run_len : {1, 2, 5, 100}) {
    string s;
    for (int k = 0; k < 10; k++) {
      s += string(run_len, char('a' + (k % 26)));
    }
    check(s);
  }

  // Random strings
  for (int iter = 0; iter < 2000; iter++) {
    int n = 1 + int(rng() % 200);
    int alpha = 1 + int(rng() % 5);
    string s(n, 'a');
    for (auto &c : s) c = char('a' + rng() % alpha);
    check(s);
  }

  // Random int vectors
  for (int iter = 0; iter < 2000; iter++) {
    int n = 1 + int(rng() % 200);
    int alpha = 1 + int(rng() % 10);
    vector<int> v(n);
    for (auto &x : v) x = int(rng() % alpha);
    check(v);
  }

  // Random with wide range (duplicates rare)
  for (int iter = 0; iter < 200; iter++) {
    int n = 1 + int(rng() % 500);
    vector<int> v(n);
    for (auto &x : v) x = int(rng());
    check(v);
  }

  // Types: long long, char
  check(vector<long long>{1LL << 40, 1LL << 40, -1LL << 40});
  check(vector<char>{1, 1, 2, 2, 2, 3});

  int a, b;
  cin >> a >> b;
  cout << a + b << '\n';
}
