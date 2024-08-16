template<int MOD> struct Mint {
    int v;

    Mint(ll x = 0) : v(int(-MOD < x && x < MOD ? x : x % MOD) + (x < 0) * MOD) {}
 
    friend Mint pow(Mint base, int exp) {
        assert(exp >= 0);
        Mint res = 1;
        while (exp) {
            if (exp & 1) {
                res *= base;
            }
            base *= base;
            exp >>= 1;
        }
        return res;
    }
 
    Mint &operator+=(Mint b) { if ((v += b.v) >= MOD) v -= MOD; return *this; }
    Mint &operator-=(Mint b) { if ((v -= b.v) < 0) v += MOD; return *this; }
    Mint &operator*=(Mint b) { v = int(1ll * v * b.v % MOD); return *this; }
    Mint &operator/=(Mint b) { v = int(1ll * v * pow(b, MOD - 2).v % MOD); return *this; }
 
    friend Mint operator+(Mint a, Mint b) { return a += b; }
    friend Mint operator-(Mint a, Mint b) { return a -= b; }
    friend Mint operator*(Mint a, Mint b) { return a *= b; }
    friend Mint operator/(Mint a, Mint b) { return a /= b; }
    
    friend ostream &operator<<(ostream &os, Mint a) { return os << a.v; }
};
