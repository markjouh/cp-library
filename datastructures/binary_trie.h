template <class T>
struct binary_trie {
    static const int W = sizeof(T) * 8;
    vector<array<int, 2>> nxt;
    vector<int> cnt;
    T filter = 0;

    binary_trie() : nxt(1, {-1, -1}), cnt(1, 0) {}

    void add(T x, int v = 1) {
        x ^= filter;
        int pos = 0;
        for (int i = W - 1; i >= 0; i--) {
            bool dir = (x >> i) & 1;
            if (nxt[pos][dir] == -1) {
                nxt[pos][dir] = sz(nxt);
                nxt.push_back({-1, -1});
                cnt.push_back(0);
            }
            pos = nxt[pos][dir];
            cnt[pos] += v;
        }
    }

    binary_trie &operator^=(T x) {
        filter ^= x;
        return *this;
    }

    T min_xor(T x) {
        x ^= filter;
        int pos = 0;
        T res = 0;
        for (int i = W - 1; i >= 0; i--) {
            bool dir = (x >> i) & 1;
            if (nxt[pos][dir] == -1 || cnt[nxt[pos][dir]] == 0) {
                res |= T(1) << i;
                pos = nxt[pos][dir ^ 1];
            } else {
                pos = nxt[pos][dir];
            }
        }
        return res;
    }

    T max_xor(T x) {
        static const T mask = -1;
        return mask ^ min_xor(x ^ mask);
    }
};