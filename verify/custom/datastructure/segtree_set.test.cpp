#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../../misc/template.h"
#include "../../../datastructures/segment_tree/segtree_set.h"

int xor_op(int a, int b) {
    return a ^ b;
}

int add_op(int a, int b) {
    return a + b;
}

int gcd_op(int a, int b) {
    return gcd(a, b);
}

int id() {
    return 0;
}

template <auto op, int N, int MXV>
void test() {
    vector<int> naive(N, id());
    SegtreeSet<int, op, id> st(N);

    for (int i = 0; i < N; i++) {
        int x = rand_int(MXV);
        st.insert(x);
        naive[i] = x;
        assert(accumulate(all(naive), id(), op) == st.query());
    }

    for (int i = 0; i < N / 2; i++) {
        int x = naive[i];
        st.remove(x);
        naive[i] = id();
        assert(accumulate(all(naive), id(), op) == st.query());
    }
}

int main() {
    for (int i = 0; i < 100; i++) {
        test<xor_op, 100, 1000000>();
    }
    for (int i = 0; i < 100; i++) {
        test<add_op, 100, 1000000>();
    }
    for (int i = 0; i < 1000; i++) {
        test<gcd_op, 10, 100>();
    }

    cerr << "Tests passed\n";
    int a_, b_;
    cin >> a_ >> b_;
    cout << a_ + b_ << '\n';
}
