#define PROBLEM "https://judge.yosupo.jp/problem/static_range_mode_query"

#include "../../../template/template.h"
#include "../../../datastructures/hash_table.h"
#include "../../../datastructures/static/mo_handler.h"

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  MoHandler<300> mo;
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    mo.add(l, r - 1);
  }

  hash_table<int, int> freq;
  set<pair<int, int>> st;

  auto add = [&](int p) {
    if (freq.find(a[p]) != freq.end()) {
      st.extract({freq[a[p]], a[p]});
    }
    freq[a[p]]++;
    st.insert({freq[a[p]], a[p]});
  };

  auto del = [&](int p) {
    if (freq.find(a[p]) != freq.end()) {
      st.extract({freq[a[p]], a[p]});
    }
    freq[a[p]]--;
    st.insert({freq[a[p]], a[p]});
  };

  vector<pair<int, int>> ans(q);

  auto query = [&](int idx) {
    ans[idx] = make_pair(rbegin(st)->second, rbegin(st)->first);
  };

  mo.run(add, del, query);
  for (auto [x, y] : ans) {
    cout << x << ' ' << y << '\n';
  }
}