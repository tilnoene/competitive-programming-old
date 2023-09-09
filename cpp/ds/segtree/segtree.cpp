// Segtree
//
// range query point update
// 
// Segtree seg(n) // n = size of original array
// seg.build(arr) // optional
//
// query(l, r) // query (sum/maximum/minimum) in interval [l, r]
// update(i, v) // update value in position i to v
//
// merge(a, b) // change to desired operation
// ftype // the node type
// 0 indexed
// 
// https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/A
// 
// O(log N) query, O(log N) update

typedef long long ftype;

struct Segtree {
    vector<ftype> tree;
    int n;
    const ftype NEUTRAL = 0;

    Segtree() {}
    
    Segtree(int n): n(n) {
        int sz = 1;
        while (sz < n) sz *= 2;
        this->n = sz;

        tree.assign(2 * sz, NEUTRAL);
    }

    ftype merge(ftype a, ftype b) {
        return a + b;
    }

    ftype query(int x, int lx, int rx, int l, int r) {
        if (rx < l || lx > r) return NEUTRAL;

        if (lx >= l && rx <= r) return tree[x];        
        
        int e = 2 * x + 1;
        int d = 2 * x + 2;
        int m = lx + (rx - lx) / 2;

        return merge(query(e, lx, m, l, r), query(d, m + 1, rx, l, r));
    }

    void update(int x, int lx, int rx, int idx, ftype val) {
        if (rx < idx || lx > idx) return;

        if (lx == idx && rx == idx) {
            tree[x] = val;
            return;
        }

        int e = 2 * x + 1;
        int d = 2 * x + 2;
        int m = lx + (rx - lx) / 2;

        update(e, lx, m, idx, val);
        update(d, m + 1, rx, idx, val);

        tree[x] = merge(tree[e], tree[d]);
    }

    void build(int x, int lx, int rx, vector<int>& v) {
        if (lx == rx) {
            if (lx < (int)v.size()) {
                tree[x] = v[lx];
            }

            return;
        }

        int e = 2 * x + 1;
        int d = 2 * x + 2;
        int m = lx + (rx - lx) / 2;

        build(e, lx, m, v);
        build(d, m + 1, rx, v);

        tree[x] = merge(tree[e], tree[d]);
    }

    ftype query(int l, int r) { // [l, r]
        return query(0, 0, n - 1, l, r);
    }

    void update(int idx, ftype val) { // arr[idx] = val
        update(0, 0, n - 1, idx, val);
    }

    void build(vector<int>& v) {
        build(0, 0, n - 1, v);
    }
};