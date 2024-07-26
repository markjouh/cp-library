template<class T, int N> struct Matrix {
    arr<arr<T, N>, N> vals{};

    Matrix() {
        rep(i, N) {
            vals[i][i] = 1;
        }
    }

    arr<T, N> &operator[](int p) {
        return vals[p];
    }

    friend Matrix pow(Matrix base, int exp) {
        Matrix res;
        while (exp) {
            if (exp & 1) {
                res *= base;
            }
            base *= base;
            exp >>= 1;
        }
        return res;
    }

    Matrix &operator*=(Matrix b) {
        arr<arr<T, N>, N> res{};
        rep(i, N) {
            rep(j, N) {
                rep(k, N) {
                    res[i][j] += vals[i][k] * b.vals[k][j];
                }
            }
        }
        vals = res;
        return *this;
    }

    friend Matrix operator*(Matrix a, Matrix b) {
        return a *= b;
    }
};
