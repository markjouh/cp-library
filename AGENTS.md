# Project overview

This project aims to be a collection of elegant, performant, and generic implementations of datastructures and algorithms for competitive programming, complete with a robust test suite and documentation.

We use verification-helper to verify code against authoritative online judge datasets and to build/publish documentation automatically. CI runs on every push.

# Library code
- Indent with 2 spaces; no line wrapping.
- Use PascalCase for class names, and snake_case for everything else.
- Headers assume `template/template.h` is included by consumers; do not include IO or third-party single-file libs from inside headers.
- 0-based indexing and inclusive intervals by default (document exceptions at the top of the file).

# Verification-helper: how we use it

- Purpose: Compile each `*.test.cpp` and run it against canonical test data fetched from supported online judges. Generates a docs site that shows which headers are verified (green checks) and links tests and docs.
- Entrypoints:
  - Local: `oj-verify run` to run a single test, `oj-verify all` to run everything, `oj-verify docs` to build docs locally.
  - CI: `.github/workflows/verify.yml` runs `oj-verify all`. With `GITHUB_TOKEN`/`GH_PAT`, it also updates GitHub Pages.
- Build config: `.verify-helper/config.toml` sets compiler and flags; we compile with GCC and C++20, optimize `-O2`, and define `-DLOCAL`.

# Writing tests

- Location and naming: Place tests under `verify/<judge>/<category>/<name>.test.cpp`. The file name must end with `.test.cpp`.
- Problem binding: At the top of each test file, add a problem URL:
  - `#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"`
  - Or `// verification-helper: PROBLEM https://judge.yosupo.jp/problem/unionfind`
- Structure: Include `template/template.h` and then the header(s) under test. Implement `main()` that reads the judge’s input, uses the library, and prints exactly the required output.
- Scope: Each test should verify one header or one cohesive feature. If multiple headers are required, include them explicitly and document the dependency in the doc page (see Docs below).
- Edge cases to cover in tests:
  - Empty/singleton inputs (if applicable)
  - Min/max indices, inclusive interval ends
  - Degenerate graphs/trees (line/star/disconnected)
  - Overflow boundaries for numeric code (use 64-bit where appropriate)
  - Adversarial equal keys/hashes where relevant
- Skipping a test: Add `// verification-helper: IGNORE` to temporarily skip in CI (use sparingly).

# Supported judges and credentials

Verification-helper can pull official test data from several sites. Common ones we use:
- Library Checker (judge.yosupo.jp): Preferred for data structures, graphs, number theory, strings. Uses GitHub-hosted datasets; `GH_PAT` avoids GitHub API rate limits.
- AOJ/Aizu (onlinejudge.u-aizu.ac.jp): Good coverage of classical problems.
- yukicoder: Some datasets require `YUKICODER_TOKEN`.
- AtCoder (abc/arc/agc): Can be used for verification when a matching task exists; prefer Library Checker when available.

Notes:
- Place the canonical URL in `PROBLEM`. Verification-helper downloads/caches datasets automatically. Keep credentials in repository secrets; do not commit them.

# Finding problems for a new algorithm

1) Check Library Checker for a direct match (e.g., union-find, static RMQ, point add range sum, LCA, SCC, shortest path, suffix array). These tasks are designed for library verification and have comprehensive tests.
2) If no direct match, search AOJ/AtCoder/yukicoder for tasks that isolate and stress the algorithm’s core behavior (avoid tasks where unrelated details dominate).
3) Ensure the problem’s constraints actually exercise the intended complexity class (e.g., O(log n) queries in large volumes for segment trees; long chains/stars for tree algorithms; zero-weight edges for 0-1 BFS).
4) Prefer non-interactive, deterministic tasks with public datasets. If only partial coverage exists, complement with an additional problem.

# Docs: authoring and linkage

Docs live as Markdown files and are linked to headers via front matter. The site is built by `oj-verify docs` and published by CI.

