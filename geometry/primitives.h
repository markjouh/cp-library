template <class T>
using prod_t = conditional_t<is_same_v<T, int>, ll, conditional_t<is_same_v<T, ll>, __int128_t, T>>;

template <class T>
bool safe_eq(T a, T b = 0) {
    static constexpr ld EPS = 1e-9;
    if constexpr (is_floating_point_v<T>) {
        return abs(a - b) < EPS;
    }
    return a == b;
}

template <class T>
struct Point {
    T x, y;

    Point(T x_ = 0, T y_ = 0) : x(x_), y(y_) {}

    template <class U>
    operator Point<U>() const {
        return Point<U>(static_cast<U>(x), static_cast<U>(y));
    }

    // Cast b onto the line colinear to a and multiply their magnitudes
    // Is b pointing in the same direction as a?
    friend prod_t<T> operator*(Point a, const Point &b) {
        return prod_t<T>(a.x) * b.x + prod_t<T>(a.y) * b.y;
    }
    // Align a horizontally along the x axis and integrate the parallelogram
    // Which side of a is b on?
    friend prod_t<T> operator^(Point a, const Point &b) {
        return prod_t<T>(a.x) * b.y - prod_t<T>(a.y) * b.x;
    }

    Point &operator+=(const Point &b) {
        x += b.x, y += b.y;
        return *this;
    }
    Point &operator-=(const Point &b) {
        x -= b.x, y -= b.y;
        return *this;
    }
    Point &operator*=(T fac) {
        x *= fac, y *= fac;
        return *this;
    }
    Point &operator/=(T fac) {
        x /= fac, y /= fac;
        return *this;
    }
    friend Point operator+(Point a, const Point &b) {
        return a += b;
    }
    friend Point operator-(Point a, const Point &b) {
        return a -= b;
    }
    friend Point operator*(Point a, T b) {
        return a *= b;
    }
    friend Point operator/(Point a, T b) {
        return a /= b;
    }
    friend bool operator<(const Point &a, const Point &b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    }
    friend bool operator>(const Point &a, const Point &b) {
        return b < a;
    }
    friend bool operator==(const Point &a, const Point &b) {
        return a.x == b.x && a.y == b.y;
    }
    friend bool operator!=(const Point &a, const Point &b) {
        return !(a == b);
    }
    int side() const {
        return y < 0 ? -1 : y == 0 && x >= 0 ? 0 : 1;
    }
    friend bool comp_angle(const Point &a, const Point &b) {
        return a.side() < b.side() || (a.side() == b.side() && (a ^ b) > 0);
    }
    friend prod_t<T> mag_sq(const Point &a) {
        return a * a;
    }
    friend ld mag(const Point &a) {
        return sqrt(mag_sq(a));
    }
    friend prod_t<T> dist_sq(const Point &a, const Point &b) {
        return mag_sq(a - b);
    }
    friend ld dist(const Point &a, const Point &b) {
        return mag(a - b);
    }
    friend istream &operator>>(istream &is, Point &a) {
        return is >> a.x >> a.y;
    }
    friend ostream &operator<<(ostream &os, const Point &a) {
        return os << '(' << a.x << ", " << a.y << ')';
    }
};

template <class T>
struct Line {
    Point<T> p, d;

    Line(Point<T> a = Point<T>()) : p(Point<T>()), d(a) {}
    Line(Point<T> a, Point<T> b, bool ends = true) : p(a), d(ends ? b - a : b) {}

    bool operator<(const Line &b) const {
        return comp_angle(this->d, b.d);
    }
    bool operator>(const Line &b) const {
        return b < *this;
    }

    friend ostream &operator<<(ostream &os, const Line &a) {
        return os << a.p << " + t" << a.d;
    }
};

template <class T>
bool on_line(const Point<T> &p, const Line<T> &l) {
    return safe_eq((p - l.p) ^ l.d);
}

template <class T>
bool on_seg(const Point<T> &p, const Line<T> &s) {
    auto vec_a = (s.p - p), vec_b = (s.p + s.d - p);
    return safe_eq(vec_a ^ vec_b) && (vec_a * vec_b) <= 0;
}

template <class T>
ld dist_line(const Point<T> &p, const Line<T> &l) {
    return abs((p - l.p) ^ l.d) / mag(l);
}

template <class T>
ld dist_seg(const Point<T> &p, const Line<T> &s) {
    if ((p - s.p) * s.d <= 0) {
        return dist(p, s.p);
    }
    if ((p - s.p - s.d) * s.d >= 0) {
        return dist(p, s.p + s.d);
    }
    return dist_line(p, s);
}

template <class T>
Point<ld> project_line(const Point<T> &p, const Line<T> &l) {
    return Point<ld>(l.p) + Point<ld>(l.d) * ((p - l.p) * l.d) / mag_sq(l);
}

template <class T>
Point<ld> project_seg(const Point<T> &p, const Line<T> &s) {
    if ((p - s.p) * s.d <= 0) {
        return s.p;
    }
    if ((p - s.p - s.d) * s.d >= 0) {
        return s.p + s.d;
    }
    return project_line(p, s);
}

template <class L>
pair<int, Point<ld>> inter_lines(const L &a, const L &b) {
    if (safe_eq(a.d ^ b.d)) return {-safe_eq(a.d ^ (b.p + b.d - a.p)), Point<ld>()};
    return Point<ld>(a.p) + Point<ld>(a.d) * ((b.p - a.p) ^ b.d) / (a.d ^ b.d);
}

template <class L>
vector<Point<ld>> inter_segs(const L &a, const L &b) {
    auto den = a.d ^ b.d;
    if (safe_eq(den)) {
        if (a.d ^ (b.p + b.d - a.p)) {
            return {};
        }

        auto s1 = a.p, e1 = a.p + a.d, s2 = b.p, e2 = b.p + b.d;
        if (e1 < s1) {
            swap(s1, e1);
        }
        if (e2 < s2) {
            swap(s2, e2);
        }

        auto l = max(s1, s2), r = min(e1, e2);
        if (r < l) {
            return {};
        }
        if (l == r) {
            return {l};
        }
        return {l, r}; // Segment from l to r
    }

    auto num_a = (b.p - a.p) ^ b.d, num_b = (a.p - b.p) ^ a.d;
    den < 0 ? den *= -1, num_a *= -1 : num_b *= -1;
    if (num_a < 0 || num_a > den || num_b < 0 || num_b > den) {
        return {};
    }
    return {Point<ld>(a.p) + Point<ld>(a.d) * num_a / den};
}

template <class T>
auto area_poly(const vector<Point<T>> &v) {
    prod_t<T> res = v.back() ^ v[0];
    for (int i = 0; i < sz(v) - 1; i++) {
        res += v[i] ^ v[i + 1];
    }
    return abs(res); // Twice the area!
}

template <class P>
int in_poly(const P &p, const vector<P> &v) {
    bool res = 0;
    for (int i = 0; i < sz(v); i++) {
        auto nxt = v[i == sz(v) - 1 ? 0 : i + 1];
        auto seg = Line(v[i], nxt);
        if (on_seg(p, seg)) {
            return -1;
        }
        res ^= ((p.y < v[i].y) - (p.y < nxt.y)) * ((v[i] - p) ^ (nxt - p)) > 0;
    }
    return res;
}