#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"

#include "../../../template/template.h"
#include "../../../template/io_helpers.h"
#include "../../../datastructures/hash_table.h"

int main() {
    int q;
    re(q);
    hash_table<ll, ll> mp;
    while (q--) {
        bool t;
        ll k;
        re(t, k);
        if (t) {
            pr(mp[k]);
        } else {
            ll v;
            re(v);
            mp[k] = v;
        }
    }
}