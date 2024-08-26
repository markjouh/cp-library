/* Connectivity data structure limited to edge insertions.
 * Operations have inverse Ackermann complexity, which is for all intents and
 * purposes O(1).
 */

#pragma once

struct union_find {
    vector<int> a;

    union_find(int n) : a(n, -1) {}

    int size(int x) {
        return -a[find(x)];
    }

    int find(int x) {
        return a[x] < 0 ? x : a[x] = find(a[x]);
    }

    bool join(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return 0;
        }
        if (a[x] > a[y]) {
            swap(x, y);
        }
        a[x] += a[y];
        a[y] = x;
        return 1;
    }
};
