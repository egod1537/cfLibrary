struct UF {
    struct info { int u, v, c; };
    int n;
    vector<int> dsu, sz;
    stack<info> stk;
    void init(int _n) {
        stk_clear(stk);
        n = _n;
        reset(dsu, n); iota(all(dsu), 0);
        reset_v(sz, n, 1);
    }
    int find(int x) { return dsu[x] == x ? x : (dsu[x] = find(dsu[x])); }
    bool merge(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        dsu[b] = a;
        stk.push({a, b, sz[a] == sz[b]});
        sz[a] += sz[a] == sz[b];
        return true;
    }
    bool join(int a, int b) { return find(a) == find(b); }
    void rollback(int cnt=1) {
        while (cnt--) {
            info top = stk.top(); stk.pop();
            dsu[top.v] = top.v;
            sz[top.u] -= top.c;
        }
    }
    vector<vector<int>> groups(){
        vector<int> cnt(n), id, rid(n);
        for(int i=0; i < n; i++){
            int p = find(i);
            if(!cnt[p]){
                rid[p] = id.size();
                id.push_back(p);
            }
            cnt[p]++;
        }
        vector<vector<int>> ret(sz(id));
        for(int i=0; i < n; i++)
            ret[rid[find(i)]].push_back(i);
        return ret;
    }
};