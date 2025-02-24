// Abstracts away the ordering and boundary movement logic for Mo's algorithm.
// For answering arbitrary range queries on a static 1D array.

template <class T, int K>
struct MoHandler {
  vector<array<int, 3>> queries;

  MoHandler() {}

  void insert(int l, int r) {
    queries.push_back({l, r, int(queries.size())});
  }

  template <class F1, class F2, class F3, class F4, class F5>
  void run(F1 add_l, F2 del_l, F3 add_r, F4 del_r, F5 answer) {
    sort(queries.begin(), queries.end(), [](array<int, 3> a, array<int, 3> b) {
      if (a[1] / K != b[1] / K) {
        return a[1] / K < b[1] / K;
      }
      return a[0] < b[0];
    });

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
      answer(idx);
    }
  }

  template <class F1, class F2, class F3>
  void run(F1 add, F2 del, F3 answer) {
    run<F1, F2, F1, F2, F3>(add, del, add, del, answer);
  }
};
