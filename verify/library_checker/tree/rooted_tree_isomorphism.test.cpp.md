---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graphs/trees/tree_hashing.h
    title: graphs/trees/tree_hashing.h
  - icon: ':question:'
    path: template/template.h
    title: template/template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification
    links:
    - https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification
  bundledCode: "#line 1 \"verify/library_checker/tree/rooted_tree_isomorphism.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification\"\
    \n\n#line 1 \"template/template.h\"\n/**\n *    author: mark\n**/\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\n#define sz(x) int(size(x))\n#define all(x) begin(x),\
    \ end(x)\n#line 1 \"graphs/trees/tree_hashing.h\"\nmap<vector<int>, int> tree_hashes;\n\
    \nauto hash_tree(const vector<vector<int>> &g, int root = 0) {\n\tvector<int>\
    \ res(sz(g));\n\t\n\tauto dfs = [&](auto &&self, int u, int par) -> void {\n\t\
    \tvector<int> ch;\n\t\tfor (int v : g[u]) {\n\t\t\tif (v != par) {\n\t\t\t\tself(self,\
    \ v, u);\n\t\t\t\tch.push_back(res[v]);\n\t\t\t}\n\t\t}\n\t\tsort(all(ch));\n\t\
    \tif (!tree_hashes.count(ch)) {\n\t\t\ttree_hashes[ch] = sz(tree_hashes);\n\t\t\
    }\n\t\tres[u] = tree_hashes[ch];\n\t};\n\n\tdfs(dfs, root, -1);\n\n\treturn res;\n\
    }\n#line 5 \"verify/library_checker/tree/rooted_tree_isomorphism.test.cpp\"\n\n\
    int main() {\n  int n;\n  cin >> n;\n  vector<vector<int>> g(n);\n  for (int i\
    \ = 1; i < n; i++) {\n    int p;\n    cin >> p;\n    g[p].push_back(i);\n  }\n\
    \  auto res = hash_tree(g);\n  cout << sz(tree_hashes) << '\\n';\n  for (int x\
    \ : res) {\n    cout << x << ' ';\n  }\n  cout << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification\"\
    \n\n#include \"../../../template/template.h\"\n#include \"../../../graphs/trees/tree_hashing.h\"\
    \n\nint main() {\n  int n;\n  cin >> n;\n  vector<vector<int>> g(n);\n  for (int\
    \ i = 1; i < n; i++) {\n    int p;\n    cin >> p;\n    g[p].push_back(i);\n  }\n\
    \  auto res = hash_tree(g);\n  cout << sz(tree_hashes) << '\\n';\n  for (int x\
    \ : res) {\n    cout << x << ' ';\n  }\n  cout << '\\n';\n}"
  dependsOn:
  - template/template.h
  - graphs/trees/tree_hashing.h
  isVerificationFile: true
  path: verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
  requiredBy: []
  timestamp: '2025-03-11 01:06:40-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
- /verify/verify/library_checker/tree/rooted_tree_isomorphism.test.cpp.html
title: verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
---
