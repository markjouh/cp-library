#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../../template/template.h"
#include "../../../datastructures/chtholly_tree.h"

// Brute: plain vector, apply pointwise transform and iterate.

template <class F>
void brute_apply(vector<int> &a, int l, int r, F f) {
  for (int i = l; i <= r; i++) a[i] = f(a[i]);
}

void check_equal(ChthollyTree<int> &ct, const vector<int> &want) {
  vector<int> got(want.size(), INT_MIN);
  ct.traverse(0, ssize(want) - 1, [&](auto it) {
    for (int i = it->l; i <= it->r; i++) got[i] = it->val;
  });
  assert(got == want);
}

void check_traverse_tiling(ChthollyTree<int> &ct, int n, mt19937_64 &rng, int trials) {
  // traverse should visit segments whose [l..r] exactly tile the queried range
  for (int t = 0; t < trials; t++) {
    int l = int(rng() % n);
    int r = l + int(rng() % (n - l));
    int cursor = l;
    vector<pair<int, int>> segs;
    ct.traverse(l, r, [&](auto it) {
      segs.emplace_back(it->l, it->r);
    });
    // After traverse, the segments must tile [l..r]
    // Sort by l, check contiguous
    sort(segs.begin(), segs.end());
    assert(!segs.empty());
    assert(segs.front().first <= l);
    int cover_lo = max(l, segs.front().first);
    int cover_hi = cover_lo - 1;
    for (auto [sl, sr] : segs) {
      assert(sl <= cover_hi + 1);
      cover_hi = max(cover_hi, sr);
    }
    assert(cover_hi >= r);
  }
}

void stress(int n, int iters, int alpha, uint64_t seed) {
  mt19937_64 rng(seed);
  vector<int> a(n);
  for (auto &x : a) x = int(rng() % alpha);
  ChthollyTree<int> ct(a);
  check_equal(ct, a);

  for (int i = 0; i < iters; i++) {
    int op = int(rng() % 4);
    int l = int(rng() % n);
    int r = l + int(rng() % (n - l));
    if (op == 0) {
      // range assign to constant v
      int v = int(rng() % alpha);
      ct.apply(l, r, [&](int) { return v; });
      brute_apply(a, l, r, [&](int) { return v; });
    } else if (op == 1) {
      // range map x -> x + c
      int c = int(rng() % 7) - 3;
      ct.apply(l, r, [&](int x) { return x + c; });
      brute_apply(a, l, r, [&](int x) { return x + c; });
    } else if (op == 2) {
      // range map x -> x ^ c  (still valid value-preserving transform)
      int c = int(rng() % 8);
      ct.apply(l, r, [&](int x) { return x ^ c; });
      brute_apply(a, l, r, [&](int x) { return x ^ c; });
    } else {
      // check via traverse: sum over [l..r]
      int64_t got = 0, want = 0;
      ct.traverse(l, r, [&](auto it) {
        int tl = max(it->l, l), tr = min(it->r, r);
        got += int64_t(it->val) * (tr - tl + 1);
      });
      for (int j = l; j <= r; j++) want += a[j];
      assert(got == want);
    }
    check_equal(ct, a);
  }

  check_traverse_tiling(ct, n, rng, 50);
}

int main() {
  // Tiny
  {
    ChthollyTree<int> ct(1, 7);
    check_equal(ct, {7});
    ct.apply(0, 0, [&](int) { return 3; });
    check_equal(ct, {3});
  }

  {
    ChthollyTree<int> ct(3, 0);
    check_equal(ct, {0, 0, 0});
    ct.apply(0, 2, [&](int) { return 5; });
    check_equal(ct, {5, 5, 5});
    ct.apply(1, 1, [&](int) { return 9; });
    check_equal(ct, {5, 9, 5});
    ct.apply(0, 2, [&](int x) { return x + 1; });
    check_equal(ct, {6, 10, 6});
  }

  // Construct from array with all distinct values
  {
    vector<int> a = {1, 2, 3, 4, 5};
    ChthollyTree<int> ct(a);
    check_equal(ct, a);
    ct.apply(1, 3, [&](int) { return 99; });
    check_equal(ct, {1, 99, 99, 99, 5});
  }

  // Construct from array with many runs
  {
    vector<int> a = {1, 1, 1, 2, 2, 3, 3, 3, 3, 1};
    ChthollyTree<int> ct(a);
    check_equal(ct, a);
    ct.apply(0, 9, [&](int) { return 0; });
    check_equal(ct, vector<int>(10, 0));
  }

  // Range assign a single cell at a time (many splits)
  {
    int n = 30;
    vector<int> a(n, 0);
    ChthollyTree<int> ct(a);
    for (int i = 0; i < n; i++) {
      ct.apply(i, i, [&](int) { return i + 1; });
      a[i] = i + 1;
      check_equal(ct, a);
    }
  }

  // Stress: several configurations
  stress(10, 500, 3, 1);
  stress(10, 500, 1, 2);       // alpha=1 (all same)
  stress(20, 2000, 5, 3);
  stress(50, 5000, 10, 4);
  stress(200, 10000, 20, 5);
  stress(5, 500, 2, 6);

  int a, b;
  cin >> a >> b;
  cout << a + b << '\n';
}
