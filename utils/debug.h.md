---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: template/template.h
    title: template/template.h
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu/alds1/binary_search.test.cpp
    title: verify/aizu/alds1/binary_search.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu/alds1/number_of_inversions.test.cpp
    title: verify/aizu/alds1/number_of_inversions.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu/dsl/rmq.test.cpp
    title: verify/aizu/dsl/rmq.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu/dsl/rsq_and_raq.test.cpp
    title: verify/aizu/dsl/rsq_and_raq.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu/ntl/power.test.cpp
    title: verify/aizu/ntl/power.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/associative_array.test.cpp
    title: verify/library_checker/data_structure/associative_array.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/point_add_range_sum.test.cpp
    title: verify/library_checker/data_structure/point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/range_kth_smallest.test.cpp
    title: verify/library_checker/data_structure/range_kth_smallest.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/set_xor_min.test.cpp
    title: verify/library_checker/data_structure/set_xor_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/static_range_mode_query.test.cpp
    title: verify/library_checker/data_structure/static_range_mode_query.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/static_rmq.test.cpp
    title: verify/library_checker/data_structure/static_rmq.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/unionfind.test.cpp
    title: verify/library_checker/data_structure/unionfind.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/graph/scc.test.cpp
    title: verify/library_checker/graph/scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/graph/shortest_path.test.cpp
    title: verify/library_checker/graph/shortest_path.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/number_theory/enumerate_primes.test.cpp
    title: verify/library_checker/number_theory/enumerate_primes.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/string/enumerate_palindromes.test.cpp
    title: verify/library_checker/string/enumerate_palindromes.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/string/suffix_array.test.cpp
    title: verify/library_checker/string/suffix_array.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/tree/lca.test.cpp
    title: verify/library_checker/tree/lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
    title: verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
    title: verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"utils/debug.h\"\n\n\n\n#include <string>\n#include <vector>\n\
    #include <iostream>\n#include <algorithm>\n\nnamespace cp_utils {\n\nusing namespace\
    \ std;\n\n// Options\nconst bool full_path = false;\n\n// Text formatting (how\
    \ to separate, put things on same or different lines, etc)\nconst string delimiter\
    \ = \", \";\nconst string divider = \", \";\nconst string open_br = \"{\", close_br\
    \ = \"}\";\nconst string indent = \"  \";\n\n// Colors\nconst string metadata_st\
    \ = \"\\033[31m\";\nconst string type_st = \"\\033[35;2m\";\nconst string param_st\
    \ = \"\\033[35;1m\";\nconst string punct_st = \"\\033[32;1m\";\nconst string value_st\
    \ = \"\\033[33m\";\nconst string literal_st = \"\\033[36;1m\";\nconst string reset_st\
    \ = \"\\033[0m\";\n\ntemplate <class T>\nint sz(const T &x) {\n    return static_cast<int>(ssize(x));\n\
    }\n\ninline string style(const string &s, const string &col) {\n    return col\
    \ + s + reset_st;\n}\n\nstruct parser {\n    string s;\n    int pos = 0;\n   \
    \ bool in_sq = 0, in_dq = 0;\n    int brackets = 0;\n\n    parser(string t) :\
    \ s(t) {}\n\n    char get() const {\n        return s[pos];\n    }\n    int layer()\
    \ const {\n        if (in_sq || in_dq) {\n            return -1;\n        }\n\
    \        return brackets;\n    }\n\n    bool next() {\n        if (pos == ssize(s))\
    \ {\n            return false;\n        }\n        in_sq ^= s[pos] == '\\'' &&\
    \ !in_dq && (pos == 0 || s[pos - 1] != '\\\\');\n        in_dq ^= s[pos] == '\\\
    \"' && !in_sq && (pos == 0 || s[pos - 1] != '\\\\');\n        if (!in_sq && !in_dq)\
    \ {\n            brackets += string(\"<([{\").find(s[pos]) != string::npos;\n\
    \            brackets -= string(\"}])>\").find(s[pos]) != string::npos;\n    \
    \    }\n        pos++;\n        return true;\n    }\n};\n\ntemplate <class T>\n\
    concept Stringable = requires(T x) { to_string(x); };\n\ntemplate <class T>\n\
    concept TupleLike = requires(T x) {\n    { tuple_size<T>::value };\n    { get<0>(x)\
    \ };\n};\n\ntemplate <class T>\nconcept Iterable = !is_same<T, string>::value\
    \ && ranges::range<T>;\n\ntemplate <class T>\nconcept ArrayLike = Iterable<T>\
    \ && requires(T x) {\n    { x[0] };\n};\n\ntemplate <class T>\nconcept Table =\
    \ ArrayLike<T> && ArrayLike<typename T::value_type> && !ArrayLike<typename T::value_type::value_type>;\n\
    \ntemplate <class T>\nvector<int> find_shape(const T &val) {\n    if constexpr\
    \ (Iterable<T>) {\n        vector<int> desc;\n        for (const auto &x : val)\
    \ {\n            if (desc.empty()) {\n                desc = find_shape(x);\n\
    \            } else if (find_shape(x) != desc) {\n                desc = {-1};\n\
    \                break;\n            }\n        }\n        desc.insert(begin(desc),\
    \ sz(val));\n        return desc;\n    } else {\n        return {0};\n    }\n\
    }\n\ntemplate <class T>\nstring format(const T &val) {\n    if constexpr (is_same_v<T,\
    \ char>) {\n        return style(string(\"'\") + val + \"'\", value_st);\n   \
    \ } else if constexpr (is_same_v<T, string>) {\n        return style('\"' + val\
    \ + '\"', value_st);\n    } else if constexpr (Stringable<T>) {\n        return\
    \ style(to_string(val), value_st);\n    } else if constexpr (TupleLike<T>) {\n\
    \        string res;\n\n        apply([&](auto &&...args) {\n            ((res\
    \ += (style(res.empty() ? \"\" : delimiter, punct_st) + format(args))), ...);\n\
    \        }, val);\n\n        res = style(open_br, punct_st) + res + style(close_br,\
    \ punct_st);\n        return res;\n    } else if constexpr (Iterable<T>) {\n \
    \       string res;\n\n        if constexpr (Table<T>) {\n            const int\
    \ n = sz(val);\n\n            vector<vector<string>> table(n);\n            int\
    \ cols = 0;\n            for (int i = 0; i < n; i++) {\n                table[i].resize(sz(val[i]));\n\
    \                cols = max(cols, sz(val[i]));\n                for (int j = 0;\
    \ j < sz(val[i]); j++) {\n                    table[i][j] = format(val[i][j]);\n\
    \                }\n            }\n\n            bool is_grid = true;\n      \
    \      for (int i = 0; i < n; i++) {\n                is_grid &= sz(val[i]) ==\
    \ cols;\n            }\n\n            if (is_grid) {\n                for (int\
    \ i = 0; i < cols; i++) {\n                    int col_width = 0;\n          \
    \          for (int j = 0; j < n; j++) {\n                        if (i < sz(table[j]))\
    \ {\n                            col_width = max(col_width, sz(table[j][i]));\n\
    \                        }\n                    }\n                    for (int\
    \ j = 0; j < n; j++) {\n                        if (i < sz(table[j])) {\n    \
    \                        table[j][i] = string(col_width - ssize(table[j][i]),\
    \ ' ') + table[j][i];\n                        }\n                    }\n    \
    \            }\n            }\n\n            res += '\\n';\n            for (int\
    \ i = 0; i < n; i++) {\n                if (i > 0) {\n                    res\
    \ += style(delimiter + \"\\n\", punct_st);\n                }\n              \
    \  res += indent + style(open_br, punct_st);\n                for (int j = 0;\
    \ j < sz(table[i]); j++) {\n                    if (j > 0) {\n               \
    \         res += style(delimiter, punct_st);\n                    }\n        \
    \            res += table[i][j];\n                }\n                res += style(close_br,\
    \ punct_st);\n            }\n            res += '\\n';\n        } else {\n   \
    \         bool first = true;\n            for (const auto &x : val) {\n      \
    \          if (!first) {\n                    res += style(delimiter, punct_st);\n\
    \                }\n                res += format(x);\n                first =\
    \ false;\n            }\n        }\n        \n        res = style(open_br, punct_st)\
    \ + res + style(close_br, punct_st);\n        return res;\n    } else {\n    \
    \    throw invalid_argument(\"Invalid type\");\n    }\n}\n\ntemplate <class ...Args>\n\
    void print(string file, const string func, const int line, const string &s, const\
    \ Args &...vals) {\n    if (!full_path) {\n        file = file.substr(file.rfind('/')\
    \ + 1, sz(file));\n    }\n\n    string res = style(\"Line #\" + to_string(line)\
    \ + \" of \" + file + \", in \" + func + \":\\n\", metadata_st);\n\n    parser\
    \ p(s);\n\n    auto format_single = [&](const auto &cur) {\n        int start\
    \ = p.pos;\n        while ((p.get() != ',' || p.layer()) && p.next());\n\n   \
    \     string label = s.substr(start, p.pos - start);\n        p.next();\n\n  \
    \      for (int i = 0; i < 2; i++) {\n            while (!label.empty() && isspace(label.back()))\
    \ {\n                label.pop_back();\n            }\n            reverse(label.begin(),\
    \ label.end());\n        }\n\n        if (start > 0) {\n            res += style(divider,\
    \ punct_st);\n        }\n\n        // Handle string literals separately\n    \
    \    if (label[0] == '\"' && label.back() == '\"' && count(label.begin(), label.end(),\
    \ '\"') == 2) {\n            res += style(label.substr(1, sz(label) - 2), literal_st);\n\
    \            return;\n        }\n\n        // Try to find shape\n        res +=\
    \ style(label, param_st);\n\n        auto shape = find_shape(cur);\n        if\
    \ (sz(shape) >= 2) {\n            for (int x : shape) {\n                if (x\
    \ == 0) {\n                    break;\n                }\n                if (x\
    \ == -1) {\n                    res += style(\"(...)\", type_st);\n          \
    \          break;\n                }\n                res += style('[' + to_string(x)\
    \ + ']', type_st);\n            }\n        }\n        \n        res += style(\"\
    \ = \", punct_st) + format(cur);\n    };\n\n    (format_single(vals), ...);\n\n\
    \    std::cerr << res << std::endl;\n}\n\n} // namespace cp_utils\n\n#define dbg(...)\
    \ cp_utils::print(__FILE__, __func__, __LINE__, #__VA_ARGS__, __VA_ARGS__)\n\n\
    \n"
  code: "#ifndef DEBUG_H\n#define DEBUG_H\n\n#include <string>\n#include <vector>\n\
    #include <iostream>\n#include <algorithm>\n\nnamespace cp_utils {\n\nusing namespace\
    \ std;\n\n// Options\nconst bool full_path = false;\n\n// Text formatting (how\
    \ to separate, put things on same or different lines, etc)\nconst string delimiter\
    \ = \", \";\nconst string divider = \", \";\nconst string open_br = \"{\", close_br\
    \ = \"}\";\nconst string indent = \"  \";\n\n// Colors\nconst string metadata_st\
    \ = \"\\033[31m\";\nconst string type_st = \"\\033[35;2m\";\nconst string param_st\
    \ = \"\\033[35;1m\";\nconst string punct_st = \"\\033[32;1m\";\nconst string value_st\
    \ = \"\\033[33m\";\nconst string literal_st = \"\\033[36;1m\";\nconst string reset_st\
    \ = \"\\033[0m\";\n\ntemplate <class T>\nint sz(const T &x) {\n    return static_cast<int>(ssize(x));\n\
    }\n\ninline string style(const string &s, const string &col) {\n    return col\
    \ + s + reset_st;\n}\n\nstruct parser {\n    string s;\n    int pos = 0;\n   \
    \ bool in_sq = 0, in_dq = 0;\n    int brackets = 0;\n\n    parser(string t) :\
    \ s(t) {}\n\n    char get() const {\n        return s[pos];\n    }\n    int layer()\
    \ const {\n        if (in_sq || in_dq) {\n            return -1;\n        }\n\
    \        return brackets;\n    }\n\n    bool next() {\n        if (pos == ssize(s))\
    \ {\n            return false;\n        }\n        in_sq ^= s[pos] == '\\'' &&\
    \ !in_dq && (pos == 0 || s[pos - 1] != '\\\\');\n        in_dq ^= s[pos] == '\\\
    \"' && !in_sq && (pos == 0 || s[pos - 1] != '\\\\');\n        if (!in_sq && !in_dq)\
    \ {\n            brackets += string(\"<([{\").find(s[pos]) != string::npos;\n\
    \            brackets -= string(\"}])>\").find(s[pos]) != string::npos;\n    \
    \    }\n        pos++;\n        return true;\n    }\n};\n\ntemplate <class T>\n\
    concept Stringable = requires(T x) { to_string(x); };\n\ntemplate <class T>\n\
    concept TupleLike = requires(T x) {\n    { tuple_size<T>::value };\n    { get<0>(x)\
    \ };\n};\n\ntemplate <class T>\nconcept Iterable = !is_same<T, string>::value\
    \ && ranges::range<T>;\n\ntemplate <class T>\nconcept ArrayLike = Iterable<T>\
    \ && requires(T x) {\n    { x[0] };\n};\n\ntemplate <class T>\nconcept Table =\
    \ ArrayLike<T> && ArrayLike<typename T::value_type> && !ArrayLike<typename T::value_type::value_type>;\n\
    \ntemplate <class T>\nvector<int> find_shape(const T &val) {\n    if constexpr\
    \ (Iterable<T>) {\n        vector<int> desc;\n        for (const auto &x : val)\
    \ {\n            if (desc.empty()) {\n                desc = find_shape(x);\n\
    \            } else if (find_shape(x) != desc) {\n                desc = {-1};\n\
    \                break;\n            }\n        }\n        desc.insert(begin(desc),\
    \ sz(val));\n        return desc;\n    } else {\n        return {0};\n    }\n\
    }\n\ntemplate <class T>\nstring format(const T &val) {\n    if constexpr (is_same_v<T,\
    \ char>) {\n        return style(string(\"'\") + val + \"'\", value_st);\n   \
    \ } else if constexpr (is_same_v<T, string>) {\n        return style('\"' + val\
    \ + '\"', value_st);\n    } else if constexpr (Stringable<T>) {\n        return\
    \ style(to_string(val), value_st);\n    } else if constexpr (TupleLike<T>) {\n\
    \        string res;\n\n        apply([&](auto &&...args) {\n            ((res\
    \ += (style(res.empty() ? \"\" : delimiter, punct_st) + format(args))), ...);\n\
    \        }, val);\n\n        res = style(open_br, punct_st) + res + style(close_br,\
    \ punct_st);\n        return res;\n    } else if constexpr (Iterable<T>) {\n \
    \       string res;\n\n        if constexpr (Table<T>) {\n            const int\
    \ n = sz(val);\n\n            vector<vector<string>> table(n);\n            int\
    \ cols = 0;\n            for (int i = 0; i < n; i++) {\n                table[i].resize(sz(val[i]));\n\
    \                cols = max(cols, sz(val[i]));\n                for (int j = 0;\
    \ j < sz(val[i]); j++) {\n                    table[i][j] = format(val[i][j]);\n\
    \                }\n            }\n\n            bool is_grid = true;\n      \
    \      for (int i = 0; i < n; i++) {\n                is_grid &= sz(val[i]) ==\
    \ cols;\n            }\n\n            if (is_grid) {\n                for (int\
    \ i = 0; i < cols; i++) {\n                    int col_width = 0;\n          \
    \          for (int j = 0; j < n; j++) {\n                        if (i < sz(table[j]))\
    \ {\n                            col_width = max(col_width, sz(table[j][i]));\n\
    \                        }\n                    }\n                    for (int\
    \ j = 0; j < n; j++) {\n                        if (i < sz(table[j])) {\n    \
    \                        table[j][i] = string(col_width - ssize(table[j][i]),\
    \ ' ') + table[j][i];\n                        }\n                    }\n    \
    \            }\n            }\n\n            res += '\\n';\n            for (int\
    \ i = 0; i < n; i++) {\n                if (i > 0) {\n                    res\
    \ += style(delimiter + \"\\n\", punct_st);\n                }\n              \
    \  res += indent + style(open_br, punct_st);\n                for (int j = 0;\
    \ j < sz(table[i]); j++) {\n                    if (j > 0) {\n               \
    \         res += style(delimiter, punct_st);\n                    }\n        \
    \            res += table[i][j];\n                }\n                res += style(close_br,\
    \ punct_st);\n            }\n            res += '\\n';\n        } else {\n   \
    \         bool first = true;\n            for (const auto &x : val) {\n      \
    \          if (!first) {\n                    res += style(delimiter, punct_st);\n\
    \                }\n                res += format(x);\n                first =\
    \ false;\n            }\n        }\n        \n        res = style(open_br, punct_st)\
    \ + res + style(close_br, punct_st);\n        return res;\n    } else {\n    \
    \    throw invalid_argument(\"Invalid type\");\n    }\n}\n\ntemplate <class ...Args>\n\
    void print(string file, const string func, const int line, const string &s, const\
    \ Args &...vals) {\n    if (!full_path) {\n        file = file.substr(file.rfind('/')\
    \ + 1, sz(file));\n    }\n\n    string res = style(\"Line #\" + to_string(line)\
    \ + \" of \" + file + \", in \" + func + \":\\n\", metadata_st);\n\n    parser\
    \ p(s);\n\n    auto format_single = [&](const auto &cur) {\n        int start\
    \ = p.pos;\n        while ((p.get() != ',' || p.layer()) && p.next());\n\n   \
    \     string label = s.substr(start, p.pos - start);\n        p.next();\n\n  \
    \      for (int i = 0; i < 2; i++) {\n            while (!label.empty() && isspace(label.back()))\
    \ {\n                label.pop_back();\n            }\n            reverse(label.begin(),\
    \ label.end());\n        }\n\n        if (start > 0) {\n            res += style(divider,\
    \ punct_st);\n        }\n\n        // Handle string literals separately\n    \
    \    if (label[0] == '\"' && label.back() == '\"' && count(label.begin(), label.end(),\
    \ '\"') == 2) {\n            res += style(label.substr(1, sz(label) - 2), literal_st);\n\
    \            return;\n        }\n\n        // Try to find shape\n        res +=\
    \ style(label, param_st);\n\n        auto shape = find_shape(cur);\n        if\
    \ (sz(shape) >= 2) {\n            for (int x : shape) {\n                if (x\
    \ == 0) {\n                    break;\n                }\n                if (x\
    \ == -1) {\n                    res += style(\"(...)\", type_st);\n          \
    \          break;\n                }\n                res += style('[' + to_string(x)\
    \ + ']', type_st);\n            }\n        }\n        \n        res += style(\"\
    \ = \", punct_st) + format(cur);\n    };\n\n    (format_single(vals), ...);\n\n\
    \    std::cerr << res << std::endl;\n}\n\n} // namespace cp_utils\n\n#define dbg(...)\
    \ cp_utils::print(__FILE__, __func__, __LINE__, #__VA_ARGS__, __VA_ARGS__)\n\n\
    #endif // DEBUG_H"
  dependsOn: []
  isVerificationFile: false
  path: utils/debug.h
  requiredBy:
  - template/template.h
  timestamp: '2024-12-02 22:41:32-05:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu/alds1/binary_search.test.cpp
  - verify/aizu/alds1/number_of_inversions.test.cpp
  - verify/aizu/ntl/power.test.cpp
  - verify/aizu/dsl/rmq.test.cpp
  - verify/aizu/dsl/rsq_and_raq.test.cpp
  - verify/library_checker/number_theory/enumerate_primes.test.cpp
  - verify/library_checker/data_structure/static_rmq.test.cpp
  - verify/library_checker/data_structure/set_xor_min.test.cpp
  - verify/library_checker/data_structure/point_add_range_sum.test.cpp
  - verify/library_checker/data_structure/unionfind.test.cpp
  - verify/library_checker/data_structure/static_range_mode_query.test.cpp
  - verify/library_checker/data_structure/range_kth_smallest.test.cpp
  - verify/library_checker/data_structure/associative_array.test.cpp
  - verify/library_checker/string/suffix_array.test.cpp
  - verify/library_checker/string/enumerate_palindromes.test.cpp
  - verify/library_checker/graph/shortest_path.test.cpp
  - verify/library_checker/graph/scc.test.cpp
  - verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
  - verify/library_checker/tree/lca.test.cpp
  - verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
documentation_of: utils/debug.h
layout: document
redirect_from:
- /library/utils/debug.h
- /library/utils/debug.h.html
title: utils/debug.h
---
