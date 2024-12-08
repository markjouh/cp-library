#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B"

#include "../../../template/template.h"
#include "../../../numeric/binsearch.h"

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(all(a));
    int q;
    cin >> q;
    int ans = 0;
    while (q--) {
        int x;
        cin >> x;
        int idx = bsmin(0, n - 1, [&](int p) {
            return a[p] >= x;
        });
        ans += idx != n && a[idx] == x;
    }
    cout << ans << '\n';
}