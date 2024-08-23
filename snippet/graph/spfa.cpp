namespace SPFA {
    vector<int> bfs(const Graph& g, vector<int> s) {
        int n = g.n;
        vector<int> ret(n, -1);
        queue<int> q;
        for (int w : s) {
            assert(0 <= w && w < n);
            q.push(w);
            ret[w] = 0;
        }
        while (q.size()) {
            int top = q.front(); q.pop();
            for (auto& l : g.V[top])
                if (ret[l.v] == -1) {
                    ret[l.v] = ret[top] + 1;
                    q.push(l.v);
                }
        }
        return ret;
    }
    vector<int> bfs(const Graph& g, int s) {
        vector<int> t = { s };
        return bfs(g, t);
    }
    vector<int> bfs01(const Graph& g, vector<int> s) {
        for (auto& l : g.line)
            assert(0 <= l.c && l.c <= 1);
        int n = g.n;
        vector<int> ret(n, 1e9);
        deque<int> dq;
        for (int w : s) {
            assert(0 <= w && w < n);
            dq.push_back(w);
            ret[w] = 0;
        }
        while (dq.size()) {
            int top = dq.front(); dq.pop_front();
            for (auto& l : g.V[top]) {
                if (ret[l.v] > ret[top] + l.c) {
                    ret[l.v] = ret[top] + l.c;
                    if (l.c) dq.push_back(l.v);
                    else dq.push_front(l.v);
                }
            }
        }
        return ret;
    }
    vector<int> bfs01(const Graph& g, int s) {
        vector<int> t = { s };
        return bfs01(g, t);
    }
    template<typename T>
    struct Q {
        int pos;
        T cost;
    };
    template<typename T>
    bool operator<(const Q<T>& a, const Q<T>& b) {
        return a.cost > b.cost;
    }
    template<typename T, T e> 
    vector<T> dijkstra(const Graph& g, vector<T> s) {
        for (auto& l : g.line)
            assert(l.c >= 0);
        int n = g.n;
        vector<T> ret(n, e);
        priority_queue<Q<T>> pq;
        for (int w : s) {
            assert(0 <= w && w < n);
            pq.push({w, 0});
            ret[w] = 0;
        }
        while (pq.size()) {
            Q<T> top = pq.top(); pq.pop();
            if (top.cost > ret[top.pos]) continue;
            for (auto& l : g.V[top.pos]) {
                if (ret[l.v] > l.c + top.cost) {
                    ret[l.v] = l.c + top.cost;
                    pq.push({l.v, ret[l.v]});
                }
            }
        }
        return ret;
    }
    template<typename T, T e>
    vector<T> dijkstra(const Graph& g, int s) {
        vector<int> t = { s };
        return dijkstra<T,e>(g, t);
    }
    template<typename T, T e>
    vector<T> bellman_ford(const Graph& g, vector<int> s) {
        int n = g.n;
        vector<T> ret(n, e);
        for (int w : s) {
            assert(0 <= w && w < n);
            ret[w] = 0;
        }
        for(int i=0; i < n; i++)
            for(auto&[u,v,c] : g.line)
                if (ret[u] != e && ret[v] > ret[u] + c) {
                    ret[v] = ret[u] + c;
                    if (i == n - 1) return vector<T>(n, e);
                }
        return ret;
    }
    template<typename T, T e>
    vector<T> bellman_ford(const Graph& g, int s) {
        vector<int> t = { s };
        return bellman_ford<T, e>(g, t);
    }
    template<typename T, T e>
    vector<vector<T>> floyd_warshall(const Graph& g) {
        int n = g.n;
        vector<vector<T>> dst(n, vector<T>(n, e));
        for (auto& [u, v, c] : g.line)
            dst[u][v] = min(dst[u][v], (T)c);
        for (int i = 0; i < n; i++) dst[i][i] = 0;
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (dst[i][k] != e && dst[k][j] != e)
                        dst[i][j] = min(dst[i][j], dst[i][k] + dst[k][j]);
        return dst;
    }
}