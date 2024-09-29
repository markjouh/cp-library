#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../../misc/template.h"
#include "../../../graphs/shortest_paths/dijkstras.h"

// Just a sanity check - makes sure the result is connected

const int T = 100;
const int INF = INT_MAX / 2;

int main() {
    for (int i = 0; i < T; i++) {
        const int n = rand_int(1e2, 1e4), root = rand_int(n);
        auto g = gen_graph(n, n - 1 + rand_int(n));

        vector<int> dist(n, INF);
        queue<int> q;
        dist[root] = 0;
        q.push(root);

        while (sz(q)) {
            int u = q.front();
            q.pop();
            for (int v : g[u]) {
                if (dist[v] == INF) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        assert(find(all(dist), INF) == end(dist));
    }

    for (int i = 0; i < T; i++) {
        const int n = rand_int(1e2, 1e4), root = rand_int(n);
        auto g = gen_weighted_graph(n, n - 1 + rand_int(n));
        
        auto from = dijkstras<ll>(g, root).second;
        from[root] = root;
        assert(find(all(from), -1) == end(from));
    }

    cerr << "Tests passed" << endl;

    int a, b;
    cin >> a >> b;
    cout << a + b << '\n';
}