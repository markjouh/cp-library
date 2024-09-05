#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C"

#include "../../boilerplate.hpp"
#include "../../../datastructures/w_ary_tree.hpp"
#include "../../../misc/compress.hpp"

int main() {
  string s;
  int x;
  vector<int> queries;
  Compress<int> vals;
  while (cin >> s) {
    if (s == "end") {
      break;
    }
    if (s == "insert") {
      cin >> x;
      queries.push_back(x);
      vals.insert(x);
    } else {
      queries.push_back(-1);
    }
  }
  vals.init();
  WAryTree<2000000> ds;
  for (auto x : queries) {
    if (x == -1) {
      int mx_idx = ds.get_max();
      cout << vals[mx_idx] << '\n';
      ds.extract(mx_idx);
    } else {
      ds.insert(vals.get(x));
    }
  }
}