#pragma once

template<class T> db bsmin_reals(db lo, db hi, T f) {
    assert(sizeof(uint64_t) >= sizeof(db));
    assert(lo <= hi);
    uint64_t l = reinterpret_cast<uint64_t&>(lo), r = reinterpret_cast<uint64_t&>(hi) + 1;
    for (uint64_t i = 1ull << __lg(r - l); i > 0; i >>= 1) {
        uint64_t nxt = r - i;
        r -= (nxt >= l && f(reinterpret_cast<db&>(nxt))) * i;
    }
    return reinterpret_cast<db&>(r);
}

template<class T> db bsmax_reals(db lo, db hi, T f) {
    assert(sizeof(uint64_t) >= sizeof(db));
    assert(lo <= hi);
    uint64_t l = reinterpret_cast<uint64_t&>(lo) - 1, r = reinterpret_cast<uint64_t&>(hi);
    for (uint64_t i = 1ull << __lg(r - l); i > 0; i >>= 1) {
        uint64_t nxt = l + i;
        l += (nxt <= r && f(reinterpret_cast<db&>(nxt))) * i;
    }
    return reinterpret_cast<db&>(l);
}
