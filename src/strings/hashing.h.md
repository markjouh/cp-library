---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: src/verify/library_checker/string/enumerate_palindromes.test.cpp
    title: src/verify/library_checker/string/enumerate_palindromes.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/strings/hashing.h\"\nnamespace hashing {\n\nmt19937_64\
    \ mt(chrono::steady_clock::now().time_since_epoch().count());\n\nconst uint64_t\
    \ MOD = (1ll << 61) - 1;\nconst uint64_t B = uniform_int_distribution<uint64_t>(0,\
    \ MOD)(mt);\n\nuint64_t add(uint64_t a, uint64_t b) {\n  a += b;\n  if (a >= MOD)\
    \ {\n    a -= MOD;\n  }\n  return a;\n}\n\nuint64_t sub(uint64_t a, uint64_t b)\
    \ {\n  a += MOD - b;\n  if (a >= MOD) {\n    a -= MOD;\n  }\n  return a;\n}\n\n\
    uint64_t mul(uint64_t a, uint64_t b) {\n  uint64_t l1 = (uint32_t) a, h1 = a >>\
    \ 32, l2 = (uint32_t) b, h2 = b >> 32;\n  uint64_t l = l1 * l2, m = l1 * h2 +\
    \ l2 * h1, h = h1 * h2;\n  uint64_t ret = (l & MOD) + (l >> 61) + (h << 3) + (m\
    \ >> 29) + (m << 35 >> 3) + 1;\n  ret = (ret & MOD) + (ret >> 61);\n  ret = (ret\
    \ & MOD) + (ret >> 61);\n  return ret - 1;\n}\n\ntemplate<typename T, typename\
    \ = void>\nstruct IsIterable : false_type {};\ntemplate<typename T>\nstruct IsIterable<T,\
    \ void_t<\n  decltype(begin(declval<T&>())),\n  decltype(end(declval<T&>()))\n\
    >> : true_type {};\n\ntemplate<typename T>\nstruct IsTuple : false_type {};\n\
    template<typename... Ts>\nstruct IsTuple<tuple<Ts...>> : true_type {};\ntemplate<typename\
    \ T, typename U>\nstruct IsTuple<pair<T, U>> : true_type {};\n\ntemplate<typename\
    \ T>\nuint64_t hash_one(const T &t) {\n  if constexpr (IsTuple<T>::value) {\n\
    \    uint64_t res = 0;\n    apply([&](const auto &...elems) {\n      ((res = add(mul(res,\
    \ B), hash_one(elems))), ...);\n    }, t);\n    return res;\n  } else if constexpr\
    \ (IsIterable<T>::value) {\n    uint64_t res = 0;\n    for (const auto &x : t)\n\
    \      res = add(mul(res, B), hash_one(x));\n    return res;\n  } else {\n   \
    \ return static_cast<uint64_t>(t);\n  }\n}\n\ntemplate<typename ...Args>\nuint64_t\
    \ hash(const Args &...args) {\n  uint64_t res = 0;\n  ((res = add(mul(res, B),\
    \ hash_one(args))), ...);\n  return res;\n}\n\nvector<uint64_t> pow_b = {1};\n\
    \nstruct SegHash {\n  uint64_t val;\n  int len;\n\n  SegHash(uint64_t x, int y)\
    \ : val(x), len(y) {}\n\n  SegHash operator+(SegHash b) const {\n    return SegHash(add(mul(val,\
    \ pow_b[b.len]), b.val), len + b.len);\n  }\n\n  bool operator==(SegHash b) const\
    \ {\n    return val == b.val;\n  }\n};\n\nstruct RollingHash {\n  int n;\n  vector<uint64_t>\
    \ h;\n\n  template <class T>\n  RollingHash(const T &s) : n(s.size()), h(n + 1)\
    \ {\n    for (int i = 0; i < n; i++) {\n      h[i + 1] = add(mul(h[i], B), s[i]);\n\
    \    }\n    int p = pow_b.size();\n    if (p < n + 1) {\n      pow_b.resize(n\
    \ + 1);\n      for (int i = p; i <= n; i++) {\n        pow_b[i] = mul(pow_b[i\
    \ - 1], B);\n      }\n    }\n  }\n\n  SegHash get(int l, int r) const {\n    assert(l\
    \ < ++r);\n    return SegHash(sub(h[r], mul(h[l], pow_b[r - l])), r - l);\n  }\n\
    \n  SegHash get_all() const {\n    return SegHash(h[n], n);\n  }\n};\n\n} // namespace\
    \ hashing\n"
  code: "namespace hashing {\n\nmt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    \nconst uint64_t MOD = (1ll << 61) - 1;\nconst uint64_t B = uniform_int_distribution<uint64_t>(0,\
    \ MOD)(mt);\n\nuint64_t add(uint64_t a, uint64_t b) {\n  a += b;\n  if (a >= MOD)\
    \ {\n    a -= MOD;\n  }\n  return a;\n}\n\nuint64_t sub(uint64_t a, uint64_t b)\
    \ {\n  a += MOD - b;\n  if (a >= MOD) {\n    a -= MOD;\n  }\n  return a;\n}\n\n\
    uint64_t mul(uint64_t a, uint64_t b) {\n  uint64_t l1 = (uint32_t) a, h1 = a >>\
    \ 32, l2 = (uint32_t) b, h2 = b >> 32;\n  uint64_t l = l1 * l2, m = l1 * h2 +\
    \ l2 * h1, h = h1 * h2;\n  uint64_t ret = (l & MOD) + (l >> 61) + (h << 3) + (m\
    \ >> 29) + (m << 35 >> 3) + 1;\n  ret = (ret & MOD) + (ret >> 61);\n  ret = (ret\
    \ & MOD) + (ret >> 61);\n  return ret - 1;\n}\n\ntemplate<typename T, typename\
    \ = void>\nstruct IsIterable : false_type {};\ntemplate<typename T>\nstruct IsIterable<T,\
    \ void_t<\n  decltype(begin(declval<T&>())),\n  decltype(end(declval<T&>()))\n\
    >> : true_type {};\n\ntemplate<typename T>\nstruct IsTuple : false_type {};\n\
    template<typename... Ts>\nstruct IsTuple<tuple<Ts...>> : true_type {};\ntemplate<typename\
    \ T, typename U>\nstruct IsTuple<pair<T, U>> : true_type {};\n\ntemplate<typename\
    \ T>\nuint64_t hash_one(const T &t) {\n  if constexpr (IsTuple<T>::value) {\n\
    \    uint64_t res = 0;\n    apply([&](const auto &...elems) {\n      ((res = add(mul(res,\
    \ B), hash_one(elems))), ...);\n    }, t);\n    return res;\n  } else if constexpr\
    \ (IsIterable<T>::value) {\n    uint64_t res = 0;\n    for (const auto &x : t)\n\
    \      res = add(mul(res, B), hash_one(x));\n    return res;\n  } else {\n   \
    \ return static_cast<uint64_t>(t);\n  }\n}\n\ntemplate<typename ...Args>\nuint64_t\
    \ hash(const Args &...args) {\n  uint64_t res = 0;\n  ((res = add(mul(res, B),\
    \ hash_one(args))), ...);\n  return res;\n}\n\nvector<uint64_t> pow_b = {1};\n\
    \nstruct SegHash {\n  uint64_t val;\n  int len;\n\n  SegHash(uint64_t x, int y)\
    \ : val(x), len(y) {}\n\n  SegHash operator+(SegHash b) const {\n    return SegHash(add(mul(val,\
    \ pow_b[b.len]), b.val), len + b.len);\n  }\n\n  bool operator==(SegHash b) const\
    \ {\n    return val == b.val;\n  }\n};\n\nstruct RollingHash {\n  int n;\n  vector<uint64_t>\
    \ h;\n\n  template <class T>\n  RollingHash(const T &s) : n(s.size()), h(n + 1)\
    \ {\n    for (int i = 0; i < n; i++) {\n      h[i + 1] = add(mul(h[i], B), s[i]);\n\
    \    }\n    int p = pow_b.size();\n    if (p < n + 1) {\n      pow_b.resize(n\
    \ + 1);\n      for (int i = p; i <= n; i++) {\n        pow_b[i] = mul(pow_b[i\
    \ - 1], B);\n      }\n    }\n  }\n\n  SegHash get(int l, int r) const {\n    assert(l\
    \ < ++r);\n    return SegHash(sub(h[r], mul(h[l], pow_b[r - l])), r - l);\n  }\n\
    \n  SegHash get_all() const {\n    return SegHash(h[n], n);\n  }\n};\n\n} // namespace\
    \ hashing"
  dependsOn: []
  isVerificationFile: false
  path: src/strings/hashing.h
  requiredBy: []
  timestamp: '2025-09-07 14:42:16-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - src/verify/library_checker/string/enumerate_palindromes.test.cpp
