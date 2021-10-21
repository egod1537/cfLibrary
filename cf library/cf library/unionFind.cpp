struct UnionFind {
	int n;
	vector<int> dsu, rank;
	void Init(int _n) {
		dsu.clear(); dsu.resize(n = _n);
		rank.clear(); rank.resize(n = _n);
		iota(dsu.begin(), dsu.end(), 0);
	}
	int find(int x) { return (dsu[x] == x ? x : dsu[x] = find(dsu[x])); }
	bool merge(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (rank[a] < rank[b]) swap(a, b);
		if (rank[a] == rank[b]) rank[a]++;
		dsu[b] = a; return true;
	}
};

struct UnionFindRollBack {
	struct Info { int u, v, state; };
	int n;
	vector<int> dsu, rank;
	stack<Info> stk;
	void Init(int _n) {
		n = _n;
		dsu.resize(n); rank.resize(n, 1);
		for (int i = 0; i < n; i++) dsu[i] = i;
	}
	int find(int x) { return (dsu[x] == x ? x : find(dsu[x])); }
	bool merge(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (rank[a] < rank[b]) swap(a, b);
		dsu[b] = a;
		stk.push({ a, b, rank[a] == rank[b] });
		rank[a] += rank[a] == rank[b];
		return true;
	}
	void rollback(int cnt) {
		while (cnt--) {
			Info top = stk.top(); stk.pop();
			dsu[top.v] = top.v;
			rank[top.u] -= top.state;
		}
	}
};