---
title: Run Length Encoding
documentation_of: ./src/strings/run_length_encoding.h
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