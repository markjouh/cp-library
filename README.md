# cp-library
[![Codeforces](https://badges.joonhyung.xyz/codeforces/mark.svg)](https://codeforces.com/profile/mark)
![GitHub last commit](https://img.shields.io/github/last-commit/markjouh/cp-library)
[![Actions Status](https://github.com/markjouh/cp-library/workflows/verify/badge.svg)](https://github.com/markjouh/cp-library/actions)
![GitHub repo size](https://img.shields.io/github/repo-size/markjouh/cp-library)

My library of template code for competitive programming.

## Why
KACTL is very concise, but I really dislike their interfaces. Atcoder Library is very fast and has nice interfaces, but is intended to be included as a black-box and infeasible to type out.

Is this library better? Not really, it's just what works for me.

## Notes
* Inclusive intervals and 0-indexing for all interfaces.
* Templates use features up to C++17, debug header uses C++20. GCC builtins are occasionally used.
* Templates are tested with [verification helper](https://github.com/online-judge-tools/verification-helper) using the solutions in [verify](verify), which can also serve as example usages.
* There's a bit of basic boilerplate code as defined in [template.cpp](local/template.cpp), but it's very minimal.