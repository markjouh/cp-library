---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/datastructures/ordered_set.h
    title: Ordered Set
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: src/verify/library_checker/data_structure/range_kth_smallest.test.cpp
    title: src/verify/library_checker/data_structure/range_kth_smallest.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/datastructures/ordered_set.h\"\n#include <ext/pb_ds/assoc_container.hpp>\
    \ \n#include <ext/pb_ds/tree_policy.hpp>\n\nusing namespace __gnu_pbds; \n\ntemplate\
    \ <class T>\nusing ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;\n\
    \ntemplate <class T>\nstruct OrderedMultiset {\n  int time = 0;\n  ordered_set<pair<T,\
    \ int>> st;\n\n  void insert(T x) {\n    st.insert({x, time++});\n  }\n  void\
    \ extract(T x) {\n    auto it = st.lower_bound({x, 0});\n    if (it != end(st)\
    \ && it->fi == x) {\n      st.erase(it);\n    }\n  }\n\n  T find_by_order(int\
    \ k) {\n    return (*st.find_by_order(k)).first;\n  }\n  int order_of_key(T x)\
    \ {\n    return st.order_of_key({x, 0});\n  }\n};\n#line 2 \"src/datastructures/merge_sort_tree.h\"\
    \n\ntemplate <class T>\nstruct MergeSortTree {\n  int n;\n  vector<ordered_set<pair<T,\
    \ int>>> st;\n \n  MergeSortTree(const vector<T> &a) : n(ssize(a)), st(2 * n)\
    \ {\n    for (int i = 0; i < n; i++) {\n      for (int p = i + n; p > 0; p >>=\
    \ 1) {\n        st[p].insert({a[i], i});\n      }\n    }\n  }\n \n  int query(int\
    \ l, int r, T v) {\n    int res = 0;\n    for (l += n, r += n + 1; l < r; l >>=\
    \ 1, r >>= 1) {\n      if (l & 1) {\n        res += st[l++].order_of_key({v, 0});\n\
    \      }\n      if (r & 1) {\n        res += st[--r].order_of_key({v, 0});\n \
    \     }\n    }\n    return res;\n  }\n \n  void set(int p, T v) {\n    const auto\
    \ old = *begin(st[p + n]);\n    for (p += n; p > 0; p >>= 1) {\n      st[p].erase(old);\n\
    \      st[p].insert(v);\n    }\n  }\n};\n"
  code: "#include \"ordered_set.h\"\n\ntemplate <class T>\nstruct MergeSortTree {\n\
    \  int n;\n  vector<ordered_set<pair<T, int>>> st;\n \n  MergeSortTree(const vector<T>\
    \ &a) : n(ssize(a)), st(2 * n) {\n    for (int i = 0; i < n; i++) {\n      for\
    \ (int p = i + n; p > 0; p >>= 1) {\n        st[p].insert({a[i], i});\n      }\n\
    \    }\n  }\n \n  int query(int l, int r, T v) {\n    int res = 0;\n    for (l\
    \ += n, r += n + 1; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) {\n        res\
    \ += st[l++].order_of_key({v, 0});\n      }\n      if (r & 1) {\n        res +=\
    \ st[--r].order_of_key({v, 0});\n      }\n    }\n    return res;\n  }\n \n  void\
    \ set(int p, T v) {\n    const auto old = *begin(st[p + n]);\n    for (p += n;\
    \ p > 0; p >>= 1) {\n      st[p].erase(old);\n      st[p].insert(v);\n    }\n\
    \  }\n};\n"
  dependsOn:
  - src/datastructures/ordered_set.h
  isVerificationFile: false
  path: src/datastructures/merge_sort_tree.h
  requiredBy: []
  timestamp: '2025-09-14 12:12:28-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - src/verify/library_checker/data_structure/range_kth_smallest.test.cpp
documentation_of: src/datastructures/merge_sort_tree.h
layout: document
title: Merge Sort Tree
---

Segment tree where each node contains ordered set of elements in its range for order statistics queries.

## Operations

- `MergeSortTree(arr)`: Construct from array
- `query(l, r, v)`: Count elements in `[l, r]` strictly less than `v`
- `set(p, v)`: Update element at position `p` to value `v`

## Complexity

- Construction: $O(n \log^2 n)$
- Query: $O(\log^2 n)$
- Update: $O(\log^2 n)$
- Space: $O(n \log n)$

## Usage

```cpp
vector<int> arr = {3, 1, 4, 1, 5, 9, 2};
MergeSortTree<int> mst(arr);

// Count elements in [1, 5] less than 4
int count = mst.query(1, 5, 4); // Returns 2

// Update element at position 2
mst.set(2, 7);
```

## Notes

Uses ordered_set with element-index pairs to handle duplicates. Extra log factor from set operations.

**Memory Optimization**: The $O(n \log n)$ space bound comes from each element appearing in $O(\log n)$ nodes. For large datasets, consider using a persistent segment tree with coordinate compression, or offline processing with a sweep line to reduce memory usage.