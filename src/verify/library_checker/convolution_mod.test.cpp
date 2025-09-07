#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include <bits/stdc++.h>
using namespace std;

#include "../../numeric/mint.h"

using mi = Mint<998244353>;

const int MOD = 998244353;

vector<mi> convolution(vector<mi> a, vector<mi> b) {
  int n = a.size() + b.size() - 1;
  int size = 1;
  while (size < n) size <<= 1;
  
  a.resize(size);
  b.resize(size);
  
  auto ntt = [&](vector<mi>& f, bool inv) {
    int n = f.size();
    if (n == 1) return;
    
    mi g = pow(mi(3), (MOD - 1) / n);
    if (inv) g = mi(1) / g;
    
    for (int i = 1, j = 0; i < n; i++) {
      int bit = n >> 1;
      for (; j & bit; bit >>= 1) {
        j ^= bit;
      }
      j ^= bit;
      if (i < j) swap(f[i], f[j]);
    }
    
    for (int len = 2; len <= n; len <<= 1) {
      mi w = pow(g, n / len);
      for (int i = 0; i < n; i += len) {
        mi wn = 1;
        for (int j = 0; j < len / 2; j++) {
          mi u = f[i + j];
          mi v = f[i + j + len / 2] * wn;
          f[i + j] = u + v;
          f[i + j + len / 2] = u - v;
          wn *= w;
        }
      }
    }
    
    if (inv) {
      mi n_inv = mi(1) / mi(n);
      for (auto& x : f) x *= n_inv;
    }
  };
  
  ntt(a, false);
  ntt(b, false);
  
  for (int i = 0; i < size; i++) {
    a[i] *= b[i];
  }
  
  ntt(a, true);
  
  a.resize(n);
  return a;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n, m;
  cin >> n >> m;
  
  vector<mi> a(n), b(m);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[i] = x;
  }
  
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    b[i] = x;
  }
  
  vector<mi> c = convolution(a, b);
  
  for (int i = 0; i < n + m - 1; i++) {
    cout << c[i];
    if (i < n + m - 2) cout << " ";
  }
  cout << "\n";
  
  return 0;
}