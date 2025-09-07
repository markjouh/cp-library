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
  bundledCode: "#line 1 \"src/datastructures/w_ary_tree.h\"\nstruct Word {\n  uint64_t\
    \ mask;\n  \n  Word() : mask(0) {}\n  \n  void flip_bit(int p) {\n    mask ^=\
    \ 1ull << p;\n  }\n\n  int min_bit() {\n    return __builtin_ctzll(mask);\n  }\n\
    \n  int max_bit() {\n    return 63 - __builtin_clzll(mask);\n  }\n};\n\nstruct\
    \ WAryTreeBase : public Word {\n  bool flip(int p) {\n    bool old = mask != 0;\n\
    \    flip_bit(p);\n    return (mask != 0) != old;\n  }\n\n  int min() {\n    return\
    \ min_bit();\n  }\n\n  int max() {\n    return max_bit();\n  }\n};\n\ntemplate\
    \ <int L>\nstruct WAryTree : public Word {\n  array<conditional_t<(L > 2), WAryTree<L\
    \ - 1>, WAryTreeBase>, 64> nxt;\n\n  static constexpr int block_sz = 1ull << (6\
    \ * (L - 1));\n\n  bool flip(int p) {\n    bool old = mask != 0;\n    int block\
    \ = p / block_sz;\n    if (nxt[block].flip(p % block_sz)) {\n      flip_bit(block);\n\
    \    }\n    return (mask != 0) != old;\n  }\n\n  int get_min() {\n    int block\
    \ = min_bit();\n    return block * block_sz + nxt[block].min();\n  }\n  \n  int\
    \ get_max() {\n    int block = max_bit();\n    return block * block_sz + nxt[block].max();\n\
    \  }\n};\n"
  code: "struct Word {\n  uint64_t mask;\n  \n  Word() : mask(0) {}\n  \n  void flip_bit(int\
    \ p) {\n    mask ^= 1ull << p;\n  }\n\n  int min_bit() {\n    return __builtin_ctzll(mask);\n\
    \  }\n\n  int max_bit() {\n    return 63 - __builtin_clzll(mask);\n  }\n};\n\n\
    struct WAryTreeBase : public Word {\n  bool flip(int p) {\n    bool old = mask\
    \ != 0;\n    flip_bit(p);\n    return (mask != 0) != old;\n  }\n\n  int min()\
    \ {\n    return min_bit();\n  }\n\n  int max() {\n    return max_bit();\n  }\n\
    };\n\ntemplate <int L>\nstruct WAryTree : public Word {\n  array<conditional_t<(L\
    \ > 2), WAryTree<L - 1>, WAryTreeBase>, 64> nxt;\n\n  static constexpr int block_sz\
    \ = 1ull << (6 * (L - 1));\n\n  bool flip(int p) {\n    bool old = mask != 0;\n\
    \    int block = p / block_sz;\n    if (nxt[block].flip(p % block_sz)) {\n   \
    \   flip_bit(block);\n    }\n    return (mask != 0) != old;\n  }\n\n  int get_min()\
    \ {\n    int block = min_bit();\n    return block * block_sz + nxt[block].min();\n\
    \  }\n  \n  int get_max() {\n    int block = max_bit();\n    return block * block_sz\
    \ + nxt[block].max();\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/datastructures/w_ary_tree.h
  requiredBy: []
  timestamp: '2025-09-06 20:10:03-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/datastructures/w_ary_tree.h
layout: document
title: W-ary Tree
---

A specialized data structure that functions like a min/max heap for a fixed-size integer universe. It provides extremely fast insertion, deletion, and retrieval of the minimum and maximum elements.

Its design is similar to a Van Emde Boas (vEB) tree, recursively partitioning the universe into 64 blocks. A 64-bit summary mask at each level tracks non-empty child blocks, allowing for rapid traversal. Performance is near-constant time due to hardware-accelerated bitwise instructions.

## Operations
- `flip(p)`: Toggles the presence of integer `p` in the set (functionally an insert or erase).
- `get_min()`: Returns the minimum integer currently in the set.
- `get_max()`: Returns the maximum integer currently in the set.

## Complexity

The time complexity depends on the compile-time depth `L`, which is determined by the universe size `N` (`L = ceil(log_64(N))`).
- All operations: $O(L)$, or $O(\log_{64} N)$.
- For any practical universe size in competitive programming (e.g., up to $10^7$), `L` is a very small constant (e.g., 4), making all operations exceptionally fast.
- Space: $O(N)$, where `N` is the size of the universe.

## Usage

The template parameter `L` sets the depth and thus the maximum integer that can be stored.
- `L=3`: Supports a universe of size up to $64^3 = 262,144$.
- `L=4`: Supports a universe of size up to $64^4 \approx 1.6 \times 10^7$.

```cpp
#include "datastructures/w_ary_tree.h"
#include <iostream>

int main() {
    // L=3 supports integers in the range [0, 262143]
    WAryTree<3> tree;

    tree.flip(100);
    tree.flip(2000);
    tree.flip(50);
    tree.flip(150000);

    // Prints 50
    std::cout << "Min: " << tree.get_min() << std::endl; 
    // Prints 150000
    std::cout << "Max: " << tree.get_max() << std::endl; 

    tree.flip(50);

    // Prints 100
    std::cout << "Min after flipping 50: " << tree.get_min() << std::endl;

    return 0;
}
```

## Notes
This structure is an excellent choice over `std::set` when you need to maintain a set of integers from a reasonably small, fixed universe and perform frequent min/max queries.
