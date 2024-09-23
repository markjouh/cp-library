#pragma once

// Simple stuff for counting lattice points when we have integer vertices.
// Fully tested on CSES Polygon Lattice Points.

template <class T>
T lattice_seg(const Point<T> &s) {
    auto a = s.p, b = s.p + s.d;
    return gcd(b.x - a.x, b.y - a.y); // (inside, on boundary)
}

template <class T>
pair<ll, ll> lattice_poly(const vector<Point<T>> &v) {
    pair<ll, ll> res;
    for (int i = 0; i < sz(v); i++) {
        auto nxt = v[i == sz(v) - 1 ? 0 : i + 1];
        auto seg = Line<T>(v[i], nxt);
        res.first += v[i] ^ nxt;
        res.second += lattice_seg(seg);
    }
    res.first = (abs(res.first) - res.second + 2) / 2;
    return res;
}