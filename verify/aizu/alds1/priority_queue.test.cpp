#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C"

#include "../../boilerplate.hpp"
#include "../../../datastructures/w_ary_tree.hpp"

int main() {
    string s;
    int x;
    vector<int> queries;
    vector<int> vals;
    while (cin >> s) {
        if (s == "end") {
            break;
        }
        if (s == "insert") {
            cin >> x;
            queries.push_back(x);
            vals.push_back(x);
        } else {
            queries.push_back(-1);
        }
    }
    sort(all(vals));
    vals.resize(unique(all(vals)) - begin(vals));
    w_ary_tree<2000000> ds;
    for (auto x : queries) {
        if (x == -1) {
            int mx_idx = ds.get_max();
            cout << vals[mx_idx] << '\n';
            ds.extract(mx_idx);
        } else {
            ds.insert(lower_bound(all(vals), x) - begin(vals));
        }
    }
}