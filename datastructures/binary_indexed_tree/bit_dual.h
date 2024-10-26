#include "bit.h"

template <class T>
struct BITDual {
    int n;
    BIT<T> pref, suff;

    BITDual(int n_) : n(n_), pref(n), suff(n) {}

    T sum(int r) {
        return pref.sum(r - 1) + suff.sum(n - r - 1) * (r + 1);
    }

    T sum(int l, int r) {
        return sum(r) - (l > 0 ? sum(l - 1) : 0);
    }

    void add(int r, T v) {
        pref.add(r, v * (r + 1));
        suff.add(n - r - 1, v);
    }

    void add(int l, int r, T v) {
        add(r, v);
        if (l > 0) {
            add(l - 1, T(0) - T(v));
        }
    }
};