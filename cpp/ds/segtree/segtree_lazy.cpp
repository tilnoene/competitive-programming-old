using ll = long long;

struct segTree {
    int size;
    vector<ll> tree, lazy;

    ll modify_op(ll a, ll b, ll len) {
        if (b == -1) return a;
        return b * len;
    }

    void apply_mod_op(ll &a, ll b, ll len) {
        a = modify_op(a, b, len);
    }

    ll merge(ll a, ll b) {
        return a + b;
    }

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2 * size, 0LL);
        lazy.assign(2 * size, -1);
    }

    void propagate(int x, int lx, int rx) {
        if (rx - lx == 1) return;
        
        int m = (lx + rx) / 2;
        apply_mod_op(lazy[2 * x + 1], lazy[x], 1);
        apply_mod_op(tree[2 * x + 1], lazy[x], m - lx);

        apply_mod_op(lazy[2 * x + 2], lazy[x], 1);
        apply_mod_op(tree[2 * x + 2], lazy[x], rx - m);
        
        lazy[x] = -1;
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

    void update(int l, int r, int v, int x, int lx, int rx) {
        propagate(x, lx, rx);

        if (lx >= r || l >= rx) return;
        if (lx >= l && rx <= r) {
            apply_mod_op(lazy[x], v, 1);
            apply_mod_op(tree[x], v, rx - lx);
            return;
        }

        int m = (lx + rx) / 2;
        update(l, r, v, 2 * x + 1, lx, m);
        update(l, r, v, 2 * x + 2, m, rx);

        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void update(int l, int r, int v) {
        update(l, r, v, 0, 0, size);
    }

    ll query(int l, int r, int x, int lx, int rx) {
        propagate(x, lx, rx);

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

    void debug() {
        for (auto e : tree)
            cout << e << ' ';
        cout << endl;

        for (auto e : lazy)
            cout << e << ' ';
        cout << endl;
    }
};