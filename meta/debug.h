#include <bits/stdc++.h>
#include <ranges>
#include <type_traits>

using namespace std;

template<typename T>
concept is_core = requires(T x) {
    cerr << x;
};

template<typename T>
concept is_iterable = ranges::range<T>;

template<typename T>
concept is_pair = requires(T x) {
    x.first;
    x.second;
};

template<typename T>
void print(T x) {
    if constexpr (is_core<T>) {
        cerr << x;
    } else if constexpr (is_pair<T>) {
        cerr << '(';
        print(x.first);
        cerr << ", ";
        print(x.second);
        cerr << ')';
    } else if constexpr (is_iterable<T>) {
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

template<typename T>
void print_debug(string s, T x) {
    cerr << s << " = ";
    print(x);
    cerr << endl;
}

template<typename T, typename... Args>
void print_debug(string s, T x, Args... args) {
    int idx = 0, layer = 0;
    while (idx < ssize(s) && (s[idx] != ',' || layer != 0)) {
        layer += s[idx] == '(' || s[idx] == '{';
        layer -= s[idx] == ')' || s[idx] == '}';
        idx++;
    }

    cerr << s.substr(0, idx) << " = ";
    print(x);
    cerr << " | ";
    print_debug(s.substr(s.find_first_not_of(' ', idx + 1)), args...);
}

#ifdef LOCAL
#define debug(...) print_debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#endif
