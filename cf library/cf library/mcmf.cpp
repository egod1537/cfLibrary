struct MCMF {
	struct Edge {
		int to, cap, f, cost;
		int dual;
		int spare() { return cap - f; }
	};
	int n, ans, cot;
	vector<vector<Edge>> E;
	void init(int _n) {
		n = _n;
		E.clear();  E.resize(n);
	}
	void add_edge(int u, int v, int cap, int cost) {
		E[u].push_back({ v,cap, 0, cost });
		E[v].push_back({ u, 0, 0, -cost });
		E[u].back().dual = E[v].size() - 1;
		E[v].back().dual = E[u].size() - 1;
	}
	Edge* GetEdge(int u, int v) {
		for (auto& e : E[u])
			if (e.to == v) return &e;
		return nullptr;
	}
	bool spfa(int s, int t, bool apply = true) {
		vector<int> dst(n, 1e9);
		vector<int> prv(n, -1);
		vector<Edge*> sel(n);
		vector<bool> chk(n);
		dst[s] = 0;
		queue<int> q;
		q.push(s); chk[s] = true;
		while (q.size()) {
			int top = q.front(); q.pop();
			chk[top] = false;
			for (auto& l : E[top]) {
				if (l.spare() > 0 && dst[top] + l.cost < dst[l.to]) {
					dst[l.to] = dst[top] + l.cost;
					prv[l.to] = top;
					sel[l.to] = &l;
					if (!chk[l.to]) {
						q.push(l.to);
						chk[l.to] = true;
					}
				}
			}
		}
		if (prv[t] == -1) return false;
		if (apply) {
			int flow = 1e9;
			for (int i = t; i != s; i = prv[i]) flow = min(flow, sel[i]->spare());
			for (int i = t; i != s; i = prv[i]) {
				sel[i]->f += flow;
				E[sel[i]->to][sel[i]->dual].f -= flow;
				cot += flow * sel[i]->cost;
			}
			ans += flow;
		}
		return true;
	}
	pair<int, int> flow(int s, int t) {
		ans = 0; cot = 0;
		while (spfa(s, t));
		return { ans, cot };
	}
};