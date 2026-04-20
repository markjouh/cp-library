#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"

#include "../../../template/template.h"
#include "../../../datastructures/ordered_set.h"

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;
  string t;
  cin >> t;

  ordered_set<int> st;
  for (int i = 0; i < n; i++) {
    if (t[i] == '1') {
      st.insert(i);
    }
  }

  while (q--) {
    int op, k;
    cin >> op >> k;
    if (op == 0) {
      st.insert(k);
    } else if (op == 1) {
      st.erase(k);
    } else if (op == 2) {
      cout << (st.find(k) != st.end()) << '\n';
    } else if (op == 3) {
      auto it = st.lower_bound(k);
      cout << (it == st.end() ? -1 : *it) << '\n';
    } else {
      auto it = st.upper_bound(k);
      cout << (it == st.begin() ? -1 : *--it) << '\n';
    }
  }
}
