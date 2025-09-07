auto gen_suffix_array(const string &s) {
    const int n = sz(s) + 1;

    vector<int> sa(n);
    sa[0] = n - 1;
    iota(begin(sa) + 1, end(sa), 0);
    sort(begin(sa) + 1, end(sa), [&](int x, int y) {
        return s[x] < s[y];
    });

    vector<int> ec(n);
    ec[sa[1]] = 1;
    for (int i = 2; i < n; i++) {
        ec[sa[i]] = ec[sa[i - 1]] + (s[sa[i]] != s[sa[i - 1]]);
    }

    for (int i = 1; i < n; i *= 2) {
        transform(all(sa), begin(sa), [&](int x) {
            x -= i;
            return x + (x < 0) * n;
        });

        vector<int> pos(n + 1);
        for (int x : ec) {
            pos[x + 1]++;
        }
        partial_sum(all(pos), begin(pos));

        vector<int> new_sa(n);
        for (int j : sa) {
            new_sa[pos[ec[j]]++] = j;
        }
        sa = new_sa;

        vector<int> new_ec(n);
        for (int j = 1; j < n; j++) {
            int x = sa[j - 1], y = sa[j];
            new_ec[y] = new_ec[x] + (ec[y] != ec[x] || ec[y + i - (y + i >= n) * n] != ec[x + i - (x + i >= n) * n]);
        }
        ec = new_ec;
    }

    return sa;
}

auto gen_lcp(const vector<int> &sa, const string &s) {
    const int n = sz(sa);

    vector<int> rank(n);
    for (int i = 0; i < n; i++) {
        rank[sa[i]] = i;
    }

    vector<int> lcp(n);
    int cur = 0;
    for (int i = 0; i < n - 1; i++) {
        int prev = sa[rank[i] - 1];
        while (s[i + cur] == s[prev + cur]) {
            cur++;
        }
        lcp[rank[i]] = cur;
        cur = max(cur - 1, 0);
    }
    return lcp;
}