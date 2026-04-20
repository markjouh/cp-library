struct DSU {
  vector<int> a;

  DSU(int n_) : a(n_, -1) {}

  int size(int x) {
    return -a[find(x)];
  }

  int find(int x) {
    return a[x] < 0 ? x : a[x] = find(a[x]);
  }

  bool join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) {
      return false;
    }
    if (a[x] > a[y]) {
      swap(x, y);
    }
    a[x] += a[y];
    a[y] = x;
    return true;
  }
};