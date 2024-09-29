#pragma once

template <class T, class U>
T bsmin(T lo, T hi, U f) {
    assert(lo <= hi);
    hi++;
    for (T i = T(1) << __lg(hi - lo); i > 0; i >>= 1) {
        hi -= (hi - i >= lo && f(hi - i)) * i;
    }
    return hi;
}

template <class T, class U>
T bsmax(T lo, T hi, U f) {
    assert(lo <= hi);
    lo--;
    for (T i = T(1) << __lg(hi - lo); i > 0; i >>= 1) {
        lo += (lo + i <= hi && f(lo + i)) * i;
    }
    return lo;
}