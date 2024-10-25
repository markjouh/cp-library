#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C"

#include "../../../misc/template.h"
#include "../../../esoteric/w_ary_tree.h"
#include "../../../common/compress.h"

int main() {
    string s;
    int x;
    vector<int> queries;
    Compress<int> vals;
    while (cin >> s) {
        if (s == "end") {
            break;
        }
        if (s == "insert") {
            cin >> x;
            queries.push_back(x);
            vals.add(x);
        } else {
            queries.push_back(-1);
        }
    }
    WAryTree<2000000> ds;
    for (auto x : queries) {
        if (x == -1) {
            int idx = ds.get_max();
            cout << vals[idx] << '\n';
            ds.remove(idx);
        } else {
            ds.insert(vals.get(x));
        }
    }
}