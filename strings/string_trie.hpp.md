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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ strings/string_trie.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/* Builds a trie, a k-ary search tree where each node represents a distinct\
    \ prefix.\n * `insert(S)`: O(|S|)\n * 'gen_graph()`: O(N), returns an adjacency\
    \ list with the same structure as the trie\n */\n\n#pragma once\n\nstruct string_trie\
    \ {\n    struct node {\n        int nxt[26];\n        bool flag = false;\n\n \
    \       node() {\n            memset(nxt, -1, sizeof nxt);\n        }\n    };\n\
    \n    vector<node> trie;\n\n    string_trie() : trie(1) {}\n\n    int insert(const\
    \ string &s) {\n        int x = 0;\n        for (char c : s) {\n            int\
    \ y = c - 'a';\n            if (trie[x].nxt[y] == -1) {\n                trie[x].nxt[y]\
    \ = sz(trie);\n                trie.emplace_back();\n            }\n         \
    \   x = trie[x].nxt[y];\n        }\n        trie[x].flag = true;\n        return\
    \ x;\n    }\n\n    vector<vector<int>> gen_graph() {\n        vector<vector<int>>\
    \ g(sz(trie));\n        for (int u = 0; u < sz(trie); u++) {\n            for\
    \ (int i = 0; i < 26; i++) {\n                int v = trie[u].nxt[i];\n      \
    \          if (v != -1) {\n                    g[u].push_back(v);\n          \
    \      }\n            }\n        }\n        return g;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: strings/string_trie.hpp
  requiredBy: []
  timestamp: '2024-08-26 11:12:12-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: strings/string_trie.hpp
layout: document
redirect_from:
- /library/strings/string_trie.hpp
- /library/strings/string_trie.hpp.html
title: strings/string_trie.hpp
---
