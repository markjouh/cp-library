#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B"

#include "../../../misc/template.h"
#include "../../../numeric/mod_int.h"

using mint = ModInt<1000000007>;

int main() {
    int m, n;
    cin >> m >> n;
    cout << pow(mint(m), n) << '\n';
}