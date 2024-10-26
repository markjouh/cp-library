template <class T, int B>
struct MoQueries {
    vector<array<int, 3>> queries;
    vector<T> res;

    MoQueries() {}

    void insert(int l, int r) {
        queries.push_back({l, r, sz(queries)});
    }

    template<class AddL, class DelL, class AddR, class DelR, class Query>
    void solve(AddL addL, DelL delL, AddR addR, DelR delR, Query query) {
        sort(all(queries), [](array<int, 3> a, array<int, 3> b) {
            if (a[1] / B != b[1] / B) {
                return a[1] / B < b[1] / B;
            }
            return a[0] < b[0];
        });
        res.resize(sz(queries));

        int curL = 0, curR = -1;
        for (auto [l, r, idx] : queries) {
            while (curL > l) {
                addL(--curL);
            }
            while (curR < r) {
                addR(++curR);
            }
            while (curL < l) {
                delL(curL++);
            }
            while (curR > r) {
                delR(curR--);
            }
            res[idx] = query();
        }
    }

    template<class Add, class Del, class Query>
    void solve(Add add, Del del, Query query) {
        solve<Add, Del, Add, Del, Query>(add, del, add, del, query);
    }
};