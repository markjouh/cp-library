#pragma once

constexpr uint64_t pow_94[10] = {1, 94, 8836, 830584, 78074896, 7339040224, 689869781056, 64847759419264, 6095689385410816, 572994802228616704};

template <class T, int W>
string encode(T x) {
  if constexpr (is_integral_v<T>) {
    string res(W, 0);
    for (int i = 0; i < W; i++) {
      res[i] = char(33 + x % 94);
      x /= 94;
    }
    return res;
  } else {
    string res;
    for (auto &y : x) {
      res += encode<typename T::value_type, W>(y);
    }
    return res;
  }
}

template <class T, int W>
T decode(string s) {
  if constexpr (is_integral_v<T>) {
    T res = 0;
    for (int i = 0; i < W; i++) {
      res += pow_94[i] * uint64_t(s[i] - 33);
    }
    return res;
  } else {
    constexpr int segs = tuple_size_v<T>;
    const int len = ssize(s) / segs;
    T res;
    for (int i = 0; i < segs; i++) {
      res[i] = decode<typename T::value_type, W>(s.substr(len * i, len));
    }
    return res;
  }
}

#define make_encoded(type, x, w) cout << "const " << type << ' ' << #x << " = decode<" << type << ", " << w << ">(R\"zzzzz(" << encode<decltype(x), w>(x) << ")zzzzz\")" << endl