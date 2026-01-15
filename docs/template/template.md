---
title: Template
documentation_of: ./src/template/template.h
---

Standard competitive programming template with common includes.

## Features

- Includes `<bits/stdc++.h>`
- `using namespace std`
- `all(x)` macro: expands to `begin(x), end(x)`

## Usage

```cpp
#include "template/template.h"

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(all(a));  // Uses the all() macro

  return 0;
}
```

## Notes

Provides minimal boilerplate for competitive programming. Use `ssize(x)` from C++20 for signed size.
