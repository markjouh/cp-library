template <class T>
struct Compress {
    vector<T> vals;
    bool ready = true;
 
    void init() {
        if (!ready) {
            sort(all(vals));
            vals.resize(unique(all(vals)) - begin(vals));
            ready = true;
        }
    }
    void add(T x) {
        vals.push_back(x);
        ready = false;
    }
 
    int size() {
        init();
        return vals.size();
    }
    int operator[](int p) {
        init();
        return vals[p];
    }
    int get(T x) {
        init();
        return lower_bound(all(vals), x) - begin(vals);
    }
};