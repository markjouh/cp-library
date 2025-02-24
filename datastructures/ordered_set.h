#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds; 

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <class T>
struct ordered_multiset {
  int time = 0;
  ordered_set<pair<T, int>> st;
 
  void insert(T x) {
    st.insert({x, time++});
  }
 
  void extract(T x) {
    auto it = st.lower_bound({x, 0});
    if (it != end(st) && it->first == x) {
      st.erase(it);
    }
  }
 
  T find_by_order(int k) {
    return (*st.find_by_order(k)).first;
  }
 
  int order_of_key(T x) {
    return st.order_of_key({x, 0});
  }
};
