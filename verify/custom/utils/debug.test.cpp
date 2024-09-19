#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../../misc/template.h"
#include "../../../utils/debug.h"

// Just make sure the output looks right...

int main() {
    const int n = rand_int(100);
    vector<int> p = rand_vec<int>(n);
    dbg(p);

    map<int, vector<int>> mp;
    for (int i = 0; i < 100; i++) {
        mp[rand_int()] = rand_vec<int>(100);
    }
    dbg(mp);

    array<double, 100> arr = rand_arr<double, 100>();
    dbg(arr);

    int a, b;
    cin >> a >> b;
    cout << a + b << '\n';
}