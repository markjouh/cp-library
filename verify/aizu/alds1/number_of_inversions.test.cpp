#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D"

#include "../../../misc/template.h"
#include "../../../datastructures/pbds/order_statistic_tree.h"

int main() {
    int n;
    cin >> n;
    ll ans = 0;
    OSTree<int> st;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ans += sz(st) - st.order_of_key(x + 1);
        st.insert(x);
    }
    cout << ans << '\n';
}