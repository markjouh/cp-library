vi kruskals(int n, vec<arr<int, 3>> &e) {
    sort(all(e), [&](arr<int, 3> a, arr<int, 3> b) {
        return a[2] < b[2];
    });
    DSU dsu(n);
    vi res;
    rep(i, sz(e)) {
        if (dsu.join(e[i][0], e[i][1])) {
            res.pb(i);
        }
    }
    return res;
}
