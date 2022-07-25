struct segTree {
    int size;
    vector<ll> tree;

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2 * size, 0LL);
    }

    ll merge(ll a, ll b) {
        return a + b;
    }

    void build(vector<int> &arr, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)arr.size())
                tree[x] = arr[lx];
            
            return;
        }
        
        int m = (lx + rx) / 2;
        build(arr, 2 * x + 1, lx, m);
        build(arr, 2 * x + 2, m, rx);

        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void build(vector<int> &arr) {
        build(arr, 0, 0, size);
    }

    void update(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = v;
            return;
        }

        int m = (lx + rx) / 2;
        if (i < m) {
            update(i, v, 2 * x + 1, lx, m);
        } else {
            update(i, v, 2 * x + 2, m, rx);
        }

        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void update(int i, int v) {
        update(i, v, 0, 0, size);
    }

    ll query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || l >= rx) return 0;
        if (lx >= l && rx <= r) return tree[x];

        int m = (lx + rx) / 2;
        ll s1 = query(l, r, 2 * x + 1, lx, m);
        ll s2 = query(l, r, 2 * x + 2, m, rx);

        return merge(s1, s2);
    }

    ll query(int l, int r) {
        return query(l, r, 0, 0, size);
    }

    ll bb(int x, int lx, int rx, int l, int r) {
    	if (rx - lx == 1) {
    	    if (lx > r) {
    	        return r;
    	    }
    	    
            return lx;
        }
    
        int m = (lx + rx) / 2;
        if (tree[2 * x + 1] == 0) {
            return bb(2 * x + 2, m, rx, l, r);
        } else {
            return bb(2 * x + 1, lx, m, l, r);
        }
    }

    ll bb(ll l, ll r) {
        return bb(0, 0, size, l, r);
    }
};