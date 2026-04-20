#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"

#include "../../../template/template.h"
#include "../../../strings/suffix_array.h"

int main() {
  string s;
  cin >> s;
  int64_t n = ssize(s);
  auto sa = gen_suffix_array(s);
  auto lcp = gen_lcp(sa, s);
  int64_t ans = n * (n + 1) / 2;
  for (int i = 2; i <= n; i++) {
    ans -= lcp[i];
  }
  cout << ans << '\n';
}
