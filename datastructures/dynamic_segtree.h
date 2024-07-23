struct STNode {
    int tl, tr;
    ll sum = 0;
    int mn = 0, mx = 0;
    int addv = 0, setv = inf + 1;
    STNode *lch = 0, *rch = 0;

    STNode(int l, int r) : tl(l), tr(r) {}

    STNode(int l, int r, vi &a) : tl(l), tr(r) {
        if (tl + 1 < tr) {
            int mid = tl + (tr - tl) / 2;
            lch = new STNode(tl, mid, a); rch = new STNode(mid, tr, a);
            pull();
        } else {
            sum = mn = mx = a[tl];
        }
    }

    void push() {
        if (!lch) {
            ll mid = tl + (tr - tl) / 2;
            lch = new STNode(tl, mid); rch = new STNode(mid, tr);
        }
        if (setv != inf + 1) {
            lch->set(tl, tr, setv); rch->set(tl, tr, setv);
            setv = inf + 1;
        } else if (addv) {
            lch->add(tl, tr, addv); rch->add(tl, tr, addv);
            addv = 0;
        }
    }

    void pull() {
        sum = lch->sum + rch->sum;
        mn = min(lch->mn, rch->mn);
        mx = max(lch->mx, rch->mx);
    }

    ll get_sum(int l, int r) {
        if (tl >= r || tr <= l) return 0;
        if (tl >= l && tr <= r) return sum;
        push();
        return lch->get_sum(l, r) + rch->get_sum(l, r);
    }

    int get_min(int l, int r) {
        if (tl >= r || tr <= l) return +inf;
        if (tl >= l && tr <= r) return mn;
        push();
        return min(lch->get_min(l, r), rch->get_min(l, r));
    }

    int get_max(int l, int r) {
        if (tl >= r || tr <= l) return -inf;
        if (tl >= l && tr <= r) return mx;
        push();
        return max(lch->get_max(l, r), rch->get_max(l, r));
    }

    void add(int l, int r, ll v) {
        if (tl >= r || tr <= l) return;
        if (tl >= l && tr <= r) {
            sum += 1ll * (tr - tl) * v;
            mn += v; mx += v;
            if (setv != inf + 1) {
                setv += v;
            } else {
                addv += v;
            }
            return;
        }
        push();
        lch->add(l, r, v); rch->add(l, r, v);
        pull();
    }

    void set(int l, int r, ll v) {
        if (tl >= r || tr <= l) return;
        if (tl >= l && tr <= r) {
            sum = 1ll * (tr - tl) * v;
            mn = mx = v;
            addv = 0;
            setv = v;
            return;
        }
        push();
        lch->set(l, r, v); rch->set(l, r, v);
        pull();
    }
};
