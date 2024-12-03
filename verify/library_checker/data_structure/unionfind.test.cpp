#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "../../../template/template.h"
#include "../../../datastructures/dsu.h"

int main() {
    int n, q;
    cin >> n >> q;
    dsu comps(n);
    while (q--) {
        bool t;
        int x, y;
        cin >> t >> x >> y;
        if (t) {
            cout << (comps.find(x) == comps.find(y)) << '\n';
        } else {
            comps.join(x, y);
        }
    }
}