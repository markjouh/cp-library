#pragma once

vector<mi> fact, factI;

void genFact(int n) {
  fact.resize(n + 1);
  factI.resize(n + 1);
  fact[0] = fact[1] = factI[0] = factI[1] = 1;
  for (int i = 2; i <= n; i++) {
    fact[i] = fact[i - 1] * i;
  }
  factI[n] = 1 / fact[n];
  for (int i = n - 1; i >= 2; i--) {
    factI[i] = factI[i + 1] * (i + 1);
  }
}

mi nck(int n, int k) {
  if (n < k || k < 0) {
    return 0;
  }
  return fact[n] * factI[k] * factI[n - k];
}

mi partitions(int items, int bins) {
  if (bins == 0) {
    return items == 0;
  }
  return nck(bins + items - 1, bins - 1);
}