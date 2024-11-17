---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: strings/suffix_array.h
    title: strings/suffix_array.h
  - icon: ':question:'
    path: template/template.h
    title: template/template.h
  - icon: ':question:'
    path: utils/bits/stdc++.h
    title: utils/bits/stdc++.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/suffixarray
    links:
    - https://judge.yosupo.jp/problem/suffixarray
  bundledCode: "#line 1 \"verify/library_checker/string/suffix_array.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\n\n#line 1 \"\
    template/template.h\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\n#define\
    \ all(x) begin(x), end(x)\n#define sz(x) int(size(x))\n\n#define pb push_back\n\
    #define eb emplace_back\n#define fi first\n#define se second\n\nusing ll = long\
    \ long;\n\n// void solve() {\n// }\n\n// int main() {\n//     cin.tie(0)->sync_with_stdio(0);\n\
    //     cin.exceptions(cin.failbit);\n\n//     int t = 1;\n//     // cin >> t;\n\
    //     while (t--) {\n//         solve();\n//     }\n\n//     return 0;\n// }\n\
    #line 1 \"strings/suffix_array.h\"\nauto gen_sa(const string &s) {\n    const\
    \ int n = sz(s) + 1;\n\n    vector<int> sa(n);\n    sa[0] = n - 1;\n    iota(begin(sa)\
    \ + 1, end(sa), 0);\n    sort(begin(sa) + 1, end(sa), [&](int x, int y) {\n  \
    \      return s[x] < s[y];\n    });\n\n    vector<int> ec(n);\n    ec[sa[1]] =\
    \ 1;\n    for (int i = 2; i < n; i++) {\n        ec[sa[i]] = ec[sa[i - 1]] + (s[sa[i]]\
    \ != s[sa[i - 1]]);\n    }\n\n    for (int i = 1; i < n; i *= 2) {\n        transform(all(sa),\
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
    \    return lcp;\n}\n#line 5 \"verify/library_checker/string/suffix_array.test.cpp\"\
    \n\nint main() {\n    string s;\n    cin >> s;\n    bool first = true;\n    for\
    \ (int x : gen_sa(s)) {\n        if (first) {\n            first = false;\n  \
    \          continue;\n        }\n        cout << x << ' ';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\n\n#include\
    \ \"../../../template/template.h\"\n#include \"../../../strings/suffix_array.h\"\
    \n\nint main() {\n    string s;\n    cin >> s;\n    bool first = true;\n    for\
    \ (int x : gen_sa(s)) {\n        if (first) {\n            first = false;\n  \
    \          continue;\n        }\n        cout << x << ' ';\n    }\n}"
  dependsOn:
  - template/template.h
  - utils/bits/stdc++.h
  - strings/suffix_array.h
  isVerificationFile: true
  path: verify/library_checker/string/suffix_array.test.cpp
  requiredBy: []
  timestamp: '2024-11-16 20:34:38-05:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/string/suffix_array.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/string/suffix_array.test.cpp
- /verify/verify/library_checker/string/suffix_array.test.cpp.html
title: verify/library_checker/string/suffix_array.test.cpp
---
