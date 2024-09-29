---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/string/suffix_array.test.cpp
    title: verify/library_checker/string/suffix_array.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"strings/suffix_array.h\"\n\nauto gen_sa(const string &s)\
    \ {\n    const int n = sz(s) + 1;\n\n    vector<int> sa(n);\n    sa[0] = n - 1;\n\
    \    iota(begin(sa) + 1, end(sa), 0);\n    sort(begin(sa) + 1, end(sa), [&](int\
    \ x, int y) {\n        return s[x] < s[y];\n    });\n\n    vector<int> ec(n);\n\
    \    ec[sa[1]] = 1;\n    for (int i = 2; i < n; i++) {\n        ec[sa[i]] = ec[sa[i\
    \ - 1]] + (s[sa[i]] != s[sa[i - 1]]);\n    }\n\n    for (int i = 1; i < n; i *=\
    \ 2) {\n        transform(all(sa), begin(sa), [&](int x) {\n            x -= i;\n\
    \            return x + (x < 0) * n;\n        });\n\n        vector<int> pos(n\
    \ + 1);\n        for (int x : ec) {\n            pos[x + 1]++;\n        }\n  \
    \      partial_sum(all(pos), begin(pos));\n\n        vector<int> new_sa(n);\n\
    \        for (int j : sa) {\n            new_sa[pos[ec[j]]++] = j;\n        }\n\
    \        sa = new_sa;\n\n        vector<int> new_ec(n);\n        for (int j =\
    \ 1; j < n; j++) {\n            int x = sa[j - 1], y = sa[j];\n            new_ec[y]\
    \ = new_ec[x] + (ec[y] != ec[x] || ec[y + i - (y + i >= n) * n] != ec[x + i -\
    \ (x + i >= n) * n]);\n        }\n        ec = new_ec;\n    }\n\n    return sa;\n\
    }\n\nauto gen_lcp(const vector<int> &sa, const string &s) {\n    const int n =\
    \ sz(sa);\n\n    vector<int> rank(n);\n    for (int i = 0; i < n; i++) {\n   \
    \     rank[sa[i]] = i;\n    }\n\n    vector<int> lcp(n);\n    int cur = 0;\n \
    \   for (int i = 0; i < n - 1; i++) {\n        int prev = sa[rank[i] - 1];\n \
    \       while (s[i + cur] == s[prev + cur]) {\n            cur++;\n        }\n\
    \        lcp[rank[i]] = cur;\n        cur = max(cur - 1, 0);\n    }\n    return\
    \ lcp;\n}\n"
  code: "#pragma once\n\nauto gen_sa(const string &s) {\n    const int n = sz(s) +\
    \ 1;\n\n    vector<int> sa(n);\n    sa[0] = n - 1;\n    iota(begin(sa) + 1, end(sa),\
    \ 0);\n    sort(begin(sa) + 1, end(sa), [&](int x, int y) {\n        return s[x]\
    \ < s[y];\n    });\n\n    vector<int> ec(n);\n    ec[sa[1]] = 1;\n    for (int\
    \ i = 2; i < n; i++) {\n        ec[sa[i]] = ec[sa[i - 1]] + (s[sa[i]] != s[sa[i\
    \ - 1]]);\n    }\n\n    for (int i = 1; i < n; i *= 2) {\n        transform(all(sa),\
    \ begin(sa), [&](int x) {\n            x -= i;\n            return x + (x < 0)\
    \ * n;\n        });\n\n        vector<int> pos(n + 1);\n        for (int x : ec)\
    \ {\n            pos[x + 1]++;\n        }\n        partial_sum(all(pos), begin(pos));\n\
    \n        vector<int> new_sa(n);\n        for (int j : sa) {\n            new_sa[pos[ec[j]]++]\
    \ = j;\n        }\n        sa = new_sa;\n\n        vector<int> new_ec(n);\n  \
    \      for (int j = 1; j < n; j++) {\n            int x = sa[j - 1], y = sa[j];\n\
    \            new_ec[y] = new_ec[x] + (ec[y] != ec[x] || ec[y + i - (y + i >= n)\
    \ * n] != ec[x + i - (x + i >= n) * n]);\n        }\n        ec = new_ec;\n  \
    \  }\n\n    return sa;\n}\n\nauto gen_lcp(const vector<int> &sa, const string\
    \ &s) {\n    const int n = sz(sa);\n\n    vector<int> rank(n);\n    for (int i\
    \ = 0; i < n; i++) {\n        rank[sa[i]] = i;\n    }\n\n    vector<int> lcp(n);\n\
    \    int cur = 0;\n    for (int i = 0; i < n - 1; i++) {\n        int prev = sa[rank[i]\
    \ - 1];\n        while (s[i + cur] == s[prev + cur]) {\n            cur++;\n \
    \       }\n        lcp[rank[i]] = cur;\n        cur = max(cur - 1, 0);\n    }\n\
    \    return lcp;\n}"
  dependsOn: []
  isVerificationFile: false
  path: strings/suffix_array.h
  requiredBy: []
  timestamp: '2024-09-29 00:35:58-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/string/suffix_array.test.cpp
documentation_of: strings/suffix_array.h
layout: document
redirect_from:
- /library/strings/suffix_array.h
- /library/strings/suffix_array.h.html
title: strings/suffix_array.h
---
