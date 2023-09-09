// Segtree
//
// range query point update
// 
// Segtree seg(n) // n = size of original array
// seg.build(arr) // optional
//
// query(l, r) // minimum and position
// upd(i, v) // update value in position i to v
//
// 0 indexed
// 
// https://codeforces.com/gym/104505/problem/F
// 
// O(log N) query, O(log N) update

typedef long long ftype;

typedef pair<int, int> ftype;

struct SegtreeNext {
    vector<ftype> tree;
    int n;
    const int INF = (int)1e9 + 17;
    const ftype NEUTRAL = {INF, INF};
    vector<int> nxt, arr;
    map<int, set<int>> pos;

    SegtreeNext() {}
    
    SegtreeNext(int n): n(n) {
        int sz = 1;
        while (sz < n) sz *= 2;
        this->n = sz;

        tree.assign(2 * sz, NEUTRAL);
        nxt.assign(2 * sz, INF);
    }

    ftype merge(ftype a, ftype b) {
        return min(a, b); // minimum and position
    }

    ftype query(int x, int lx, int rx, int l, int r) {
        if (rx < l || lx > r) return NEUTRAL;

        if (lx >= l && rx <= r) return tree[x];        
        
        int e = 2 * x + 1;
        int d = 2 * x + 2;
        int m = lx + (rx - lx) / 2;

        return merge(query(e, lx, m, l, r), query(d, m + 1, rx, l, r));
    }

    void update(int x, int lx, int rx, int idx, int val) {
        if (rx < idx || lx > idx) return;

        if (lx == idx && rx == idx) {
            tree[x] = {val, idx};
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
                tree[x] = {v[lx], lx};
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

    void update(int idx, int val) { // arr[idx] = {val, idx}
        update(0, 0, n - 1, idx, val);
    }

    void build(vector<int> &arr) {
        this->arr = arr;
        int nt = arr.size();
 
        // build pos
        for (int i = 0; i < nt; i++) {
            pos[arr[i]].insert(i);
        }
 
        // build nxt
        map<int, int> cur;
 
        for (int i = nt - 1; i >= 0; i--) {
            if (cur.find(arr[i]) != cur.end()) {
                nxt[i] = cur[arr[i]];
            } else {
                nxt[i] = INF;
            }
          
            cur[arr[i]] = i;
        }
        
        // build seg
        build(0, 0, n - 1, nxt);
    }

    // remove the element in position idx (arr[idx] = INF)
    void rem(int idx) {
        auto it = pos[arr[idx]].find(idx);
 
        if (it != pos[arr[idx]].begin()) {
            auto pit = prev(it);
            auto nit = next(it);
 
            if (nit != pos[arr[idx]].end()) {
                nxt[ *pit ] = *nit;
                update(*pit, *nit);
            } else {
                nxt[ *pit ] = INF;
                update(*pit, INF);
            }
        }
 
        pos[arr[idx]].erase(it);
        nxt[idx] = INF;
        arr[idx] = INF;
        update(idx, INF);
    }

    // arr[idx] = val (remember to do rem(idx) before)
    void add(int idx, int val) {
        // add
        arr[idx] = val;
 
        pos[arr[idx]].insert(idx);
        auto it = pos[arr[idx]].find(idx);
      
        // previous
        if (it != pos[arr[idx]].begin()) {
            auto pit = prev(it);
        
            nxt[*pit] = *it;
            update(*pit, *it);
        }
    
        // current
        auto nit = next(it);
 
        if (nit != pos[arr[idx]].end()) {
            nxt[*it] = *nit;
            update(*it, *nit);
        } else {
            nxt[*it] = INF;
            update(*it, INF);
        }
    }

    void upd(int idx, int val) {
        rem(idx);
        add(idx, val);
    }
};