#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"

#include "../../boilerplate.hpp"
#include "../../../datastructures/pbds/hash_table.hpp"

int main() {
  int q;
  cin >> q;
  HashTable<i64, i64> mp;
  while (q--) {
    bool t;
    i64 k;
    cin >> t >> k;
    if (t) {
      cout << mp[k] << '\n';
    } else {
      i64 v;
      cin >> v;
      mp[k] = v;
    }
  }
}