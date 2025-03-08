#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"

#include "../../../template/template.h"
#include "../../../datastructures/hash_table.h"

int main() {
  int q;
  cin >> q;
  hash_table<int64_t, int64_t> mp;
  while (q--) {
    bool t;
    int64_t k;
    cin >> t >> k;
    if (t) {
      cout << mp[k] << '\n';
    } else {
      int64_t v;
      cin >> v;
      mp[k] = v;
    }
  }
}