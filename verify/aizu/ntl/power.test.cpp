#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B"

#include "../../../template/template.h"
#include "../../../numeric/mint.h"

using mi = Mint<1000000007>;

int main() {
    int m, n;
    cin >> m >> n;
    cout << pow(mi(m), n) << '\n';
}