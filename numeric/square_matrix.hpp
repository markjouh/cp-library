#pragma once

template<class T, int N> struct sq_matrix {
    array<array<T, N>, N> vals{};

    sq_matrix() {
        for (int i = 0; i < N; i++) {
            vals[i][i] = 1;
        }
    }

    array<T, N> &operator[](int p) {
        return vals[p];
    }

    friend sq_matrix pow(sq_matrix base, int exp) {
        sq_matrix res;
        while (exp) {
            if (exp & 1) {
                res *= base;
            }
            base *= base;
            exp >>= 1;
        }
        return res;
    }

    sq_matrix &operator*=(sq_matrix b) {
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

    friend sq_matrix operator*(sq_matrix a, sq_matrix b) {
        return a *= b;
    }
};
