## Overview

A collection of data structures and algorithms for competitive programming, automatically tested against online judge datasets and documented via GitHub Actions.

## Code Style

**Formatting:**
- 2-space indentation, no line wrapping
- PascalCase for classes, snake_case for everything else
- 0-indexed and inclusive intervals always

**Class Naming:**
- `Segtree` not `SegTree` (includes `LazySegtree`, `SparseSegtree`, `PersistentSegtree`)
- `Fentree` not `FenTree` (includes `DualFentree`, `Fentree2D`)
- Fully capitalize acronyms (`KosarajuSCC`, `FastLCA`, `DSU`)

**Headers:**
- Assume `template/template.h` is pre-included
- Don't include IO or external libraries inside headers

## Tests

Tests go in `verify/<judge>/<category>/<name>.test.cpp` and must:
- Start with `#define PROBLEM "https://judge.yosupo.jp/problem/..."` 
- Include `template/template.h` then the header being tested
- Read judge input and print exact expected output in `main()`
- Cover edge cases: empty/singleton inputs, min/max indices, degenerate graphs, overflow boundaries, adversarial inputs
- Use `// verification-helper: IGNORE` to temporarily skip (sparingly)

## Supported Judges

- **Library Checker** (judge.yosupo.jp): Best for data structures, graphs, number theory, strings. Set `GH_PAT` to avoid rate limits.
- **AOJ** (onlinejudge.u-aizu.ac.jp): Classical problems with good coverage.
- **yukicoder**: May need `YUKICODER_TOKEN` for some datasets.
- **AtCoder**: Use when no Library Checker equivalent exists.

Store credentials as repository secrets, never commit them directly.

## Finding Test Problems

1. Check Library Checker first—it's designed for library verification
2. Search AOJ/AtCoder/yukicoder for problems that isolate your algorithm
3. Verify constraints exercise the intended complexity (e.g., large n for O(log n) operations)
4. Prefer deterministic problems with public datasets

## Documentation

Create Markdown files in `docs/` with YAML front matter linking to headers:

```yaml
---
title: Disjoint Set Union (DSU)
documentation_of: datastructures/dsu.h
---
```

Include: overview, API reference, complexity analysis, preconditions/caveats, and a concise usage example. The site is auto-built by `oj-verify docs` and styled via `.verify-helper/docs/_config.yml`.