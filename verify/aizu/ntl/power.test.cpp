#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B"

#include "../../boilerplate.hpp"
#include "../../../numeric/mod_int.hpp"

using mint = mod_int<1000000007>;

int main() {
    int m, n;
    cin >> m >> n;
    cout << pow(mint(m), n) << '\n';
}