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
  bundledCode: "#line 1 \"heuristic/simulated_annealing.h\"\nstruct state {\n    //\
    \ ...\n\n    state() {\n    }\n\n    void edit() {\n    }\n\n    void undo() {\n\
    \    }\n\n    int eval() const {\n    }\n};\n\nstate anneal(int ms) {\n    const\
    \ double temp_start = 10, temp_end = 0.001;\n    clock_t start = clock();\n\n\
    \    state cur;\n    int cur_cost = cur.eval(), new_cost, mn_cost = cur_cost;\n\
    \    while (true) {\n        double elapsed_frac = double(clock() - start) / CLOCKS_PER_SEC\
    \ * 1000 / ms;\n        if (elapsed_frac >= 1) {\n            break;\n       \
    \ }\n\n        cur.edit();\n        new_cost = cur.eval();\n\n        double temp\
    \ = temp_start * pow(temp_end / temp_start, elapsed_frac);\n        if (new_cost\
    \ < cur_cost || double(rand()) / RAND_MAX < exp((cur_cost - new_cost) / temp))\
    \ {\n            cur_cost = new_cost;\n        } else {\n            cur.undo();\n\
    \        }\n\n        mn_cost = min(mn_cost, cur_cost);\n    }\n    return cur;\n\
    }\n"
  code: "struct state {\n    // ...\n\n    state() {\n    }\n\n    void edit() {\n\
    \    }\n\n    void undo() {\n    }\n\n    int eval() const {\n    }\n};\n\nstate\
    \ anneal(int ms) {\n    const double temp_start = 10, temp_end = 0.001;\n    clock_t\
    \ start = clock();\n\n    state cur;\n    int cur_cost = cur.eval(), new_cost,\
    \ mn_cost = cur_cost;\n    while (true) {\n        double elapsed_frac = double(clock()\
    \ - start) / CLOCKS_PER_SEC * 1000 / ms;\n        if (elapsed_frac >= 1) {\n \
    \           break;\n        }\n\n        cur.edit();\n        new_cost = cur.eval();\n\
    \n        double temp = temp_start * pow(temp_end / temp_start, elapsed_frac);\n\
    \        if (new_cost < cur_cost || double(rand()) / RAND_MAX < exp((cur_cost\
    \ - new_cost) / temp)) {\n            cur_cost = new_cost;\n        } else {\n\
    \            cur.undo();\n        }\n\n        mn_cost = min(mn_cost, cur_cost);\n\
    \    }\n    return cur;\n}"
  dependsOn: []
  isVerificationFile: false
  path: heuristic/simulated_annealing.h
  requiredBy: []
  timestamp: '2024-12-02 22:41:32-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: heuristic/simulated_annealing.h
layout: document
redirect_from:
- /library/heuristic/simulated_annealing.h
- /library/heuristic/simulated_annealing.h.html
title: heuristic/simulated_annealing.h
---
