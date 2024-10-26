#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D"

#include "../../../template/template.h"

int main() {
    int n;
    cin >> n;
    ll ans = 0;
    oset<int> st;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ans += sz(st) - st.order_of_key(x + 1);
        st.insert(x);
    }
    cout << ans << '\n';
}