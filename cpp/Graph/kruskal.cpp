struct DSU {
    int n;
    vector<int> link, sizes;

    DSU(int n) {
        this->n = n;
        link.assign(n+1, 0);
        sizes.assign(n+1, 1);

        for (int i = 0; i <= n; i++)
            link[i] = i;
    }

    int find(int x) {
        while (x != link[x])
            x = link[x];
        
        return x;
    }

    bool same(int a, int b) {
        return find(a) == find(b);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        
        if (a == b) return;
        
        if (sizes[a] < sizes[b])
            swap(a, b);
            
        sizes[a] += sizes[b];
        link[b] = a;
    }
};

struct Edge {
    int u, v;
    long long weight;
    
    Edge() {}
    
    Edge(int u, int v, long long weight) : u(u), v(v), weight(weight) {}
    
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

vector<Edge> kruskal(vector<Edge> edges, int n) {
    vector<Edge> result; // arestas da MST
    long long cost = 0;

    sort(edges.begin(), edges.end());

    DSU dsu(n);

    for (auto e : edges) {
        if (!dsu.same(e.u, e.v)) {
            cost += e.weight;
            result.push_back(e);
            dsu.unite(e.u, e.v);
        }
    }

    return result;
}