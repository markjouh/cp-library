#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include "../../../template/template.h"
#include "../../../strings/suffix_array.h"

int main() {
  string s;
  cin >> s;
  auto sa = gen_suffix_array(s);
  for (int i = 1; i < ssize(sa); i++) {
    cout << sa[i];
    cout << " \n"[i + 1 == ssize(sa)];
  }
}
