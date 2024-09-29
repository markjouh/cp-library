#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"

#include "../../../misc/template.h"
#include "../../../common/binsearch.h"
#include "../../../strings/hashing.h"

int main() {
    string s;
    cin >> s;
    string rev = s;
    reverse(all(rev));
    StringHash a(s), b(rev);
    const int n = sz(s);
    vector<int> ans(2 * n - 1);
    for (int i = 0; i < n; i++) {
        ans[2 * i] = 2 * bsmax(0, min(i, n - i - 1), [&](int d) {
            return a.get(i - d, i) == b.get(n - i - 1 - d, n - i - 1);
        }) + 1;
    }
    for (int i = 0; i < n - 1; i++) {
        ans[2 * i + 1] = 2 * bsmax(0, min(i, n - i - 2), [&](int d) {
            return a.get(i - d, i) == b.get(n - i - 2 - d, n - i - 2);
        }) + 2;
    }
    for (int i = 0; i < 2 * n - 1; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}