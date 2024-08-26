#pragma once

template<int N> struct quick_heap {
    uint32_t freq[N];
    uint64_t l0[(N >> 6) + 1], l1[(N >> 12) + 1], root;

    quick_heap() {
        memset(freq, 0, sizeof freq);
        memset(l0, 0, sizeof l0);
        memset(l1, 0, sizeof l1);
        root = 0;
    }

    void insert(int x) {
        freq[x]++;
        if (freq[x] == 1) {
            l0[x >> 6] |= 1ull << (x & 63);
            if (__builtin_popcountll(l0[x >> 6]) == 1) {
                l1[x >> 12] |= 1ull << ((x >> 6) & 63);
                if (__builtin_popcountll(l1[x >> 12]) == 1) {
                    root |= 1ull << ((x >> 12) & 63);
                }
            }
        }
    }

    void extract(int x) {
        freq[x]--;
        if (freq[x] == 0) {
            l0[x >> 6] ^= 1ull << (x & 63);
            if (__builtin_popcountll(l0[x >> 6]) == 0) {
                l1[x >> 12] ^= 1ull << ((x >> 6) & 63);
                if (__builtin_popcountll(l1[x >> 12]) == 0) {
                    root ^= 1ull << ((x >> 12) & 63);
                }
            }
        }
    }

    int get_min() {
        uint32_t p = __builtin_ctzll(root);
        p = (p << 6) + __builtin_ctzll(l1[p]);
        p = (p << 6) + __builtin_ctzll(l0[p]);
        return p;
    }

    int get_max() {
        uint32_t p = 63 - __builtin_clzll(root);
        p = (p << 6) + 63 - __builtin_clzll(l1[p]);
        p = (p << 6) + 63 - __builtin_clzll(l0[p]);
        return p;
    }
};
