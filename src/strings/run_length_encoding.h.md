---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/strings/run_length_encoding.h\"\ntemplate <class T>\n\
    auto rle(const T &a) {\n  vector<pair<typename T::value_type, int>> res;\n  res.emplace_back(a[0],\
    \ 0);\n  for (auto x : a) {\n    if (x != res.back().first) {\n      res.emplace_back(x,\
    \ 0);\n    }\n    res.back().second++;\n  }\n  return res;\n}\n"
  code: "template <class T>\nauto rle(const T &a) {\n  vector<pair<typename T::value_type,\
    \ int>> res;\n  res.emplace_back(a[0], 0);\n  for (auto x : a) {\n    if (x !=\
    \ res.back().first) {\n      res.emplace_back(x, 0);\n    }\n    res.back().second++;\n\
    \  }\n  return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/strings/run_length_encoding.h
  requiredBy: []
  timestamp: '2025-09-06 20:10:03-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/strings/run_length_encoding.h
layout: document
title: Run Length Encoding
---

Compresses sequences by encoding consecutive identical elements as (element, count) pairs.

## Operations

- `rle(container)`: Encode container using run length encoding

## Complexity

- Time: $O(n)$
- Space: $O(k)$ where $k$ is number of runs

## Usage

```cpp
string s = "aaabbbccccdd";
auto encoded = rle(s);
for (auto [ch, count] : encoded) {
  cout << ch << ":" << count << " ";
}
// Output: a:3 b:3 c:4 d:2

vector<int> v = {1, 1, 1, 2, 2, 3, 3, 3, 3, 1};
auto encoded_vec = rle(v);
// Result: [(1, 3), (2, 2), (3, 4), (1, 1)]
```

## Notes

Returns `vector<pair<T::value_type, int>>`. Requires non-empty input container.