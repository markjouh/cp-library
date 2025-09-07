---
title: W-ary Tree
documentation_of: ./src/datastructures/w_ary_tree.h
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
