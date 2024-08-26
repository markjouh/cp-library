#pragma once
#include "mod_int.hpp"

template<class T, int N> struct matrix {
    array<array<T, N>, N> vals{};

    matrix() {
        for (int i = 0; i < N; i++) {
            vals[i][i] = 1;
        }
    }

    array<T, N> &operator[](int p) {
        return vals[p];
    }

    friend matrix pow(matrix base, int exp) {
        matrix res;
        while (exp) {
            if (exp & 1) {
                res *= base;
            }
            base *= base;
            exp >>= 1;
        }
        return res;
    }

    matrix &operator*=(matrix b) {
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

    friend matrix operator*(matrix a, matrix b) {
        return a *= b;
    }
};
