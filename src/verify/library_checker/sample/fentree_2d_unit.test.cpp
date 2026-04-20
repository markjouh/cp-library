#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../../template/template.h"
#include "../../../datastructures/fenwick_tree/fentree_2d.h"

long long brute_rect(const vector<vector<long long>> &a, int r1, int c1, int r2, int c2) {
  long long s = 0;
  for (int r = r1; r <= r2; r++)
    for (int c = c1; c <= c2; c++)
      s += a[r][c];
  return s;
}

long long brute_prefix(const vector<vector<long long>> &a, int r, int c) {
  if (r < 0 || c < 0) return 0;
  return brute_rect(a, 0, 0, r, c);
}

void stress(int n, int m, int iters, uint64_t seed) {
  mt19937_64 rng(seed);
  Fentree2D<long long> ft(n, m);
  vector<vector<long long>> a(n, vector<long long>(m, 0));

  for (int i = 0; i < iters; i++) {
    int op = int(rng() % 3);
    if (op == 0) {
      int r = int(rng() % n), c = int(rng() % m);
      long long v = int64_t(rng() % 201) - 100;
      ft.add(r, c, v);
      a[r][c] += v;
    } else if (op == 1) {
      int r = int(rng() % n), c = int(rng() % m);
      assert(ft.sum(r, c) == brute_prefix(a, r, c));
    } else {
      int r1 = int(rng() % n), r2 = int(rng() % n);
      int c1 = int(rng() % m), c2 = int(rng() % m);
      if (r1 > r2) swap(r1, r2);
      if (c1 > c2) swap(c1, c2);
      assert(ft.sum(r1, c1, r2, c2) == brute_rect(a, r1, c1, r2, c2));
    }
  }
}

int main() {
  // Dimensions that exercise odd shapes
  stress(1, 1, 100, 1);
  stress(1, 10, 1000, 2);
  stress(10, 1, 1000, 3);
  stress(2, 2, 500, 4);
  stress(3, 5, 2000, 5);
  stress(5, 5, 5000, 6);
  stress(8, 13, 5000, 7);

  // Larger, fewer iterations to keep runtime tight
  stress(20, 30, 20000, 11);
  stress(50, 50, 10000, 12);
  stress(100, 100, 5000, 13);

  // Deterministic edge cases
  {
    Fentree2D<long long> ft(3, 3);
    ft.add(0, 0, 5);
    ft.add(1, 1, 7);
    ft.add(2, 2, 9);
    assert(ft.sum(2, 2) == 21);
    assert(ft.sum(0, 0) == 5);
    assert(ft.sum(1, 1) == 12);
    assert(ft.sum(0, 0, 1, 1) == 12);
    assert(ft.sum(1, 1, 2, 2) == 16);
    assert(ft.sum(0, 2, 0, 2) == 0);  // column 2 row 0 only
    assert(ft.sum(2, 0, 2, 2) == 9);  // row 2
  }

  // Add same cell many times
  {
    Fentree2D<long long> ft(5, 5);
    for (int i = 0; i < 1000; i++) ft.add(2, 3, 1);
    assert(ft.sum(2, 3) == 1000);
    assert(ft.sum(0, 0, 4, 4) == 1000);
    for (int i = 0; i < 500; i++) ft.add(2, 3, -1);
    assert(ft.sum(2, 3) == 500);
  }

  // Rectangle queries with degenerate bounds (single row or single column)
  {
    Fentree2D<long long> ft(10, 10);
    for (int r = 0; r < 10; r++)
      for (int c = 0; c < 10; c++)
        ft.add(r, c, r * 10 + c);
    for (int r = 0; r < 10; r++) {
      long long expect = 0;
      for (int c = 0; c < 10; c++) expect += r * 10 + c;
      assert(ft.sum(r, 0, r, 9) == expect);
    }
    for (int c = 0; c < 10; c++) {
      long long expect = 0;
      for (int r = 0; r < 10; r++) expect += r * 10 + c;
      assert(ft.sum(0, c, 9, c) == expect);
    }
  }

  // Negative values
  {
    Fentree2D<long long> ft(4, 4);
    ft.add(1, 1, -100);
    ft.add(2, 2, 50);
    assert(ft.sum(3, 3) == -50);
    assert(ft.sum(0, 0, 1, 1) == -100);
    assert(ft.sum(2, 2, 3, 3) == 50);
  }

  int a, b;
  cin >> a >> b;
  cout << a + b << '\n';
}
