---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: geometry/integer_lattice.h
    title: geometry/integer_lattice.h
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/primitives.h\"\n\n// Geometry primitives. Sticks\
    \ to integer arithmetic when possible - everywhere but point to line & line intersection\
    \ ops.\n// Tested on CSES Geometry (not exhaustive)\n\ntemplate <class T>\nusing\
    \ prod_t = conditional_t<is_same_v<T, int>, ll, conditional_t<is_same_v<T, ll>,\
    \ __int128_t, T>>;\n\ntemplate <class T>\nbool safe_eq(T a, T b = 0) {\n    static\
    \ constexpr ld EPS = 1e-9;\n    if constexpr (is_floating_point_v<T>) return abs(a\
    \ - b) < EPS;\n    return a == b;\n}\n\ntemplate <class T>\nstruct Point {\n \
    \   T x, y;\n\n    Point(T x_ = 0, T y_ = 0) : x(x_), y(y_) {}\n\n    template\
    \ <class U>\n    operator Point<U>() const { return Point<U>(static_cast<U>(x),\
    \ static_cast<U>(y)); }\n\n    Point &operator+=(const Point &b) { x += b.x, y\
    \ += b.y; return *this; }\n    Point &operator-=(const Point &b) { x -= b.x, y\
    \ -= b.y; return *this; }\n    Point &operator*=(T fac) { x *= fac, y *= fac;\
    \ return *this; }\n    Point &operator/=(T fac) { x /= fac, y /= fac; return *this;\
    \ }\n\n    // Cast b onto the line colinear to a and multiply their magnitudes\n\
    \    // Is b pointing in the same direction as a?\n    friend prod_t<T> operator*(Point\
    \ a, const Point &b) {\n        return prod_t<T>(a.x) * b.x + prod_t<T>(a.y) *\
    \ b.y;\n    }\n\n    // Align a horizontally along the x axis and integrate the\
    \ parallelogram\n    // Which side of a is b on?\n    friend prod_t<T> operator^(Point\
    \ a, const Point &b) {\n        return prod_t<T>(a.x) * b.y - prod_t<T>(a.y) *\
    \ b.x;\n    }\n\n    friend Point operator+(Point a, const Point &b) { return\
    \ a += b; }\n    friend Point operator-(Point a, const Point &b) { return a -=\
    \ b; }\n    friend Point operator*(Point a, T b) { return a *= b; }\n    friend\
    \ Point operator/(Point a, T b) { return a /= b; }\n\n    bool operator<(const\
    \ Point &b) const { return this->x < b.x || (this->x == b.x && this->y < b.y);\
    \ }\n    bool operator>(const Point &b) const { return b < *this; }\n    bool\
    \ operator==(const Point &b) const { return this->x == b.x && this->y == b.y;\
    \ }\n    bool operator!=(const Point &b) const { return !(*this == b); }\n\n \
    \   int side() const { return y < 0 ? -1 : y == 0 && x >= 0 ? 0 : 1; }\n    friend\
    \ bool comp_angle(const Point &a, const Point &b) { return a.side() < b.side()\
    \ || (a.side() == b.side() && (a ^ b) > 0); }\n\n    friend prod_t<T> mag_sq(const\
    \ Point &a) { return a * a; }\n    friend ld mag(const Point &a) { return sqrt(mag_sq(a));\
    \ }\n    friend prod_t<T> dist_sq(const Point &a, const Point &b) { return mag_sq(a\
    \ - b); }\n    friend ld dist(const Point &a, const Point &b) { return mag(a -\
    \ b); }\n\n    friend istream &operator>>(istream &is, Point &a) { return is >>\
    \ a.x >> a.y; }\n    friend ostream &operator<<(ostream &os, const Point &a) {\
    \ return os << '(' << a.x << \", \" << a.y << ')'; }\n};\n\ntemplate <class T>\n\
    struct Line {\n    Point<T> p, d;\n\n    Line(Point<T> a = Point<T>()) : p(Point<T>()),\
    \ d(a) {}\n    Line(Point<T> a, Point<T> b, bool ends = true) : p(a), d(ends ?\
    \ b - a : b) {}\n\n    bool operator<(const Line &b) const { return comp_angle(this->d,\
    \ b.d); }\n    bool operator>(const Line &b) const { return b < *this; }\n\n \
    \   friend ostream &operator<<(ostream &os, const Line &a) { return os << a.p\
    \ << \" + t\" << a.d; }\n};\n\ntemplate <class T>\nbool on_line(const Point<T>\
    \ &p, const Line<T> &l) {\n    return safe_eq((p - l.p) ^ l.d);\n}\n\ntemplate\
    \ <class T>\nbool on_seg(const Point<T> &p, const Line<T> &s) {\n    auto vec_a\
    \ = (s.p - p), vec_b = (s.p + s.d - p);\n    return safe_eq(vec_a ^ vec_b) &&\
    \ (vec_a * vec_b) <= 0;\n}\n\ntemplate <class T>\nld dist_line(const Point<T>\
    \ &p, const Line<T> &l) {\n    return abs((p - l.p) ^ l.d) / mag(l);\n}\n\ntemplate\
    \ <class T>\nld dist_seg(const Point<T> &p, const Line<T> &s) {\n    if ((p -\
    \ s.p) * s.d <= 0) return dist(p, s.p);\n    if ((p - s.p - s.d) * s.d >= 0) return\
    \ dist(p, s.p + s.d);\n    return dist_line(p, s);\n}\n\ntemplate <class T>\n\
    Point<ld> project_line(const Point<T> &p, const Line<T> &l) {\n    return Point<ld>(l.p)\
    \ + Point<ld>(l.d) * ((p - l.p) * l.d) / mag_sq(l);\n}\n\ntemplate <class T>\n\
    Point<ld> project_seg(const Point<T> &p, const Line<T> &s) {\n    if ((p - s.p)\
    \ * s.d <= 0) return s.p;\n    if ((p - s.p - s.d) * s.d >= 0) return s.p + s.d;\n\
    \    return project_line(p, s);\n}\n\ntemplate <class L>\npair<int, Point<ld>>\
    \ inter_lines(const L &a, const L &b) {\n    if (safe_eq(a.d ^ b.d)) return {-safe_eq(a.d\
    \ ^ (b.p + b.d - a.p)), Point<ld>()};\n    return Point<ld>(a.p) + Point<ld>(a.d)\
    \ * ((b.p - a.p) ^ b.d) / (a.d ^ b.d);\n}\n\ntemplate <class L>\nvector<Point<ld>>\
    \ inter_segs(const L &a, const L &b) {\n    auto den = a.d ^ b.d;\n    if (safe_eq(den))\
    \ {\n        if (a.d ^ (b.p + b.d - a.p)) return {};\n        auto s1 = a.p, e1\
    \ = a.p + a.d, s2 = b.p, e2 = b.p + b.d;\n        if (e1 < s1) swap(s1, e1);\n\
    \        if (e2 < s2) swap(s2, e2);\n        auto l = max(s1, s2), r = min(e1,\
    \ e2);\n        if (r < l) return {};\n        if (l == r) return {l}; \n    \
    \    return {l, r}; // Segment from l to r\n    }\n    auto num_a = (b.p - a.p)\
    \ ^ b.d, num_b = (a.p - b.p) ^ a.d;\n    den < 0 ? den *= -1, num_a *= -1 : num_b\
    \ *= -1;\n    if (num_a < 0 || num_a > den || num_b < 0 || num_b > den) return\
    \ {};\n    return {Point<ld>(a.p) + Point<ld>(a.d) * num_a / den};\n}\n\ntemplate\
    \ <class T>\nauto area_poly(const vector<Point<T>> &v) {\n    prod_t<T> res =\
    \ v.back() ^ v[0];\n    for (int i = 0; i < sz(v) - 1; i++) {\n        res +=\
    \ v[i] ^ v[i + 1];\n    }\n    return abs(res); // Twice the area!\n}\n\ntemplate\
    \ <class P>\nint in_poly(const P &p, const vector<P> &v) {\n    bool res = 0;\n\
    \    for (int i = 0; i < sz(v); i++) {\n        auto nxt = v[i == sz(v) - 1 ?\
    \ 0 : i + 1];\n        auto seg = Line(v[i], nxt);\n        if (on_seg(p, seg))\
    \ return -1;\n        res ^= ((p.y < v[i].y) - (p.y < nxt.y)) * ((v[i] - p) ^\
    \ (nxt - p)) > 0;\n    }\n    return res;\n}\n"
  code: "#pragma once\n\n// Geometry primitives. Sticks to integer arithmetic when\
    \ possible - everywhere but point to line & line intersection ops.\n// Tested\
    \ on CSES Geometry (not exhaustive)\n\ntemplate <class T>\nusing prod_t = conditional_t<is_same_v<T,\
    \ int>, ll, conditional_t<is_same_v<T, ll>, __int128_t, T>>;\n\ntemplate <class\
    \ T>\nbool safe_eq(T a, T b = 0) {\n    static constexpr ld EPS = 1e-9;\n    if\
    \ constexpr (is_floating_point_v<T>) return abs(a - b) < EPS;\n    return a ==\
    \ b;\n}\n\ntemplate <class T>\nstruct Point {\n    T x, y;\n\n    Point(T x_ =\
    \ 0, T y_ = 0) : x(x_), y(y_) {}\n\n    template <class U>\n    operator Point<U>()\
    \ const { return Point<U>(static_cast<U>(x), static_cast<U>(y)); }\n\n    Point\
    \ &operator+=(const Point &b) { x += b.x, y += b.y; return *this; }\n    Point\
    \ &operator-=(const Point &b) { x -= b.x, y -= b.y; return *this; }\n    Point\
    \ &operator*=(T fac) { x *= fac, y *= fac; return *this; }\n    Point &operator/=(T\
    \ fac) { x /= fac, y /= fac; return *this; }\n\n    // Cast b onto the line colinear\
    \ to a and multiply their magnitudes\n    // Is b pointing in the same direction\
    \ as a?\n    friend prod_t<T> operator*(Point a, const Point &b) {\n        return\
    \ prod_t<T>(a.x) * b.x + prod_t<T>(a.y) * b.y;\n    }\n\n    // Align a horizontally\
    \ along the x axis and integrate the parallelogram\n    // Which side of a is\
    \ b on?\n    friend prod_t<T> operator^(Point a, const Point &b) {\n        return\
    \ prod_t<T>(a.x) * b.y - prod_t<T>(a.y) * b.x;\n    }\n\n    friend Point operator+(Point\
    \ a, const Point &b) { return a += b; }\n    friend Point operator-(Point a, const\
    \ Point &b) { return a -= b; }\n    friend Point operator*(Point a, T b) { return\
    \ a *= b; }\n    friend Point operator/(Point a, T b) { return a /= b; }\n\n \
    \   bool operator<(const Point &b) const { return this->x < b.x || (this->x ==\
    \ b.x && this->y < b.y); }\n    bool operator>(const Point &b) const { return\
    \ b < *this; }\n    bool operator==(const Point &b) const { return this->x ==\
    \ b.x && this->y == b.y; }\n    bool operator!=(const Point &b) const { return\
    \ !(*this == b); }\n\n    int side() const { return y < 0 ? -1 : y == 0 && x >=\
    \ 0 ? 0 : 1; }\n    friend bool comp_angle(const Point &a, const Point &b) { return\
    \ a.side() < b.side() || (a.side() == b.side() && (a ^ b) > 0); }\n\n    friend\
    \ prod_t<T> mag_sq(const Point &a) { return a * a; }\n    friend ld mag(const\
    \ Point &a) { return sqrt(mag_sq(a)); }\n    friend prod_t<T> dist_sq(const Point\
    \ &a, const Point &b) { return mag_sq(a - b); }\n    friend ld dist(const Point\
    \ &a, const Point &b) { return mag(a - b); }\n\n    friend istream &operator>>(istream\
    \ &is, Point &a) { return is >> a.x >> a.y; }\n    friend ostream &operator<<(ostream\
    \ &os, const Point &a) { return os << '(' << a.x << \", \" << a.y << ')'; }\n\
    };\n\ntemplate <class T>\nstruct Line {\n    Point<T> p, d;\n\n    Line(Point<T>\
    \ a = Point<T>()) : p(Point<T>()), d(a) {}\n    Line(Point<T> a, Point<T> b, bool\
    \ ends = true) : p(a), d(ends ? b - a : b) {}\n\n    bool operator<(const Line\
    \ &b) const { return comp_angle(this->d, b.d); }\n    bool operator>(const Line\
    \ &b) const { return b < *this; }\n\n    friend ostream &operator<<(ostream &os,\
    \ const Line &a) { return os << a.p << \" + t\" << a.d; }\n};\n\ntemplate <class\
    \ T>\nbool on_line(const Point<T> &p, const Line<T> &l) {\n    return safe_eq((p\
    \ - l.p) ^ l.d);\n}\n\ntemplate <class T>\nbool on_seg(const Point<T> &p, const\
    \ Line<T> &s) {\n    auto vec_a = (s.p - p), vec_b = (s.p + s.d - p);\n    return\
    \ safe_eq(vec_a ^ vec_b) && (vec_a * vec_b) <= 0;\n}\n\ntemplate <class T>\nld\
    \ dist_line(const Point<T> &p, const Line<T> &l) {\n    return abs((p - l.p) ^\
    \ l.d) / mag(l);\n}\n\ntemplate <class T>\nld dist_seg(const Point<T> &p, const\
    \ Line<T> &s) {\n    if ((p - s.p) * s.d <= 0) return dist(p, s.p);\n    if ((p\
    \ - s.p - s.d) * s.d >= 0) return dist(p, s.p + s.d);\n    return dist_line(p,\
    \ s);\n}\n\ntemplate <class T>\nPoint<ld> project_line(const Point<T> &p, const\
    \ Line<T> &l) {\n    return Point<ld>(l.p) + Point<ld>(l.d) * ((p - l.p) * l.d)\
    \ / mag_sq(l);\n}\n\ntemplate <class T>\nPoint<ld> project_seg(const Point<T>\
    \ &p, const Line<T> &s) {\n    if ((p - s.p) * s.d <= 0) return s.p;\n    if ((p\
    \ - s.p - s.d) * s.d >= 0) return s.p + s.d;\n    return project_line(p, s);\n\
    }\n\ntemplate <class L>\npair<int, Point<ld>> inter_lines(const L &a, const L\
    \ &b) {\n    if (safe_eq(a.d ^ b.d)) return {-safe_eq(a.d ^ (b.p + b.d - a.p)),\
    \ Point<ld>()};\n    return Point<ld>(a.p) + Point<ld>(a.d) * ((b.p - a.p) ^ b.d)\
    \ / (a.d ^ b.d);\n}\n\ntemplate <class L>\nvector<Point<ld>> inter_segs(const\
    \ L &a, const L &b) {\n    auto den = a.d ^ b.d;\n    if (safe_eq(den)) {\n  \
    \      if (a.d ^ (b.p + b.d - a.p)) return {};\n        auto s1 = a.p, e1 = a.p\
    \ + a.d, s2 = b.p, e2 = b.p + b.d;\n        if (e1 < s1) swap(s1, e1);\n     \
    \   if (e2 < s2) swap(s2, e2);\n        auto l = max(s1, s2), r = min(e1, e2);\n\
    \        if (r < l) return {};\n        if (l == r) return {l}; \n        return\
    \ {l, r}; // Segment from l to r\n    }\n    auto num_a = (b.p - a.p) ^ b.d, num_b\
    \ = (a.p - b.p) ^ a.d;\n    den < 0 ? den *= -1, num_a *= -1 : num_b *= -1;\n\
    \    if (num_a < 0 || num_a > den || num_b < 0 || num_b > den) return {};\n  \
    \  return {Point<ld>(a.p) + Point<ld>(a.d) * num_a / den};\n}\n\ntemplate <class\
    \ T>\nauto area_poly(const vector<Point<T>> &v) {\n    prod_t<T> res = v.back()\
    \ ^ v[0];\n    for (int i = 0; i < sz(v) - 1; i++) {\n        res += v[i] ^ v[i\
    \ + 1];\n    }\n    return abs(res); // Twice the area!\n}\n\ntemplate <class\
    \ P>\nint in_poly(const P &p, const vector<P> &v) {\n    bool res = 0;\n    for\
    \ (int i = 0; i < sz(v); i++) {\n        auto nxt = v[i == sz(v) - 1 ? 0 : i +\
    \ 1];\n        auto seg = Line(v[i], nxt);\n        if (on_seg(p, seg)) return\
    \ -1;\n        res ^= ((p.y < v[i].y) - (p.y < nxt.y)) * ((v[i] - p) ^ (nxt -\
    \ p)) > 0;\n    }\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: geometry/primitives.h
  requiredBy:
  - geometry/integer_lattice.h
  timestamp: '2024-09-22 22:20:12-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/primitives.h
layout: document
redirect_from:
- /library/geometry/primitives.h
- /library/geometry/primitives.h.html
title: geometry/primitives.h
---
