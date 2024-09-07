#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"

#include "../../boilerplate.hpp"
#include "../../../numeric/binary_trie.hpp"

int main() {
  int q;
  cin >> q;
  BinaryTrie bt;
  while (q--) {
    int t, x;
    cin >> t >> x;
    if (t == 0) {
      if (bt.count(x) == 0) {
        bt.insert(x);
      }
    } else if (t == 1) {
      if (bt.count(x) == 1) {
        bt.remove(x);
      }
    } else {
      cout << bt.min_xor(x) << '\n';
    }
  }
}