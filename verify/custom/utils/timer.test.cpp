#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include <unistd.h>

#include "../../../misc/template.h"

// Just for completionism's sake...

const int T = 10;

int main() {
    for (int i = 0; i < T; i++) {
        const int rand_ms = rand_int(50, 500);

        start_timer();
        usleep(rand_ms * 1000);
        assert(abs(elapsed() - rand_ms) < 10);
    }

    cerr << "Tests passed\n";

    int a, b;
    cin >> a >> b;
    cout << a + b << '\n';
}