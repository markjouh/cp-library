#pragma once

template <class T, int N>
struct SquareMatrix {
  array<array<T, N>, N> vals{};

  SquareMatrix() {
    for (int i = 0; i < N; i++) {
      vals[i][i] = 1;
    }
  }

  array<T, N> &operator[](int p) {
    return vals[p];
  }

  friend SquareMatrix pow(SquareMatrix base, int exp) {
    SquareMatrix res;
    while (exp) {
      if (exp & 1) {
        res *= base;
      }
      base *= base;
      exp >>= 1;
    }
    return res;
  }

  SquareMatrix &operator*=(SquareMatrix b) {
    array<array<T, N>, N> res{};
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        for (int k = 0; k < N; k++) {
          res[i][j] += vals[i][k] * b.vals[k][j];
        }
      }
    }
    vals = res;
    return *this;
  }

  friend SquareMatrix operator*(SquareMatrix a, SquareMatrix b) {
    return a *= b;
  }
};
