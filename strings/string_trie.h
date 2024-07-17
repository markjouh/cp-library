struct Trie {
    struct Node {
        int nxt[26];
        bool flag = false;

        Node() {
            memset(nxt, -1, sizeof nxt);
        }
    };

    vector<Node> trie;

    Trie() : trie(1) {}

    int add(string &s) {
        int x = 0;
        for (char c : s) {
            int y = c - 'a';
            if (trie[x].nxt[y] == -1) {
                trie[x].nxt[y] = sz(trie);
                trie.eb();
            }
            x = trie[x].nxt[y];
        }
        trie[x].flag = true;
        return x;
    }

    vec<vi> graph() {
        vec<vi> g(sz(trie));
        rep(u, sz(trie)) {
            rep(i, 26) {
                int v = trie[u].nxt[i];
                if (v != -1) {
                    g[u].pb(v);
                }
            }
        }
        return g;
    }
};
