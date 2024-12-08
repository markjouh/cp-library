template <class T, class = void>
struct is_range : false_type {};
template <class T>
struct is_range<T, void_t<decltype(begin(declval<T>())), decltype(end(declval<T>()))>> : true_type {};
template <class T>
using enable_if_cont = enable_if_t<!is_same<T, string>::value && is_range<T>::value, bool>;

template <class T, class U>
istream &operator>>(istream &is, pair<T, U> &p) {
    is >> p.fi >> p.se;
    return is;
}
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
    os << p.fi << ' ' << p.se;
    return os;
}
template <class T, enable_if_cont<T> = true>
istream &operator>>(istream &is, T &v) {
    for (auto &x : v) {
        is >> x;
    }
    return is;
}
template <class T, enable_if_cont<T> = true>
ostream &operator<<(ostream &os, const T &v) {
    for (int i = 0; i < sz(v); i++) {
        os << v[i];
        if (i != sz(v) - 1) {
            os << (is_range<typename T::value_type>::value ? '\n' : ' ');
        }
    }
    return os;
}

template <class ...T>
void re(T &...a) {
    (cin >> ... >> a);
}
template <class ...T>
void pr(const T &...a) {
    int p = 0;
    ((cout << a << (++p == sizeof...(T) ? '\n' : ' ')), ...);
}