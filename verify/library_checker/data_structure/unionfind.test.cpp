#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "../../../misc/template.h"
#include "../../../datastructures/dsu.h"

int main() {
    int n, q;
    cin >> n >> q;
    DSU dsu(n);
    while (q--) {
        bool t;
        int x, y;
        cin >> t >> x >> y;
        if (t) {
            cout << (dsu.find(x) == dsu.find(y)) << '\n';
        } else {
            dsu.join(x, y);
        }
    }
}