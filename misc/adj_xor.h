// Add/delete elements, query for min pairwise XOR in set.

struct AdjXor {
    multiset<pi> vals;
    map<int, int> xors;
 
    void add(pi v) {
        vals.insert(v);
        auto it = vals.find(v);
        if (it != begin(vals)) {
            xors[v.fi ^ (*prev(it)).fi]++;
        }
        if (it != prev(end(vals))) {
            xors[v.fi ^ (*next(it)).fi]++;
        }
        if (it != begin(vals) && it != prev(end(vals))) {
            xors[(*prev(it)).fi ^ (*next(it)).fi]--;
        }
    }
 
    void remove(pi v) {
        auto it = vals.find(v);
        if (it != begin(vals)) {
            xors[v.fi ^ (*prev(it)).fi]--;
        }
        if (it != prev(end(vals))) {
            xors[v.fi ^ (*next(it)).fi]--;
        }
        if (it != begin(vals) && it != prev(end(vals))) {
            xors[(*prev(it)).fi ^ (*next(it)).fi]++;
        }
        vals.erase(it);
    }
 
    int get_min() {
        while (sz(xors) && begin(xors)->se == 0) {
            xors.erase(begin(xors));
        }
        return xors.empty() ? INT_MAX : begin(xors)->fi;
    }
};
