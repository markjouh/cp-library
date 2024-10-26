---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: geometry/primitives.h
    title: geometry/primitives.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"geometry/primitives.h\"\ntemplate <class T>\nusing prod_t\
    \ = conditional_t<is_same_v<T, int>, ll, conditional_t<is_same_v<T, ll>, __int128_t,\
    \ T>>;\n\ntemplate <class T>\nbool safe_eq(T a, T b = 0) {\n    static constexpr\
    \ ld EPS = 1e-9;\n    if constexpr (is_floating_point_v<T>) {\n        return\
    \ abs(a - b) < EPS;\n    }\n    return a == b;\n}\n\ntemplate <class T>\nstruct\
    \ Point {\n    T x, y;\n\n    Point(T x_ = 0, T y_ = 0) : x(x_), y(y_) {}\n\n\
    \    template <class U>\n    operator Point<U>() const {\n        return Point<U>(static_cast<U>(x),\
    \ static_cast<U>(y));\n    }\n\n    // Cast b onto the line colinear to a and\
    \ multiply their magnitudes\n    // Is b pointing in the same direction as a?\n\
    \    friend prod_t<T> operator*(Point a, const Point &b) {\n        return prod_t<T>(a.x)\
    \ * b.x + prod_t<T>(a.y) * b.y;\n    }\n    // Align a horizontally along the\
    \ x axis and integrate the parallelogram\n    // Which side of a is b on?\n  \
    \  friend prod_t<T> operator^(Point a, const Point &b) {\n        return prod_t<T>(a.x)\
    \ * b.y - prod_t<T>(a.y) * b.x;\n    }\n\n    Point &operator+=(const Point &b)\
    \ {\n        x += b.x, y += b.y;\n        return *this;\n    }\n    Point &operator-=(const\
    \ Point &b) {\n        x -= b.x, y -= b.y;\n        return *this;\n    }\n   \
    \ Point &operator*=(T fac) {\n        x *= fac, y *= fac;\n        return *this;\n\
    \    }\n    Point &operator/=(T fac) {\n        x /= fac, y /= fac;\n        return\
    \ *this;\n    }\n    friend Point operator+(Point a, const Point &b) {\n     \
    \   return a += b;\n    }\n    friend Point operator-(Point a, const Point &b)\
    \ {\n        return a -= b;\n    }\n    friend Point operator*(Point a, T b) {\n\
    \        return a *= b;\n    }\n    friend Point operator/(Point a, T b) {\n \
    \       return a /= b;\n    }\n    friend bool operator<(const Point &a, const\
    \ Point &b) {\n        return a.x < b.x || (a.x == b.x && a.y < b.y);\n    }\n\
    \    friend bool operator>(const Point &a, const Point &b) {\n        return b\
    \ < a;\n    }\n    friend bool operator==(const Point &a, const Point &b) {\n\
    \        return a.x == b.x && a.y == b.y;\n    }\n    friend bool operator!=(const\
    \ Point &a, const Point &b) {\n        return !(a == b);\n    }\n    int side()\
    \ const {\n        return y < 0 ? -1 : y == 0 && x >= 0 ? 0 : 1;\n    }\n    friend\
    \ bool comp_angle(const Point &a, const Point &b) {\n        return a.side() <\
    \ b.side() || (a.side() == b.side() && (a ^ b) > 0);\n    }\n    friend prod_t<T>\
    \ mag_sq(const Point &a) {\n        return a * a;\n    }\n    friend ld mag(const\
    \ Point &a) {\n        return sqrt(mag_sq(a));\n    }\n    friend prod_t<T> dist_sq(const\
    \ Point &a, const Point &b) {\n        return mag_sq(a - b);\n    }\n    friend\
    \ ld dist(const Point &a, const Point &b) {\n        return mag(a - b);\n    }\n\
    \    friend istream &operator>>(istream &is, Point &a) {\n        return is >>\
    \ a.x >> a.y;\n    }\n    friend ostream &operator<<(ostream &os, const Point\
    \ &a) {\n        return os << '(' << a.x << \", \" << a.y << ')';\n    }\n};\n\
    \ntemplate <class T>\nstruct Line {\n    Point<T> p, d;\n\n    Line(Point<T> a\
    \ = Point<T>()) : p(Point<T>()), d(a) {}\n    Line(Point<T> a, Point<T> b, bool\
    \ ends = true) : p(a), d(ends ? b - a : b) {}\n\n    bool operator<(const Line\
    \ &b) const {\n        return comp_angle(this->d, b.d);\n    }\n    bool operator>(const\
    \ Line &b) const {\n        return b < *this;\n    }\n\n    friend ostream &operator<<(ostream\
    \ &os, const Line &a) {\n        return os << a.p << \" + t\" << a.d;\n    }\n\
    };\n\ntemplate <class T>\nbool on_line(const Point<T> &p, const Line<T> &l) {\n\
    \    return safe_eq((p - l.p) ^ l.d);\n}\n\ntemplate <class T>\nbool on_seg(const\
    \ Point<T> &p, const Line<T> &s) {\n    auto vec_a = (s.p - p), vec_b = (s.p +\
    \ s.d - p);\n    return safe_eq(vec_a ^ vec_b) && (vec_a * vec_b) <= 0;\n}\n\n\
    template <class T>\nld dist_line(const Point<T> &p, const Line<T> &l) {\n    return\
    \ abs((p - l.p) ^ l.d) / mag(l);\n}\n\ntemplate <class T>\nld dist_seg(const Point<T>\
    \ &p, const Line<T> &s) {\n    if ((p - s.p) * s.d <= 0) {\n        return dist(p,\
    \ s.p);\n    }\n    if ((p - s.p - s.d) * s.d >= 0) {\n        return dist(p,\
    \ s.p + s.d);\n    }\n    return dist_line(p, s);\n}\n\ntemplate <class T>\nPoint<ld>\
    \ project_line(const Point<T> &p, const Line<T> &l) {\n    return Point<ld>(l.p)\
    \ + Point<ld>(l.d) * ((p - l.p) * l.d) / mag_sq(l);\n}\n\ntemplate <class T>\n\
    Point<ld> project_seg(const Point<T> &p, const Line<T> &s) {\n    if ((p - s.p)\
    \ * s.d <= 0) {\n        return s.p;\n    }\n    if ((p - s.p - s.d) * s.d >=\
    \ 0) {\n        return s.p + s.d;\n    }\n    return project_line(p, s);\n}\n\n\
    template <class L>\npair<int, Point<ld>> inter_lines(const L &a, const L &b) {\n\
    \    if (safe_eq(a.d ^ b.d)) return {-safe_eq(a.d ^ (b.p + b.d - a.p)), Point<ld>()};\n\
    \    return Point<ld>(a.p) + Point<ld>(a.d) * ((b.p - a.p) ^ b.d) / (a.d ^ b.d);\n\
    }\n\ntemplate <class L>\nvector<Point<ld>> inter_segs(const L &a, const L &b)\
    \ {\n    auto den = a.d ^ b.d;\n    if (safe_eq(den)) {\n        if (a.d ^ (b.p\
    \ + b.d - a.p)) {\n            return {};\n        }\n\n        auto s1 = a.p,\
    \ e1 = a.p + a.d, s2 = b.p, e2 = b.p + b.d;\n        if (e1 < s1) {\n        \
    \    swap(s1, e1);\n        }\n        if (e2 < s2) {\n            swap(s2, e2);\n\
    \        }\n\n        auto l = max(s1, s2), r = min(e1, e2);\n        if (r <\
    \ l) {\n            return {};\n        }\n        if (l == r) {\n           \
    \ return {l};\n        }\n        return {l, r}; // Segment from l to r\n    }\n\
    \n    auto num_a = (b.p - a.p) ^ b.d, num_b = (a.p - b.p) ^ a.d;\n    den < 0\
    \ ? den *= -1, num_a *= -1 : num_b *= -1;\n    if (num_a < 0 || num_a > den ||\
    \ num_b < 0 || num_b > den) {\n        return {};\n    }\n    return {Point<ld>(a.p)\
    \ + Point<ld>(a.d) * num_a / den};\n}\n\ntemplate <class T>\nauto area_poly(const\
    \ vector<Point<T>> &v) {\n    prod_t<T> res = v.back() ^ v[0];\n    for (int i\
    \ = 0; i < sz(v) - 1; i++) {\n        res += v[i] ^ v[i + 1];\n    }\n    return\
    \ abs(res); // Twice the area!\n}\n\ntemplate <class P>\nint in_poly(const P &p,\
    \ const vector<P> &v) {\n    bool res = 0;\n    for (int i = 0; i < sz(v); i++)\
    \ {\n        auto nxt = v[i == sz(v) - 1 ? 0 : i + 1];\n        auto seg = Line(v[i],\
    \ nxt);\n        if (on_seg(p, seg)) {\n            return -1;\n        }\n  \
    \      res ^= ((p.y < v[i].y) - (p.y < nxt.y)) * ((v[i] - p) ^ (nxt - p)) > 0;\n\
    \    }\n    return res;\n}\n#line 2 \"geometry/integer_lattice.h\"\n\ntemplate\
    \ <class T>\nT lattice_seg(const Point<T> &s) {\n    auto a = s.p, b = s.p + s.d;\n\
    \    return gcd(b.x - a.x, b.y - a.y); // (inside, on boundary)\n}\n\ntemplate\
    \ <class T>\npair<ll, ll> lattice_poly(const vector<Point<T>> &v) {\n    pair<ll,\
    \ ll> res;\n    for (int i = 0; i < sz(v); i++) {\n        auto nxt = v[i == sz(v)\
    \ - 1 ? 0 : i + 1];\n        auto seg = Line<T>(v[i], nxt);\n        res.first\
    \ += v[i] ^ nxt;\n        res.second += lattice_seg(seg);\n    }\n    res.first\
    \ = (abs(res.first) - res.second + 2) / 2;\n    return res;\n}\n"
  code: "#include \"primitives.h\"\n\ntemplate <class T>\nT lattice_seg(const Point<T>\
    \ &s) {\n    auto a = s.p, b = s.p + s.d;\n    return gcd(b.x - a.x, b.y - a.y);\
    \ // (inside, on boundary)\n}\n\ntemplate <class T>\npair<ll, ll> lattice_poly(const\
    \ vector<Point<T>> &v) {\n    pair<ll, ll> res;\n    for (int i = 0; i < sz(v);\
    \ i++) {\n        auto nxt = v[i == sz(v) - 1 ? 0 : i + 1];\n        auto seg\
    \ = Line<T>(v[i], nxt);\n        res.first += v[i] ^ nxt;\n        res.second\
    \ += lattice_seg(seg);\n    }\n    res.first = (abs(res.first) - res.second +\
    \ 2) / 2;\n    return res;\n}"
  dependsOn:
  - geometry/primitives.h
  isVerificationFile: false
  path: geometry/integer_lattice.h
  requiredBy: []
  timestamp: '2024-10-25 20:01:05-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/integer_lattice.h
layout: document
redirect_from:
- /library/geometry/integer_lattice.h
- /library/geometry/integer_lattice.h.html
title: geometry/integer_lattice.h
---
