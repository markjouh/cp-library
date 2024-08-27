#define PROBLEM "https://judge.yosupo.jp/problem/double_ended_priority_queue"

#include "../../boilerplate.hpp"
#include "../../../datastructures/w_ary_tree.hpp"

const ll lo = numeric_limits<ll>::min(), hi = numeric_limits<ll>::max();

int main() {
    int n, q;
    cin >> n >> q;
    vector<ll> queries, vals;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        queries.push_back(x);
        vals.push_back(x);
    }
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 0) {
            int x;
            cin >> x;
            queries.push_back(x);
            vals.push_back(x);
        } else if (t == 1) {
            queries.push_back(lo);
        } else {
            queries.push_back(hi);
        }
    }
    sort(all(vals));
    vals.resize(unique(all(vals)) - begin(vals));
    w_ary_tree<20000000> ds;
    for (ll x : queries) {
        if (x == lo) {
            int rem = ds.get_min();
            cout << vals[rem] << '\n';
            ds.extract(rem);
        } else if (x == hi) {
            int rem = ds.get_max();
            cout << vals[rem] << '\n';
            ds.extract(rem);
        } else {
            ds.insert(lower_bound(all(vals), x) - begin(vals));
        }
    }
}