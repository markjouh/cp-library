#pragma once

template <class T>
pair<vector<int>, vector<int>> findNGE(vector<T> a, bool greater = false) {
  const int n = sz(a);
  vector<int> prev(n, -1), nxt(n, n);

  if (greater) {
    for (int i = 0; i < n; i++) {
      a[i] = -a[i];
    }
  }

  stack<int> s;
  for (int i = 0; i < n; i++) {
    while (sz(s) && a[s.top()] > a[i]) {
      s.pop();
    }
    if (sz(s)) {
      prev[i] = s.top();
    }
    s.push(i);
  }
  while (sz(s)) {
    s.pop();
  }
  for (int i = n - 1; i >= 0; i--) {
    while (sz(s) && a[s.top()] >= a[i]) {
      s.pop();
    }
    if (sz(s)) {
      nxt[i] = s.top();
    }
    s.push(i);
  }

  return make_pair(prev, nxt);
}