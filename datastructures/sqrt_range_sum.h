// Supports point updates in O(1) and range queries in O(sqrt N).

template <class T, int K>
struct SqrtRangeSum {
  vector<int> arr, blocks;

  SqrtRangeSum(int n) {
    const int m = (n + K - 1) / K;
    arr.resize(m * K);
    blocks.resize(m);
  }

  SqrtRangeSum(const vector<T> &a) {
    SqrtRangeSum(a.size());
    for (int i = 0; i < int(a.size()); i++) {
      arr[i] = a[i];
      blocks[i / K] += a[i];
    }
  }

  void add(int p, T x) {
    arr[p] += x;
    blocks[p / K] += x;
  }

  void set(int p, T x) {
    add(p, x - arr[p]);
  }

  T get(int p) {
    return arr[p];
  }

  T sum(int l, int r) {
    T res = 0;
    if (l / K == r / K) {
      for (int i = l; i <= r; i++) {
        res += arr[i];
      }
    } else {
      while (l % K) {
        res += arr[l++];
      }
      while ((r + 1) % K) {
        res += arr[r--];
      }
      for (int i = l / K; i <= r / K; i++) {
        res += blocks[i];
      }
    }
    return res;
  }
};
