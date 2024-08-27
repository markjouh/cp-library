#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"

#include "../../boilerplate.hpp"
#include "../../../datastructures/hash_table.hpp"

int main() {
    int q;
    cin >> q;
    hash_table<ll, ll> mp;
    while (q--) {
        bool t;
        ll k;
        cin >> t >> k;
        if (t) {
            cout << mp[k] << '\n';
        } else {
            ll v;
            cin >> v;
            mp[k] = v;
        }
    }
}