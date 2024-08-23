struct Graph {
    struct line { int u, v, c; };
    int n, m;
    vector<vector<line>> V;
    vector<line> line;
    vector<int> ind, dst;
    Graph() {}
    Graph(int _n) { init(_n); }
    void init(int _n) {
        n = _n; m = 0;
        reset(V, n); reset(ind, n);
        reset(dst, n); line.clear();
    }
    void add_edge(int u, int v, int c=0) {
        V[u].push_back({ u, v, c });
        ind[v]++;
        line.push_back({u,v,c});
        m = 0;
    }
};