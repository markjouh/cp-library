template<class T> ll fst_true(ll lo, ll hi, T f) {
    while (lo + 1 < hi) {
        ll mid = (lo + hi) / 2;
        (f(mid) ? hi : lo) = mid;
    }
    return hi;
}

template<class T> ll lst_true(ll lo, ll hi, T f) {
    lo--;
    while (lo + 1 < hi) {
        ll mid = (lo + hi) / 2;
        (f(mid) ? lo : hi) = mid;
    }
    return lo;
}
