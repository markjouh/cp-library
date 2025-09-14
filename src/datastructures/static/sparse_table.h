template <class T, auto op>
struct SparseTable {
  int n, log;
  vector<vector<T>> st;

  SparseTable() {}
  SparseTable(const vector<T> &a) : n(ssize(a)), log(__lg(n) + 1) {
    st.resize(log);
    st[0] = a;
    for (int i = 1; i < log; i++) {
      st[i].resize(n - (1 << i) + 1);
      for (int j = 0; j < ssize(st[i]); j++) {
        st[i][j] = op(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
      }
    }
  }

  T query(int l, int r) {
    assert(l <= r);
    int i = __lg(++r - l);
    return op(st[i][l], st[i][r - (1 << i)]);
  }
};

template <class T>
T min_op(T x, T y) {
  return x < y ? x : y;
}
template <class T>
T max_op(T x, T y) {
  return x > y ? x : y;
}
