template <class T, int N>
struct square_matrix {
    array<array<T, N>, N> vals{};

    square_matrix() {
        for (int i = 0; i < N; i++) {
            vals[i][i] = 1;
        }
    }

    array<T, N> &operator[](int p) {
        return vals[p];
    }

    friend square_matrix pow(square_matrix base, int exp) {
        square_matrix res;
        while (exp) {
            if (exp & 1) {
                res *= base;
            }
            base *= base;
            exp >>= 1;
        }
        return res;
    }

    square_matrix &operator*=(square_matrix b) {
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

    friend square_matrix operator*(square_matrix a, square_matrix b) {
        return a *= b;
    }
};
