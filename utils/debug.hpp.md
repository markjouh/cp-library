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
  bundledCode: "#line 2 \"utils/debug.hpp\"\n#include <iostream>\n#include <ranges>\n\
    #include <type_traits>\n\nnamespace debug_internal {\n\nusing namespace std;\n\
    \ntemplate <typename T>\nconcept is_core = requires(T x) {\n  cerr << x;\n};\n\
    \ntemplate <typename T>\nconcept is_pair = requires(T x) {\n  x.first;\n  x.second;\n\
    };\n\ntemplate <typename T>\nconcept is_iterable = ranges::range<T>;\n\ntemplate\
    \ <typename T>\nvoid print(T x) {\n  if constexpr (is_core<T>) {\n    cerr <<\
    \ x;\n  } else if constexpr (is_pair<T>) {\n    cerr << '(';\n    print(x.first);\n\
    \    cerr << \", \";\n    print(x.second);\n    cerr << ')';\n  } else if constexpr\
    \ (is_iterable<T>) {\n    cerr << '[';\n    bool flag = false;\n    for (auto\
    \ y : x) {\n      if (flag) {\n        cerr << \", \";\n      }\n      print(y);\n\
    \      flag = true;\n    }\n    cerr << ']';\n  } else {\n    cerr << \"Unknown\
    \ type\";\n  }\n}\n\ntemplate <typename T>\nvoid debug(string s, T x) {\n  cerr\
    \ << \"\\033[1;35m\" << s << \"\\033[0;0m = \";\n  print(x);\n  cerr << endl;\n\
    }\n\ntemplate <typename T, typename... Args>\nvoid debug(string s, T x, Args...\
    \ args) {\n  int idx = 0, layer = 0;\n  while (idx < ssize(s) && (s[idx] != ','\
    \ || layer != 0)) {\n    layer += s[idx] == '(' || s[idx] == '{';\n    layer -=\
    \ s[idx] == ')' || s[idx] == '}';\n    idx++;\n  }\n  cerr << \"\\033[1;35m\"\
    \ << s.substr(0, idx) << \"\\033[0;0m = \";\n  print(x);\n  cerr << \"\\033[1;32m\
    \ | \\033[0;0m\";\n  debug(s.substr(s.find_first_not_of(' ', idx + 1)), args...);\n\
    }\n}\n\n#define dbg(...) debug_internal::debug(#__VA_ARGS__, __VA_ARGS__)\n"
  code: "#pragma once\n#include <iostream>\n#include <ranges>\n#include <type_traits>\n\
    \nnamespace debug_internal {\n\nusing namespace std;\n\ntemplate <typename T>\n\
    concept is_core = requires(T x) {\n  cerr << x;\n};\n\ntemplate <typename T>\n\
    concept is_pair = requires(T x) {\n  x.first;\n  x.second;\n};\n\ntemplate <typename\
    \ T>\nconcept is_iterable = ranges::range<T>;\n\ntemplate <typename T>\nvoid print(T\
    \ x) {\n  if constexpr (is_core<T>) {\n    cerr << x;\n  } else if constexpr (is_pair<T>)\
    \ {\n    cerr << '(';\n    print(x.first);\n    cerr << \", \";\n    print(x.second);\n\
    \    cerr << ')';\n  } else if constexpr (is_iterable<T>) {\n    cerr << '[';\n\
    \    bool flag = false;\n    for (auto y : x) {\n      if (flag) {\n        cerr\
    \ << \", \";\n      }\n      print(y);\n      flag = true;\n    }\n    cerr <<\
    \ ']';\n  } else {\n    cerr << \"Unknown type\";\n  }\n}\n\ntemplate <typename\
    \ T>\nvoid debug(string s, T x) {\n  cerr << \"\\033[1;35m\" << s << \"\\033[0;0m\
    \ = \";\n  print(x);\n  cerr << endl;\n}\n\ntemplate <typename T, typename...\
    \ Args>\nvoid debug(string s, T x, Args... args) {\n  int idx = 0, layer = 0;\n\
    \  while (idx < ssize(s) && (s[idx] != ',' || layer != 0)) {\n    layer += s[idx]\
    \ == '(' || s[idx] == '{';\n    layer -= s[idx] == ')' || s[idx] == '}';\n   \
    \ idx++;\n  }\n  cerr << \"\\033[1;35m\" << s.substr(0, idx) << \"\\033[0;0m =\
    \ \";\n  print(x);\n  cerr << \"\\033[1;32m | \\033[0;0m\";\n  debug(s.substr(s.find_first_not_of('\
    \ ', idx + 1)), args...);\n}\n}\n\n#define dbg(...) debug_internal::debug(#__VA_ARGS__,\
    \ __VA_ARGS__)\n"
  dependsOn: []
  isVerificationFile: false
  path: utils/debug.hpp
  requiredBy: []
  timestamp: '2024-09-01 21:27:07-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utils/debug.hpp
layout: document
redirect_from:
- /library/utils/debug.hpp
- /library/utils/debug.hpp.html
title: utils/debug.hpp
---
