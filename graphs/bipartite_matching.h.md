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
  bundledCode: "#line 1 \"graphs/bipartite_matching.h\"\n// Left and right parts should\
    \ have separate numbering\n// ls_adj should contain the neighbors of the left\
    \ part\n// rs_match should be the size of the right part, and be initialized with\
    \ -1s\n\nbool find(int j, vector<vector<int>> &ls_adj, vector<int> &rs_match,\
    \ vector<int> &vis) {\n    if (rs_match[j] == -1) {\n        return 1;\n    }\n\
    \    vis[j] = 1;\n    int di = rs_match[j];\n    for (int e : ls_adj[di]) {\n\
    \        if (!vis[e] && find(e, ls_adj, rs_match, vis)) {\n            rs_match[e]\
    \ = di;\n            return 1;\n        }\n    }\n    return 0;\n}\n\nint bipartite_matching(vector<vector<int>>\
    \ &ls_adj, vector<int> &rs_match) {\n    vector<int> vis;\n    for (int i = 0;\
    \ i < sz(ls_adj); i++) {\n        vis.assign(sz(rs_match), 0);\n        for (int\
    \ j : ls_adj[i]) {\n            if (find(j, ls_adj, rs_match, vis)) {\n      \
    \          rs_match[j] = i;\n                break;\n            }\n        }\n\
    \    }\n    return sz(rs_match) - count(all(rs_match), -1);\n}\n"
  code: "// Left and right parts should have separate numbering\n// ls_adj should\
    \ contain the neighbors of the left part\n// rs_match should be the size of the\
    \ right part, and be initialized with -1s\n\nbool find(int j, vector<vector<int>>\
    \ &ls_adj, vector<int> &rs_match, vector<int> &vis) {\n    if (rs_match[j] ==\
    \ -1) {\n        return 1;\n    }\n    vis[j] = 1;\n    int di = rs_match[j];\n\
    \    for (int e : ls_adj[di]) {\n        if (!vis[e] && find(e, ls_adj, rs_match,\
    \ vis)) {\n            rs_match[e] = di;\n            return 1;\n        }\n \
    \   }\n    return 0;\n}\n\nint bipartite_matching(vector<vector<int>> &ls_adj,\
    \ vector<int> &rs_match) {\n    vector<int> vis;\n    for (int i = 0; i < sz(ls_adj);\
    \ i++) {\n        vis.assign(sz(rs_match), 0);\n        for (int j : ls_adj[i])\
    \ {\n            if (find(j, ls_adj, rs_match, vis)) {\n                rs_match[j]\
    \ = i;\n                break;\n            }\n        }\n    }\n    return sz(rs_match)\
    \ - count(all(rs_match), -1);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graphs/bipartite_matching.h
  requiredBy: []
  timestamp: '2025-02-15 21:47:08-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graphs/bipartite_matching.h
layout: document
redirect_from:
- /library/graphs/bipartite_matching.h
- /library/graphs/bipartite_matching.h.html
title: graphs/bipartite_matching.h
---
