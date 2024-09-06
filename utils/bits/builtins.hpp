#pragma once

#if !__has_builtin(__lg)
template <class T>
int __lg(T x) {
  int res = 0;
  while (x >>= 1) {
    res++;
  }
  return res;
}
#endif

#if !__has_builtin(__builtin_popcount)
int __builtin_popcount(unsigned int x) {
  int res = 0;
  for (int i = 0; i < 32; i++) {
    res += (x >> i) & 1;
  }
  return res;
}
#endif

#if !__has_builtin(__builtin_popcountll)
int __builtin_popcountll(unsigned long long x) {
  int res = 0;
  for (int i = 0; i < 64; i++) {
    res += (x >> i) & 1;
  }
  return res;
}
}
#endif