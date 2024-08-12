// Note: largely untested

namespace geometry {
    template<class T> struct Point {
        T x, y;

        Point(T a = 0, T b = 0) : x(a), y(b) {}

        friend T mh_dist(Point a, Point b) {
            return abs(a.x - b.x) + abs(a.y - b.y);
        }

        friend T sq_dist(Point a, Point b) {
            return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
        }

        friend ld dist(Point a, Point b) {
            return sqrt(sq_dist(a, b));
        }

        friend istream &operator>>(istream &is, Point &p) {
            is >> p.x >> p.y;
            return is;
        }

        friend ostream &operator<<(ostream &os, Point &p) {
            os << p.x << ' ' << p.y;
            return os;
        }
    };

    template<class T> struct Line {
        Point<T> p;
        T slope;
        bool vert;

        Line(Point<T> a, T s, bool v = false) : p(a), slope(s), vert(v) {}

        Line(Point<T> a, Point<T> b) : p(a) {
            if (a.x == b.x) {
                vert = true;
            } else {
                slope = (b.y - a.y) / (b.x - a.x);
            }
        }

        Line get_perp() {
            if (slope == 0) {
                return Line(p, 0, true);
            }
            if (vert) {
                return Line(p, 0, false);
            }
            return Line(p, -1.0 / slope);
        }

        Point<T> eval(T x) {
            return Point<T>(x, p.y + slope * (x - p.x));
        }

        bool contains(Point<T> q) {
            return eval(q.x) == q.y;
        }

        friend Point<T> line_inter(Line<T> a, Line<T> b) {
            assert(a.vert != b.vert || a.slope != b.slope);
            if (a.vert) {
                return b.eval(a.x);
            }
            if (b.vert) {
                return a.eval(b.x);
            }
            return a.eval((-a.y + b.y + a.slope * a.x - b.slope * b.x) / (a.slope - b.slope));
        }
    };

    template<class T> Point<T> proj_point(Point<T> p, Line<T> a) {
        Line<T> perp = a.get_perp();
        return line_inter(a, Line<T>(p, perp.slope, perp.vert));
    }
};
