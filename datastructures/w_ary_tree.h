struct Word {
    uint64_t mask;
    Word() : mask(0) {}
    
    void flip_bit(int p) { mask ^= 1ull << p; }
    int min_bit() { return __builtin_ctzll(mask); }
    int max_bit() { return 63 - __builtin_clzll(mask); }
};

struct WaryBase : public Word {
    bool flip(int p) {
        bool old = mask != 0;
        flip_bit(p);
        return (mask != 0) != old;
    }
    int min() { return min_bit(); }
    int max() { return max_bit(); }
};

template <int L>
struct WaryTree : public Word {
    array<conditional_t<(L > 2), WaryTree<L - 1>, WaryBase>, 64> nxt;

    static constexpr int block_sz = 1ull << (6 * (L - 1));

    bool flip(int p) {
        bool old = mask != 0;
        int block = p / block_sz;
        if (nxt[block].flip(p % block_sz)) {
            flip_bit(block);
        }
        return (mask != 0) != old;
    }
    int min() {
        int block = min_bit();
        return block * block_sz + nxt[block].min();
    }
    int max() {
        int block = max_bit();
        return block * block_sz + nxt[block].max();
    }
};