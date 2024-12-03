#ifndef DEBUG_H
#define DEBUG_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

namespace cp_utils {

using namespace std;

// Options
const bool full_path = false;

// Text formatting (how to separate, put things on same or different lines, etc)
const string delimiter = ", ";
const string divider = ", ";
const string open_br = "{", close_br = "}";
const string indent = "  ";

// Colors
const string metadata_st = "\033[31m";
const string type_st = "\033[35;2m";
const string param_st = "\033[35;1m";
const string punct_st = "\033[32;1m";
const string value_st = "\033[33m";
const string literal_st = "\033[36;1m";
const string reset_st = "\033[0m";

template <class T>
int sz(const T &x) {
    return static_cast<int>(ssize(x));
}

inline string style(const string &s, const string &col) {
    return col + s + reset_st;
}

struct parser {
    string s;
    int pos = 0;
    bool in_sq = 0, in_dq = 0;
    int brackets = 0;

    parser(string t) : s(t) {}

    char get() const {
        return s[pos];
    }
    int layer() const {
        if (in_sq || in_dq) {
            return -1;
        }
        return brackets;
    }

    bool next() {
        if (pos == ssize(s)) {
            return false;
        }
        in_sq ^= s[pos] == '\'' && !in_dq && (pos == 0 || s[pos - 1] != '\\');
        in_dq ^= s[pos] == '\"' && !in_sq && (pos == 0 || s[pos - 1] != '\\');
        if (!in_sq && !in_dq) {
            brackets += string("<([{").find(s[pos]) != string::npos;
            brackets -= string("}])>").find(s[pos]) != string::npos;
        }
        pos++;
        return true;
    }
};

template <class T>
concept Stringable = requires(T x) { to_string(x); };

template <class T>
concept TupleLike = requires(T x) {
    { tuple_size<T>::value };
    { get<0>(x) };
};

template <class T>
concept Iterable = !is_same<T, string>::value && ranges::range<T>;

template <class T>
concept ArrayLike = Iterable<T> && requires(T x) {
    { x[0] };
};

template <class T>
concept Table = ArrayLike<T> && ArrayLike<typename T::value_type> && !ArrayLike<typename T::value_type::value_type>;

template <class T>
vector<int> find_shape(const T &val) {
    if constexpr (Iterable<T>) {
        vector<int> desc;
        for (const auto &x : val) {
            if (desc.empty()) {
                desc = find_shape(x);
            } else if (find_shape(x) != desc) {
                desc = {-1};
                break;
            }
        }
        desc.insert(begin(desc), sz(val));
        return desc;
    } else {
        return {0};
    }
}

template <class T>
string format(const T &val) {
    if constexpr (is_same_v<T, char>) {
        return style(string("'") + val + "'", value_st);
    } else if constexpr (is_same_v<T, string>) {
        return style('"' + val + '"', value_st);
    } else if constexpr (Stringable<T>) {
        return style(to_string(val), value_st);
    } else if constexpr (TupleLike<T>) {
        string res;

        apply([&](auto &&...args) {
            ((res += (style(res.empty() ? "" : delimiter, punct_st) + format(args))), ...);
        }, val);

        res = style(open_br, punct_st) + res + style(close_br, punct_st);
        return res;
    } else if constexpr (Iterable<T>) {
        string res;

        if constexpr (Table<T>) {
            const int n = sz(val);

            vector<vector<string>> table(n);
            int cols = 0;
            for (int i = 0; i < n; i++) {
                table[i].resize(sz(val[i]));
                cols = max(cols, sz(val[i]));
                for (int j = 0; j < sz(val[i]); j++) {
                    table[i][j] = format(val[i][j]);
                }
            }

            bool is_grid = true;
            for (int i = 0; i < n; i++) {
                is_grid &= sz(val[i]) == cols;
            }

            if (is_grid) {
                for (int i = 0; i < cols; i++) {
                    int col_width = 0;
                    for (int j = 0; j < n; j++) {
                        if (i < sz(table[j])) {
                            col_width = max(col_width, sz(table[j][i]));
                        }
                    }
                    for (int j = 0; j < n; j++) {
                        if (i < sz(table[j])) {
                            table[j][i] = string(col_width - ssize(table[j][i]), ' ') + table[j][i];
                        }
                    }
                }
            }

            res += '\n';
            for (int i = 0; i < n; i++) {
                if (i > 0) {
                    res += style(delimiter + "\n", punct_st);
                }
                res += indent + style(open_br, punct_st);
                for (int j = 0; j < sz(table[i]); j++) {
                    if (j > 0) {
                        res += style(delimiter, punct_st);
                    }
                    res += table[i][j];
                }
                res += style(close_br, punct_st);
            }
            res += '\n';
        } else {
            bool first = true;
            for (const auto &x : val) {
                if (!first) {
                    res += style(delimiter, punct_st);
                }
                res += format(x);
                first = false;
            }
        }
        
        res = style(open_br, punct_st) + res + style(close_br, punct_st);
        return res;
    } else {
        throw invalid_argument("Invalid type");
    }
}

template <class ...Args>
void print(string file, const string func, const int line, const string &s, const Args &...vals) {
    if (!full_path) {
        file = file.substr(file.rfind('/') + 1, sz(file));
    }

    string res = style("Line #" + to_string(line) + " of " + file + ", in " + func + ":\n", metadata_st);

    parser p(s);

    auto format_single = [&](const auto &cur) {
        int start = p.pos;
        while ((p.get() != ',' || p.layer()) && p.next());

        string label = s.substr(start, p.pos - start);
        p.next();

        for (int i = 0; i < 2; i++) {
            while (!label.empty() && isspace(label.back())) {
                label.pop_back();
            }
            reverse(label.begin(), label.end());
        }

        if (start > 0) {
            res += style(divider, punct_st);
        }

        // Handle string literals separately
        if (label[0] == '"' && label.back() == '"' && count(label.begin(), label.end(), '"') == 2) {
            res += style(label.substr(1, sz(label) - 2), literal_st);
            return;
        }

        // Try to find shape
        res += style(label, param_st);

        auto shape = find_shape(cur);
        if (sz(shape) >= 2) {
            for (int x : shape) {
                if (x == 0) {
                    break;
                }
                if (x == -1) {
                    res += style("(...)", type_st);
                    break;
                }
                res += style('[' + to_string(x) + ']', type_st);
            }
        }
        
        res += style(" = ", punct_st) + format(cur);
    };

    (format_single(vals), ...);

    std::cerr << res << std::endl;
}

} // namespace cp_utils

#define dbg(...) cp_utils::print(__FILE__, __func__, __LINE__, #__VA_ARGS__, __VA_ARGS__)

#endif // DEBUG_H