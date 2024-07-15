struct STNode {
    ll tl, tr;
    ll val = 0, lz = 0;
    STNode *left = 0, *right = 0;

    STNode(ll l, ll r) : tl(l), tr(r) {}

    void push() {
        if (!left) {
            ll mid = tl + (tr - tl) / 2;
            left = new STNode(tl, mid);
            right = new STNode(mid, tr);
        }
        if (lz) {
            left->add(tl, tr, lz);
            right->add(tl, tr, lz);
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
        return left->query(l, r) + right->query(l, r);
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
        left->add(l, r, v);
        right->add(l, r, v);
        val = left->val + right->val;
    }
};
