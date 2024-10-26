#define PROBLEM "https://judge.yosupo.jp/problem/static_range_mode_query"

#include "../../../template/template.h"
#include "../../../datastructures/hash_table.h"
#include "../../../datastructures/static/mo_queries.h"

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    MoQueries<pair<int, int>, 300> mo;
    while (q--) {
        int l, r;
        cin >> l >> r;
        mo.insert(l, r - 1);
    }

    HashTable<int, int> freq;
    set<pair<int, int>> st;

    auto add = [&](int p) {
        if (freq.find(a[p]) != freq.end()) {
            st.extract({freq[a[p]], a[p]});
        }
        freq[a[p]]++;
        st.insert({freq[a[p]], a[p]});
    };

    auto del = [&](int p) {
        if (freq.find(a[p]) != freq.end()) {
            st.extract({freq[a[p]], a[p]});
        }
        freq[a[p]]--;
        st.insert({freq[a[p]], a[p]});
    };

    auto query = [&]() {
        return make_pair(rbegin(st)->second, rbegin(st)->first);
    };

    mo.solve(add, del, query);
    for (auto [x, y] : mo.res) {
        cout << x << ' ' << y << '\n';
    }
}