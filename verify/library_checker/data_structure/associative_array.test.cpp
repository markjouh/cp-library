#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"

#include "../../../misc/template.h"
#include "../../../datastructures/pbds/hash_table.h"

int main() {
    int q;
    cin >> q;
    HashTable<ll, ll> mp;
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