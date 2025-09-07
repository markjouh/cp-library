---
title: Suffix Array and LCP Array
documentation_of: ./src/strings/suffix_array.h
---

Suffix array construction using radix sort with LCP array generation for string processing.

## Operations

- `gen_suffix_array(s)`: Generate suffix array for string `s`
- `gen_lcp(sa, s)`: Generate LCP array from suffix array and string

## Complexity

- Suffix array: $O(n \log n)$
- LCP array: $O(n)$
- Space: $O(n)$

## Usage

```cpp
string s = "banana";
auto sa = gen_suffix_array(s);
auto lcp = gen_lcp(sa, s);

// sa[i] contains starting position of i-th lexicographically smallest suffix
// lcp[i] = LCP length between suffixes sa[i-1] and sa[i]

// Pattern matching with binary search
string pattern = "an";
auto low = lower_bound(sa.begin() + 1, sa.end(), 0, 
  [&](int pos, int) { return s.substr(pos, pattern.size()) < pattern; });
```

## Notes

Supports empty suffix at position `n`. Uses Kasai's algorithm for LCP construction with height optimization.