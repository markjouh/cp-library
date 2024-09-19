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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.6/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.6/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.6/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.6/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: segtree.h: line\
    \ -1: no such header\n"
  code: "#pragma once\n\n#include \"segtree.h\"\n\ntemplate <class T, T(*op)(T, T),\
    \ T(*id)()>\nstruct SegtreeSet {\n    int n;\n    set<int> free;\n    set<pair<T,\
    \ int>> used;\n    SegmentTree<T, op, id> st;\n\n    SegtreeSet(int n_) : n(n_),\
    \ st(n) {\n        for (int i = 0; i < n; i++) {\n            free.insert(i);\n\
    \        }\n    }\n\n    void insert(T x) {\n        assert(!free.empty());\n\
    \        T p = *begin(free);\n        free.erase(begin(free));\n        st.set(p,\
    \ x);\n        used.emplace(x, p);\n    }\n\n    void remove(T x) {\n        auto\
    \ it = used.lower_bound({x, -1});\n        assert(it->fi == x);\n        st.set(it->se,\
    \ id());\n        free.insert(it->se);\n        used.erase(it);\n    }\n\n   \
    \ T query() {\n        return st.query(0, n - 1);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/segtree/segtree_set.h
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructures/segtree/segtree_set.h
layout: document
redirect_from:
- /library/datastructures/segtree/segtree_set.h
- /library/datastructures/segtree/segtree_set.h.html
title: datastructures/segtree/segtree_set.h
---
