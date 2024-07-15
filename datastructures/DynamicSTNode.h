struct STNode {
    ll tl, tr;
    ll val = 0, lz = 0;
    STNode *l_child = 0, *r_child = 0;

    STNode(ll l, ll r) : tl(l), tr(r) {}

    void push() {
        if (!l_child) {
            ll mid = tl + (tr - tl) / 2;
            l_child = new STNode(tl, mid);
            r_child = new STNode(mid, tr);
        }
        if (lz) {
            l_child->add(tl, tr, lz);
            r_child->add(tl, tr, lz);
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
        return l_child->query(l, r) + r_child->query(l, r);
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
        l_child->add(l, r, v);
        r_child->add(l, r, v);
        val = l_child->val + r_child->val;
    }
};
