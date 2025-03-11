---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/string/enumerate_palindromes.test.cpp
    title: verify/library_checker/string/enumerate_palindromes.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"strings/hashing.h\"\nnamespace hashing {\n\nmt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    \nconst uint64_t MOD = (1ll << 61) - 1;\nconst uint64_t B = uniform_int_distribution<uint64_t>(0,\
    \ MOD)(mt);\n\nvector<uint64_t> pow_b = {1};\n\nuint64_t add(uint64_t a, uint64_t\
    \ b) {\n  a += b;\n  if (a >= MOD) {\n    a -= MOD;\n  }\n  return a;\n}\n\nuint64_t\
    \ sub(uint64_t a, uint64_t b) {\n  a += MOD - b;\n  if (a >= MOD) {\n    a -=\
    \ MOD;\n  }\n  return a;\n}\n\nuint64_t mul(uint64_t a, uint64_t b) {\n  uint64_t\
    \ l1 = (uint32_t) a, h1 = a >> 32, l2 = (uint32_t) b, h2 = b >> 32;\n  uint64_t\
    \ l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;\n  uint64_t ret = (l & MOD)\
    \ + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;\n  ret = (ret & MOD)\
    \ + (ret >> 61);\n  ret = (ret & MOD) + (ret >> 61);\n  return ret - 1;\n}\n\n\
    struct SegHash {\n  uint64_t val;\n  int len;\n\n  SegHash(uint64_t x, int y)\
    \ : val(x), len(y) {}\n\n  SegHash operator+(SegHash b) const {\n    return SegHash(add(mul(val,\
    \ pow_b[b.len]), b.val), len + b.len);\n  }\n\n  bool operator==(SegHash b) const\
    \ {\n    return val == b.val;\n  }\n};\n\nstruct RollingHash {\n  int n;\n  vector<uint64_t>\
    \ h;\n\n  template <class T>\n  RollingHash(const T &s) : n(sz(s)), h(n + 1) {\n\
    \    for (int i = 0; i < n; i++) {\n      h[i + 1] = add(mul(h[i], B), s[i]);\n\
    \    }\n    int p = sz(pow_b);\n    if (p < n + 1) {\n      pow_b.resize(n + 1);\n\
    \      for (int i = p; i <= n; i++) {\n        pow_b[i] = mul(pow_b[i - 1], B);\n\
    \      }\n    }\n  }\n\n  SegHash get(int l, int r) const {\n    assert(l < ++r);\n\
    \    return SegHash(sub(h[r], mul(h[l], pow_b[r - l])), r - l);\n  }\n\n  SegHash\
    \ get_all() const {\n    return SegHash(h[n], n);\n  }\n};\n\n} // namespace hashing\n"
  code: "namespace hashing {\n\nmt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    \nconst uint64_t MOD = (1ll << 61) - 1;\nconst uint64_t B = uniform_int_distribution<uint64_t>(0,\
    \ MOD)(mt);\n\nvector<uint64_t> pow_b = {1};\n\nuint64_t add(uint64_t a, uint64_t\
    \ b) {\n  a += b;\n  if (a >= MOD) {\n    a -= MOD;\n  }\n  return a;\n}\n\nuint64_t\
    \ sub(uint64_t a, uint64_t b) {\n  a += MOD - b;\n  if (a >= MOD) {\n    a -=\
    \ MOD;\n  }\n  return a;\n}\n\nuint64_t mul(uint64_t a, uint64_t b) {\n  uint64_t\
    \ l1 = (uint32_t) a, h1 = a >> 32, l2 = (uint32_t) b, h2 = b >> 32;\n  uint64_t\
    \ l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;\n  uint64_t ret = (l & MOD)\
    \ + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;\n  ret = (ret & MOD)\
    \ + (ret >> 61);\n  ret = (ret & MOD) + (ret >> 61);\n  return ret - 1;\n}\n\n\
    struct SegHash {\n  uint64_t val;\n  int len;\n\n  SegHash(uint64_t x, int y)\
    \ : val(x), len(y) {}\n\n  SegHash operator+(SegHash b) const {\n    return SegHash(add(mul(val,\
    \ pow_b[b.len]), b.val), len + b.len);\n  }\n\n  bool operator==(SegHash b) const\
    \ {\n    return val == b.val;\n  }\n};\n\nstruct RollingHash {\n  int n;\n  vector<uint64_t>\
    \ h;\n\n  template <class T>\n  RollingHash(const T &s) : n(sz(s)), h(n + 1) {\n\
    \    for (int i = 0; i < n; i++) {\n      h[i + 1] = add(mul(h[i], B), s[i]);\n\
    \    }\n    int p = sz(pow_b);\n    if (p < n + 1) {\n      pow_b.resize(n + 1);\n\
    \      for (int i = p; i <= n; i++) {\n        pow_b[i] = mul(pow_b[i - 1], B);\n\
    \      }\n    }\n  }\n\n  SegHash get(int l, int r) const {\n    assert(l < ++r);\n\
    \    return SegHash(sub(h[r], mul(h[l], pow_b[r - l])), r - l);\n  }\n\n  SegHash\
    \ get_all() const {\n    return SegHash(h[n], n);\n  }\n};\n\n} // namespace hashing"
  dependsOn: []
  isVerificationFile: false
  path: strings/hashing.h
  requiredBy: []
  timestamp: '2025-03-11 15:25:13-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/string/enumerate_palindromes.test.cpp
documentation_of: strings/hashing.h
layout: document
redirect_from:
- /library/strings/hashing.h
- /library/strings/hashing.h.html
title: strings/hashing.h
---
