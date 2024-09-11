#pragma once

vector<int> minPF, primes;

void sieve(int n) {
  minPF.resize(n + 1);
  for (int i = 2; i <= n; i++) {
    if (!minPF[i]) {
      minPF[i] = i;
      primes.push_back(i);
      for (i64 j = 1ll * i * i; j <= n; j += i) {
        if (!minPF[j]) {
          minPF[j] = i;
        }
      }
    }
  }
}

template <class T>
vector<pair<T, int>> factor(T num) {
  vector<pair<T, int>> res;

  if (num <= sz(minPF) - 1) {
    while (num > 1) {
      int fac = minPF[num];
      res.emplace_back(fac, 0);
      while (num % fac == 0) {
        num /= fac;
        res.back().second++;
      }
    }
    return res;
  }

  for (int p : primes) {
    if (1ll * p * p > num) {
      break;
    }
    int exp = 0;
    while (num % p == 0) {
      num /= p;
      exp++;
    }
    if (exp) {
      res.emplace_back(p, exp);
    }
  }
  if (num > 1) {
    res.emplace_back(num, 1);
  }
  return res;
}

template <class T>
vector<T> genDivisors(vector<pair<T, int>> facs) {
  vector<T> res = {1};
  for (auto [p, exp] : facs) {
    const int oldSize = sz(res);
    T coeff = 1;
    for (int i = 0; i < exp; i++) {
      coeff *= p;
      for (int j = 0; j < oldSize; j++) {
        res.push_back(coeff * res[j]);
      }
    }
  }
  return res;
}