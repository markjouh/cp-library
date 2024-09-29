#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../../misc/template.h"
#include "../../../datastructures/binary_indexed_tree/bit_range_add.h"

const int N = 1e5, Q = 1e5;

int main() {
    vector<ll> a = rand_vec<ll>(N);
    RangeAddBIT<ll> ft(a);
    for (int i = 0; i < Q; i++) {
        if (rand_bool()) {
            int l = rand_int(N), r = rand_int(N);
            if (l > r) {
                swap(l, r);
            }
            const int v = rand_int(1e9);
            for (int j = l; j <= r; j++) {
                a[j] += v;
            }
            ft.add(l, r, v);
        } else {
            int p = rand_int(N);
            assert(a[p] == ft.get(p));
        }
    }

    cerr << "Tests passed\n";

    int a_, b_;
    cin >> a_ >> b_;
    cout << a_ + b_ << '\n';
}