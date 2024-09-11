#pragma once

namespace debug_internal {

using namespace std;

template <typename T>
concept isCore = requires(T x) {
  cerr << x;
};

template <typename T>
concept isPair = requires(T x) {
  x.first;
  x.second;
};

template <typename T>
concept isIterable = ranges::range<T>;

template <typename T>
void print(T x) {
  if constexpr (isCore<T>) {
    cerr << x;
  } else if constexpr (isPair<T>) {
    cerr << '(';
    print(x.first);
    cerr << ", ";
    print(x.second);
    cerr << ')';
  } else if constexpr (isIterable<T>) {
    cerr << '[';
    bool flag = false;
    for (auto y : x) {
      if (flag) {
        cerr << ", ";
      }
      print(y);
      flag = true;
    }
    cerr << ']';
  } else {
    cerr << "Unknown type";
  }
}

template <typename T>
void debug(string s, T x) {
  cerr << "\033[1;35m" << s << "\033[0;0m = ";
  print(x);
  cerr << endl;
}

template <typename T, typename... Args>
void debug(string s, T x, Args... args) {
  int idx = 0, layer = 0;
  while (idx < ssize(s) && (s[idx] != ',' || layer != 0)) {
    layer += s[idx] == '(' || s[idx] == '{';
    layer -= s[idx] == ')' || s[idx] == '}';
    idx++;
  }
  cerr << "\033[1;35m" << s.substr(0, idx) << "\033[0;0m = ";
  print(x);
  cerr << "\033[1;32m | \033[0;0m";
  debug(s.substr(s.find_first_not_of(' ', idx + 1)), args...);
}
}

#define dbg(...) debug_internal::debug(#__VA_ARGS__, __VA_ARGS__)
