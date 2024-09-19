#define PROBLEM "https://judge.yosupo.jp/problem/double_ended_priority_queue"

#include "../../../misc/template.h"
#include "../../../datastructures/w_ary_tree.h"

const int N = 1 << 18;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> queries, vals;
    for (int i = 0; i < n; i++) {
        int x;
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
            queries.push_back(INT_MIN);
        } else {
            queries.push_back(INT_MAX);
        }
    }
    sort(all(vals));
    vals.resize(unique(all(vals)) - begin(vals));

    array<int, 3> cnt{};
    array<WAryTree<1 << 18>, 3> ds;
    for (int x : queries) {
        if (x == INT_MIN) {
            for (int i = 0; i < 3; i++) {
                if (cnt[i] > 0) {
                    int rem = ds[i].get_min();
                    cout << vals[i * N + rem] << '\n';
                    ds[i].remove(rem);
                    cnt[i]--;
                    break;
                }
            }
        } else if (x == INT_MAX) {
            for (int i = 2; i >= 0; i--) {
                if (cnt[i] > 0) {
                    int rem = ds[i].get_max();
                    cout << vals[i * N + rem] << '\n';
                    ds[i].remove(rem);
                    cnt[i]--;
                    break;
                }
            }
        } else {
            int idx = lower_bound(all(vals), x) - begin(vals);
            ds[idx / N].insert(idx % N);
            cnt[idx / N]++;
        }
    }
}