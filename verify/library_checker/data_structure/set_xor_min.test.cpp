#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"

#include "../../../misc/template.h"
#include "../../../datastructures/binary_trie.h"

int main() {
    int q;
    cin >> q;
    BinaryTrie<uint32_t> bt;
    while (q--) {
        int t, x;
        cin >> t >> x;
        if (t == 0) {
            if (bt.min_xor(x) != 0) {
                bt.add(x);
            }
        } else if (t == 1) {
            if (bt.min_xor(x) == 0) {
                bt.add(x, -1);
            }
        } else {
            cout << bt.min_xor(x) << '\n';
        }
    }
}