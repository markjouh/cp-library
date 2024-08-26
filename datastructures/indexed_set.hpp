/* An order statistic tree using gnu pbds. Supports the following in O(log(N)):
 * st.find_by_order(k) finds the kth smallest element (0-indexed), and
 * st.order_of_key(v) counts the number of elements < v in the set.
 */

#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
