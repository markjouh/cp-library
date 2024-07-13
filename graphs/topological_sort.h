vi topsort(vec<vpi> &g) {
    vi in(sz(g));
    rep(u, sz(g)) {
        for (auto [v, _] : g[u]) {
            in[v]++;
        }
    }
    vi res;
    queue<int> q;
    rep(i, sz(g)) {
        if (in[i] == 0) {
            q.push(i);
        }
    }
    while (sz(q)) {
        int u = q.front();
        q.pop();
        res.pb(u);
        for (auto [v, _] : g[u]) {
            if (--in[v] == 0) {
                q.push(v);
            }
        }
    }
    return res;
}
