---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/associative_array.test.cpp
    title: verify/library_checker/data_structure/associative_array.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"template/io_helpers.h\"\ntemplate <class T, class = void>\n\
    struct is_range : false_type {};\ntemplate <class T>\nstruct is_range<T, void_t<decltype(begin(declval<T>())),\
    \ decltype(end(declval<T>()))>> : true_type {};\ntemplate <class T>\nusing enable_if_cont\
    \ = enable_if_t<!is_same<T, string>::value && is_range<T>::value, bool>;\n\ntemplate\
    \ <class T, class U>\nistream &operator>>(istream &is, pair<T, U> &p) {\n    is\
    \ >> p.fi >> p.se;\n    return is;\n}\ntemplate <class T, class U>\nostream &operator<<(ostream\
    \ &os, const pair<T, U> &p) {\n    os << p.fi << ' ' << p.se;\n    return os;\n\
    }\ntemplate <class T, enable_if_cont<T> = true>\nistream &operator>>(istream &is,\
    \ T &v) {\n    for (auto &x : v) {\n        is >> x;\n    }\n    return is;\n\
    }\ntemplate <class T, enable_if_cont<T> = true>\nostream &operator<<(ostream &os,\
    \ const T &v) {\n    for (int i = 0; i < sz(v); i++) {\n        os << v[i];\n\
    \        if (i != sz(v) - 1) {\n            os << (is_range<typename T::value_type>::value\
    \ ? '\\n' : ' ');\n        }\n    }\n    return os;\n}\n\ntemplate <class ...T>\n\
    void re(T &...a) {\n    (cin >> ... >> a);\n}\ntemplate <class ...T>\nvoid pr(const\
    \ T &...a) {\n    int p = 0;\n    ((cout << a << (++p == sizeof...(T) ? '\\n'\
    \ : ' ')), ...);\n}\n"
  code: "template <class T, class = void>\nstruct is_range : false_type {};\ntemplate\
    \ <class T>\nstruct is_range<T, void_t<decltype(begin(declval<T>())), decltype(end(declval<T>()))>>\
    \ : true_type {};\ntemplate <class T>\nusing enable_if_cont = enable_if_t<!is_same<T,\
    \ string>::value && is_range<T>::value, bool>;\n\ntemplate <class T, class U>\n\
    istream &operator>>(istream &is, pair<T, U> &p) {\n    is >> p.fi >> p.se;\n \
    \   return is;\n}\ntemplate <class T, class U>\nostream &operator<<(ostream &os,\
    \ const pair<T, U> &p) {\n    os << p.fi << ' ' << p.se;\n    return os;\n}\n\
    template <class T, enable_if_cont<T> = true>\nistream &operator>>(istream &is,\
    \ T &v) {\n    for (auto &x : v) {\n        is >> x;\n    }\n    return is;\n\
    }\ntemplate <class T, enable_if_cont<T> = true>\nostream &operator<<(ostream &os,\
    \ const T &v) {\n    for (int i = 0; i < sz(v); i++) {\n        os << v[i];\n\
    \        if (i != sz(v) - 1) {\n            os << (is_range<typename T::value_type>::value\
    \ ? '\\n' : ' ');\n        }\n    }\n    return os;\n}\n\ntemplate <class ...T>\n\
    void re(T &...a) {\n    (cin >> ... >> a);\n}\ntemplate <class ...T>\nvoid pr(const\
    \ T &...a) {\n    int p = 0;\n    ((cout << a << (++p == sizeof...(T) ? '\\n'\
    \ : ' ')), ...);\n}"
  dependsOn: []
  isVerificationFile: false
  path: template/io_helpers.h
  requiredBy: []
  timestamp: '2024-12-07 20:04:53-05:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/data_structure/associative_array.test.cpp
documentation_of: template/io_helpers.h
layout: document
redirect_from:
- /library/template/io_helpers.h
- /library/template/io_helpers.h.html
title: template/io_helpers.h
---
