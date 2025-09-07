// http://isaku-wada.my.coocan.jp/rand/rand.html
// https://github.com/maspypy/library/blob/bd963151adcd2ad29642a2dcea65a15420d1767d/random/base.hpp

uint64_t rng() {
  static uint64_t x = uint64_t(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count()) * 0x8cde9e0f1d3b04d7;
  x ^= x << 7;
  x ^= x >> 9;
  return x;
}

uint64_t rng(uint64_t n) {
  return rng() % n;
}

int64_t rng(int64_t l, int64_t r) {
  return l + rng() % (r - l);
}

template <class T>
void shuffle(vector<T> &a) {
  for (int i = 0; i < sz(a); i++) {
    int j = rng() % (i + 1);
    if (i != j) {
      swap(a[i], a[j]);
    }
  }
}