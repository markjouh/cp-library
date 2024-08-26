# cp-library
[![Codeforces](https://badges.joonhyung.xyz/codeforces/mark.svg)](https://codeforces.com/profile/mark) 

## Goals
Ranked roughly in order...
1. Simple and easy to understand modern C++ code short enough to be typed out during contests.
2. Convenient interfaces. What this looks like is kinda formed from trial and error through implementing a lot of solutions.
3. Good performance. It's nice to have most of your optimization work done in advance!

## Why
KACTL is very concise, but I really dislike their interfaces. Atcoder Library is very fast and has nice interfaces, but is intended to be included as a black-box and infeasible to type out.

Is this library better? Probably not.

## Notes
* Inclusive intervals and 0-indexing for all interfaces.
* Templates use features up to C++17, debug header uses C++20. GCC builtins are occasionally used.
* There's a bit of basic template code as defined in [template.cpp](local/template.cpp), but it's very minimal.
