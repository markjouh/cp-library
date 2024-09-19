#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../../misc/template.h"
#include "../../../datastructures/segtree/segtree_sparse.h"

const int N = 1e9, Q = 5e4;

ll op(ll x, ll y) {
    return x + y;
}

ll id() {
    return 0;
}

int main() {
    vector<pair<int, int>> a;
    SparseSegtree<ll, op, id> st(N);

    for (int i = 0; i < Q; i++) {
        if (rand_bool()) {
            const int p = rand_int(N), v = rand_int(1e9);
            bool flag = false;
            for (auto &b : a) {
                if (b.first == p) {
                    flag = true;
                    b.second = v;
                    break;
                }
            }
            if (!flag) {
                a.emplace_back(p, v);
            }
            st.set(p, v);
        } else {
            int l = rand_int(N), r = rand_int(N);
            if (l > r) {
                swap(l, r);
            }
            ll sum = 0;
            for (auto [p, v] : a) {
                if (p >= l && p <= r) {
                    sum += v;
                }
            }
            assert(st.query(l, r) == sum);
        }
    }

    cerr << "Tests passed\n";

    int a_, b_;
    cin >> a_ >> b_;
    cout << a_ + b_ << '\n';
}