---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"strings/string_trie.hpp\"\n\nstruct StringTrie {\n  struct\
    \ node {\n    int nxt[26];\n    bool flag = false;\n\n    node() {\n      memset(nxt,\
    \ -1, sizeof nxt);\n    }\n  };\n\n  vector<node> trie;\n\n  StringTrie() : trie(1)\
    \ {}\n\n  int insert(const string &s) {\n    int x = 0;\n    for (char c : s)\
    \ {\n      int y = c - 'a';\n      if (trie[x].nxt[y] == -1) {\n        trie[x].nxt[y]\
    \ = sz(trie);\n        trie.emplace_back();\n      }\n      x = trie[x].nxt[y];\n\
    \    }\n    trie[x].flag = true;\n    return x;\n  }\n\n  vector<vector<int>>\
    \ gen_graph() {\n    vector<vector<int>> g(sz(trie));\n    for (int u = 0; u <\
    \ sz(trie); u++) {\n      for (int i = 0; i < 26; i++) {\n        int v = trie[u].nxt[i];\n\
    \        if (v != -1) {\n          g[u].push_back(v);\n        }\n      }\n  \
    \  }\n    return g;\n  }\n};\n"
  code: "#pragma once\n\nstruct StringTrie {\n  struct node {\n    int nxt[26];\n\
    \    bool flag = false;\n\n    node() {\n      memset(nxt, -1, sizeof nxt);\n\
    \    }\n  };\n\n  vector<node> trie;\n\n  StringTrie() : trie(1) {}\n\n  int insert(const\
    \ string &s) {\n    int x = 0;\n    for (char c : s) {\n      int y = c - 'a';\n\
    \      if (trie[x].nxt[y] == -1) {\n        trie[x].nxt[y] = sz(trie);\n     \
    \   trie.emplace_back();\n      }\n      x = trie[x].nxt[y];\n    }\n    trie[x].flag\
    \ = true;\n    return x;\n  }\n\n  vector<vector<int>> gen_graph() {\n    vector<vector<int>>\
    \ g(sz(trie));\n    for (int u = 0; u < sz(trie); u++) {\n      for (int i = 0;\
    \ i < 26; i++) {\n        int v = trie[u].nxt[i];\n        if (v != -1) {\n  \
    \        g[u].push_back(v);\n        }\n      }\n    }\n    return g;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: strings/string_trie.hpp
  requiredBy: []
  timestamp: '2024-08-28 02:47:08-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: strings/string_trie.hpp
layout: document
redirect_from:
- /library/strings/string_trie.hpp
- /library/strings/string_trie.hpp.html
title: strings/string_trie.hpp
---