- Where to put docs: Create a Markdown file under `docs/` (root). The Jekyll config in `.verify-helper/docs/_config.yml` styles the site.
- Link a doc to a header with YAML front matter:
  ---
  title: Disjoint Set Union (DSU)
  documentation_of: datastructures/dsu.h
  ---
  Then write prose: purpose, API, complexity, caveats, usage snippet.
- Multiple headers: Use one page per primary header; for support headers, either create short pages or list them in a Dependencies section.
- What to include in each doc page:
  - Overview and intended use cases
  - API synopsis (constructor, main methods)
  - Complexity (build/query/update)
  - Preconditions/caveats (indexing, root assumptions, numeric limits, recursion depth)
  - Usage example (short and focused)

# Site generation & what shows up

- Index page: Automatically lists library files and marks headers with verified tests as green checks. Each header links to the associated doc page if present.
- Per-file pages: Show test status, linked tests, and dependencies. When a doc page with `documentation_of` exists, it becomes the primary page for that header.
- Local preview: `oj-verify docs` builds the site; serve with any static server or Jekyll locally if desired.

# Local workflow

- One-time setup on macOS (self-contained):
  - Install toolchain: `brew install gcc pipx`
  - Ensure PATH has pipx bin: `export PATH="$HOME/.local/bin:$PATH"`
  - Install tools: `pipx install online-judge-verify-helper` and `pipx install online-judge-tools`
  - Create local config: `make config-local CXX_BIN=g++-15` (or your installed `g++-XX`)
- Day-to-day:
  - Modify headers in place.
  - Add tests under `verify/.../*.test.cpp` with a `#define PROBLEM` URL.
  - Run a single test: `oj-verify run verify/.../file.test.cpp --config-file .verify-helper/config.local.toml`
  - Run all tests: `oj-verify all --config-file .verify-helper/config.local.toml` (or `make verify`)
  - Build docs locally: `oj-verify docs --config-file .verify-helper/config.local.toml` (or `make docs`)
- Push changes; CI runs with `.verify-helper/config.toml` (kept CI-friendly) and updates the site.

# Non-obvious conventions and pitfalls

- Headers do not include IO or third-party blobs; keep them `#include`-light and dependent on `template/template.h` only. Tests/solutions may include `template/fast_io.h` but library headers must not depend on it.
- Trees default to root `0` unless a constructor explicitly accepts a root; document if different.
- `SparseTable` requires non-empty input; calling `__lg(n)` with `n==0` is invalid.
- Real-number binary search assumes IEEE 754 binary64 layout and monotone bit patterns over the search interval (avoid ranges that cross the sign bit).
- PBDS `gp_hash_table` requires GCC; iteration order is non-deterministic due to randomized hashing. Do not rely on ordering in tests.
- Avoid recursion for algorithms that may hit deep stacks, or document maximum depth assumptions.

# Environment hygiene

- Python tools are installed via `pipx` into isolated virtualenvs under `~/.local/pipx/venvs`; executables live in `~/.local/bin`. This avoids polluting system Python.
- GCC is installed via Homebrew and coexists with Apple Clang; we never replace system compilers.
- Local verification uses `.verify-helper/config.local.toml` passed via `--config-file`. CI uses `.verify-helper/config.toml`. We do not change CI defaults for local runs.

# Maintenance checklist for new headers

- Code: Follow style; document root/indexing/interval assumptions at the top; prefer templates/generic operators where appropriate; avoid unnecessary allocations.
- Tests: Add at least one `.test.cpp` that targets an authoritative dataset; include extreme/degenerate cases; keep runtime small.
- Docs: Add `docs/<name>.md` with `documentation_of:` linking to the header. Include API/complexity/caveats and a tiny usage example.
- CI: Ensure C++ standard conformance and portability to GCC. If a judge requires credentials, confirm the secret exists in repo settings.
