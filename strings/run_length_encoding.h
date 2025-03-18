template <class T>
auto rle(const T &a) {
  vector<pair<typename T::value_type, int>> res;
  res.emplace_back(a[0], 0);
  for (auto x : a) {
    if (x != res.back().first) {
      res.emplace_back(x, 0);
    }
    res.back().second++;
  }
  return res;
}