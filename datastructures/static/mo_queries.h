template <class T, int K>
struct mo_queries {
    vector<array<int, 3>> queries;
    vector<T> res;

    mo_queries() {}

    void insert(int l, int r) {
        queries.push_back({l, r, sz(queries)});
    }

    template <class F1, class F2, class F3, class F4, class F5>
    void solve(F1 add_l, F2 del_l, F3 add_r, F4 del_r, F5 query) {
        sort(all(queries), [](array<int, 3> a, array<int, 3> b) {
            if (a[1] / K != b[1] / K) {
                return a[1] / K < b[1] / K;
            }
            return a[0] < b[0];
        });
        res.resize(sz(queries));

        int cur_l = 0, cur_r = -1;
        for (auto [l, r, idx] : queries) {
            while (cur_l > l) {
                add_l(--cur_l);
            }
            while (cur_r < r) {
                add_r(++cur_r);
            }
            while (cur_l < l) {
                del_l(cur_l++);
            }
            while (cur_r > r) {
                del_r(cur_r--);
            }
            res[idx] = query();
        }
    }

    template <class F1, class F2, class F3>
    void solve(F1 add, F2 del, F3 query) {
        solve<F1, F2, F1, F2, F3>(add, del, add, del, query);
    }
};