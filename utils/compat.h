#ifndef COMPAT_H
#define COMPAT_H

#ifdef __clang__

template <class T>
unsigned int __lg(T x) {
    unsigned int res = 0;
    while (x > 0) {
        x >>= 1;
        res++;
    }
    return res;
}

#endif // __clang__

#endif // COMPAT_H