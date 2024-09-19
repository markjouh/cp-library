#pragma once

template <class T>
struct MinXorSet {
    multiset<T> xors, vals;

    MinXorSet() {}

    void insert(T x) {
        vals.insert(x);
        auto it = vals.find(x);
        if (it != begin(vals) && it != prev(end(vals))) {
            xors.extract(*next(it) ^ *prev(it));
        }
        if (it != begin(vals)) {
            xors.insert(x ^ *prev(it));
        }
        if (it != prev(end(vals))) {
            xors.insert(x ^ *next(it));
        }
    }

    void remove(T x) {
        auto it = vals.find(x);
        if (it != begin(vals) && it != prev(end(vals))) {
            xors.insert(*next(it) ^ *prev(it));
        }
        if (it != begin(vals)) {
            xors.extract(x ^ *prev(it));
        }
        if (it != prev(end(vals))) {
            xors.extract(x ^ *next(it));
        }
        vals.extract(x);
    }

    T get() {
        return xors.empty() ? numeric_limits<T>::max() : *begin(xors);
    }
};