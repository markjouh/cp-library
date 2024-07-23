vi topsort(vvi &g) {
    vi in(sz(g));
    rep(u, sz(g)) {
        for (int v : g[u]) {
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
        int u = ft(q);
        q.pop();
        res.pb(u);
        for (int v : g[u]) {
            if (--in[v] == 0) {
                q.push(v);
            }
        }
    }
    return res;
}
