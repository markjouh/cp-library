#pragma once

template <class T, int B>
struct MoQueries {
  vector<array<int, 3>> queries;
  vector<T> res;

  MoQueries() {}

  void insert(int l, int r) {
    queries.push_back({l, r, sz(queries)});
  }

  template<class AddL, class DelL, class AddR, class DelR, class Query>
  void solve(AddL add_l, DelL del_l, AddR add_r, DelR del_r, Query query) {
    sort(all(queries), [](array<int, 3> a, array<int, 3> b) {
      if (a[1] / B != b[1] / B) {
        return a[1] / B < b[1] / B;
      }
      return a[0] < b[0];
    });
    res.resize(sz(queries));

    int cur_l = 0, cur_r = -1;
    for (auto [l, r, idx] : queries) {
      while (cur_l > l) {
        add_l(--cur_l);
      }
      while (cur_r < r) {
        add_r(++cur_r);
      }
      while (cur_l < l) {
        del_l(cur_l++);
      }
      while (cur_r > r) {
        del_r(cur_r--);
      }
      res[idx] = query();
    }
  }

  template<class Add, class Del, class Query>
  void solve(Add add, Del del, Query query) {
    solve<Add, Del, Add, Del, Query>(add, del, add, del, query);
  }
};