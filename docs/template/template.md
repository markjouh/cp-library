---
title: Template
documentation_of: ./src/template/template.h
---

Standard competitive programming template with common includes and optimizations.

## Features

- Fast I/O setup with `ios::sync_with_stdio(false)`
- Common includes: `<bits/stdc++.h>`, algorithm headers
- Useful macros and typedefs
- Debug utilities for local development

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
  
  // Your solution here
  
  return 0;
}
```

## Notes

Includes portable built-ins and explicit standard library includes for compatibility across different compilers.