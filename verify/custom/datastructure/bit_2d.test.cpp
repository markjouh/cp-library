#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../../misc/template.h"
#include "../../../datastructures/binary_indexed_tree/bit_2d.h"

const int N = 500, M = 500, Q = 1e5;
const int MXV = 1e6;

int main() {
    vector<vector<ll>> a(N, vector<ll>(M));
    BIT2D<ll> ft(N, M);

    for (int i = 0; i < N; i++) {
        a[i] = rand_vec<ll>(M, 0, MXV);
        for (int j = 0; j < M; j++) {
            ft.add(i, j, a[i][j]);
        }
    }

    for (int i = 0; i < Q; i++) {
        if (rand_bool()) {
            int r = rand_int(N), c = rand_int(M);
            const int v = rand_int(MXV);

            a[r][c] += v;
            ft.add(r, c, v);
        } else {
            int r1 = rand_int(N), c1 = rand_int(M), r2 = rand_int(N), c2 = rand_int(M);
            if (r1 > r2) {
                swap(r1, r2);
            }
            if (c1 > c2) {
                swap(c1, c2);
            }
            ll brute = 0;
            for (int r = r1; r <= r2; r++) {
                for (int c = c1; c <= c2; c++) {
                    brute += a[r][c];
                }
            }
            assert(brute == ft.sum(r1, c1, r2, c2));
        }
    }

    cerr << "Tests passed\n";
    int a_, b_;
    cin >> a_ >> b_;
    cout << a_ + b_ << '\n';
}
