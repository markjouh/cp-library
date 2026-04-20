#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../../template/template.h"
#include "../../../datastructures/w_ary_tree.h"

// NOTE: this test only covers L=1 and L=2. For L >= 3, get_min / get_max
// call `nxt[block].min()` but the recursive child `WAryTree<L-1>` exposes
// `get_min`, not `min` — so the current implementation is broken on deeper
// recursions.

template <int L>
void stress(int universe, int iters, uint64_t seed) {
  mt19937_64 rng(seed);
  WAryTree<L> t;
  set<int> s;

  for (int i = 0; i < iters; i++) {
    int op = int(rng() % 5);
    int p = int(rng() % universe);
    if (op < 3) {
      bool was_empty = s.empty();
      if (s.count(p)) s.erase(p);
      else s.insert(p);
      bool is_empty = s.empty();
      bool changed = t.flip(p);
      assert(changed == (was_empty != is_empty));
    } else if (!s.empty()) {
      if (op == 3) assert(t.get_min() == *s.begin());
      else assert(t.get_max() == *s.rbegin());
    }
  }
}

int main() {
  // L=1 universe [0, 64)
  stress<1>(64, 20000, 1);

  // L=2 universe [0, 4096)
  stress<2>(4096, 80000, 2);

  // Same element flipped many times: toggles emptiness every call
  {
    WAryTree<2> t;
    for (int i = 0; i < 1000; i++) {
      bool r = t.flip(42);
      assert(r);
    }
    bool r = t.flip(42);
    assert(r);
    assert(t.get_min() == 42);
    assert(t.get_max() == 42);
  }

  // Fill entire L=2 universe, then drain from min
  {
    WAryTree<2> t;
    int U = 4096;
    for (int i = 0; i < U; i++) t.flip(i);
    assert(t.get_min() == 0);
    assert(t.get_max() == U - 1);
    for (int i = 0; i < U; i++) {
      assert(t.get_min() == i);
      t.flip(i);
    }
  }

  // Insert in reverse order, verify max stays at the initial large value and
  // min keeps dropping.
  {
    WAryTree<2> t;
    int U = 1024;
    for (int i = U - 1; i >= 0; i--) {
      t.flip(i);
      assert(t.get_max() == U - 1);
      assert(t.get_min() == i);
    }
  }

  // L=1 block boundaries
  {
    WAryTree<1> t;
    t.flip(0);
    t.flip(63);
    assert(t.get_min() == 0);
    assert(t.get_max() == 63);
    t.flip(0);
    assert(t.get_min() == 63);
    assert(t.get_max() == 63);
  }

  // L=2 boundaries
  {
    WAryTree<2> t;
    int hi = 4095;
    t.flip(hi);
    assert(t.get_min() == hi);
    assert(t.get_max() == hi);
    t.flip(0);
    assert(t.get_min() == 0);
    assert(t.get_max() == hi);
    t.flip(2048);
    assert(t.get_min() == 0);
    assert(t.get_max() == hi);
    t.flip(hi);
    assert(t.get_max() == 2048);
  }

  int a, b;
  cin >> a >> b;
  cout << a + b << '\n';
}
