#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../../misc/template.h"

// Just for completionism's sake...

const int T = 50;

int main() {
    for (int i = 0; i < T; i++) {
        const long long rand_ns = rand_int(1e6, 1e7);

        timer::start();
        this_thread::sleep_for(chrono::nanoseconds(rand_ns));
        long long elapsed = timer::get_ns();

        assert(abs(elapsed - rand_ns) < 1e7);
    }

    cerr << "Tests passed\n";

    int a, b;
    cin >> a >> b;
    cout << a + b << '\n';
}