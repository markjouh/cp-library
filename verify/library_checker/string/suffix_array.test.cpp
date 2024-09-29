#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include "../../../misc/template.h"
#include "../../../strings/suffix_array.h"

int main() {
    string s;
    cin >> s;
    bool first = true;
    for (int x : gen_sa(s)) {
        if (first) {
            first = false;
            continue;
        }
        cout << x << ' ';
    }
}