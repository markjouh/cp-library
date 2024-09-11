#pragma once

struct BinaryTrie {
  vector<array<int, 2>> nxt;
  vector<int> cnt;

  BinaryTrie() : nxt(1, {-1, -1}), cnt(1, 0) {}

  int count(unsigned int x) {
    int pos = 0;
    for (int i = 31; i >= 0; i--) {
      pos = nxt[pos][(x >> i) & 1];
      if (pos == -1) {
        return 0;
      }
    }
    return cnt[pos];
  }

  void insert(unsigned int x) {
    int pos = 0;
    for (int i = 31; i >= 0; i--) {
      bool dir = (x >> i) & 1;
      if (nxt[pos][dir] == -1) {
        nxt[pos][dir] = sz(nxt);
        nxt.push_back({-1, -1});
        cnt.push_back(0);
      }
      pos = nxt[pos][dir];
      cnt[pos]++;
    }
  }

  void remove(unsigned int x) {
    int pos = 0;
    for (int i = 31; i >= 0; i--) {
      pos = nxt[pos][(x >> i) & 1];
      cnt[pos]--;
    }
  }

  unsigned int minXor(unsigned int x) {
    int pos = 0;
    unsigned int res = 0;
    for (int i = 31; i >= 0; i--) {
      bool dir = (x >> i) & 1;
      if (nxt[pos][dir] == -1 || cnt[nxt[pos][dir]] == 0) {
        res |= 1 << i;
        pos = nxt[pos][dir ^ 1];
      } else {
        pos = nxt[pos][dir];
      }
    }
    return res;
  }

  unsigned int maxXor(unsigned int x) {
    static const unsigned int mask = -1;
    return mask ^ minXor(x ^ mask);
  }
};