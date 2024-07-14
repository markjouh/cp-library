struct dst_node {
    ll tl, tr;
    ll val = 0, lz = 0;
    dst_node *lch = 0, *rch = 0;

    dst_node(ll l, ll r) : tl(l), tr(r) {}

    void push() {
        if (!lch) {
            ll mid = tl + (tr - tl) / 2;
            lch = new dst_node(tl, mid);
            rch = new dst_node(mid, tr);
        }
        if (lz) {
            lch->add(tl, tr, lz);
            rch->add(tl, tr, lz);
            lz = 0;
        }
    }

    ll query(ll l, ll r) {
        if (tl >= r || tr <= l) {
            return 0;
        }
        if (tl >= l && tr <= r) {
            return val;
        }
        push();
        return lch->query(l, r) + rch->query(l, r);
    }

    void add(ll l, ll r, ll v) {
        if (tl >= r || tr <= l) {
            return;
        }
        if (tl >= l && tr <= r) {
            val += (tr - tl) * v;
            lz += v;
            return;
        }
        push();
        lch->add(l, r, v);
        rch->add(l, r, v);
        val = lch->val + rch->val;
    }
};
