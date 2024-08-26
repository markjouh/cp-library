/* Builds a trie, a k-ary search tree where each node represents a distinct prefix.
 * `insert(S)`: O(|S|)
 * 'gen_graph()`: O(N), returns an adjacency list with the same structure as the trie
 */

#pragma once

struct string_trie {
    struct node {
        int nxt[26];
        bool flag = false;

        node() {
            memset(nxt, -1, sizeof nxt);
        }
    };

    vector<node> trie;

    string_trie() : trie(1) {}

    int insert(const string &s) {
        int x = 0;
        for (char c : s) {
            int y = c - 'a';
            if (trie[x].nxt[y] == -1) {
                trie[x].nxt[y] = sz(trie);
                trie.emplace_back();
            }
            x = trie[x].nxt[y];
        }
        trie[x].flag = true;
        return x;
    }

    vector<vector<int>> gen_graph() {
        vector<vector<int>> g(sz(trie));
        for (int u = 0; u < sz(trie); u++) {
            for (int i = 0; i < 26; i++) {
                int v = trie[u].nxt[i];
                if (v != -1) {
                    g[u].push_back(v);
                }
            }
        }
        return g;
    }
};