documentation_of: src/strings/hashing.h
layout: document
title: Polynomial Rolling Hash
---

Polynomial rolling hash with 64-bit modulus $2^{61} - 1$ and randomized base for collision-resistant string hashing.

## Operations

- `hash_one(x)`: Hash single value of supported type
- `hash(args...)`: Hash multiple arguments  
- `add(a, b)`, `sub(a, b)`, `mul(a, b)`: Modular arithmetic
- `RollingHash(s)`: Construct from string/container
- `get(l, r)`: Get hash of `s[l..r-1]`
- `get_all()`: Get hash of entire string
- `operator+(other)`: Concatenate hash segments (`SegHash`)

## Complexity

- Construction: $O(n)$
- Query: $O(1)$
- Space: $O(n)$

## Usage

```cpp
string s = "hello";
RollingHash rh(s);
auto full_hash = rh.get_all();
auto substr_hash = rh.get(1, 4); // "ell"

// Multi-argument hashing
auto combined = hashing::hash(42, "test", vector<int>{1, 2, 3});

// Hash concatenation
SegHash seg1 = rh.get(0, 2);
SegHash seg2 = rh.get(2, 5);
SegHash combined = seg1 + seg2;
```

## Notes

Uses randomized base with time-based seeding. Supports strings, containers, tuples, and primitives.