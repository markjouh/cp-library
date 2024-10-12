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
  bundledCode: "#line 2 \"heuristic/simulated_annealing.h\"\n\ntemplate <class T,\
    \ auto edit, auto undo, auto eval>\nT anneal(int ms) {\n    const double temp_start\
    \ = 10, temp_end = 0.001;\n    clock_t start = clock();\n\n    T cur_cost = eval(),\
    \ new_cost, mn_cost = cur_cost;\n    while (true) {\n        double elapsed_frac\
    \ = double(clock() - start) / CLOCKS_PER_SEC * 1000 / ms;\n        if (elapsed_frac\
    \ >= 1) {\n            break;\n        }\n\n        edit();\n        new_cost\
    \ = eval();\n\n        double temp = temp_start * pow(temp_end / temp_start, elapsed_frac);\n\
    \        if (new_cost < cur_cost || double(rand()) / RAND_MAX < exp((cur_cost\
    \ - new_cost) / temp) {\n            cur_cost = new_cost;\n        } else {\n\
    \            undo();\n        }\n\n        mn_cost = min(mn_cost, cur_cost);\n\
    \    }\n    return mn_cost;\n}\n"
  code: "#pragma once\n\ntemplate <class T, auto edit, auto undo, auto eval>\nT anneal(int\
    \ ms) {\n    const double temp_start = 10, temp_end = 0.001;\n    clock_t start\
    \ = clock();\n\n    T cur_cost = eval(), new_cost, mn_cost = cur_cost;\n    while\
    \ (true) {\n        double elapsed_frac = double(clock() - start) / CLOCKS_PER_SEC\
    \ * 1000 / ms;\n        if (elapsed_frac >= 1) {\n            break;\n       \
    \ }\n\n        edit();\n        new_cost = eval();\n\n        double temp = temp_start\
    \ * pow(temp_end / temp_start, elapsed_frac);\n        if (new_cost < cur_cost\
    \ || double(rand()) / RAND_MAX < exp((cur_cost - new_cost) / temp) {\n       \
    \     cur_cost = new_cost;\n        } else {\n            undo();\n        }\n\
    \n        mn_cost = min(mn_cost, cur_cost);\n    }\n    return mn_cost;\n}"
  dependsOn: []
  isVerificationFile: false
  path: heuristic/simulated_annealing.h
  requiredBy: []
  timestamp: '2024-10-12 02:07:15-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: heuristic/simulated_annealing.h
layout: document
redirect_from:
- /library/heuristic/simulated_annealing.h
- /library/heuristic/simulated_annealing.h.html
title: heuristic/simulated_annealing.h
---
