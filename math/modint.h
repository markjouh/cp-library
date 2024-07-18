template<int M> struct Mint {
    int v;
    
    Mint() {}

    Mint(ll x) {
        v = int(-M < x && x < M ? x : x % M);
        if (v < 0) v += M;
    }
 
    friend Mint pow(Mint base, int exp) {
        Mint res = 1;
        while (exp) {
            if (exp & 1) res *= base;
            base *= base;
            exp >>= 1;
        }
        return res;
    }

    Mint &operator+=(Mint b) { if ((v += b.v) >= M) v -= M; return *this; }
    Mint &operator-=(Mint b) { if ((v -= b.v) < 0) v += M; return *this; }
    Mint &operator*=(Mint b) { v = int(ll(v) * b.v % M); return *this; }
    Mint &operator/=(Mint b) { v = int(ll(v) * pow(b, M - 2).v % M); return *this; }

    friend Mint operator+(Mint a, Mint b) { return a += b; }
    friend Mint operator-(Mint a, Mint b) { return a -= b; }
    friend Mint operator*(Mint a, Mint b) { return a *= b; }
    friend Mint operator/(Mint a, Mint b) { return a /= b; }

    friend ostream &operator<<(ostream &os, Mint a) { return os << a.v; }
};

// using mi = Mint<int(1e9 + 7)>;
// using mi = Mint<998244353>;
