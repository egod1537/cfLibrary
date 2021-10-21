struct Fenwick {
	int n;
	vector<ll> tree;
	void Init(int _n) {
		n = _n;
		tree.resize(n + 1);
	}
	void udpate(int idx, ll diff) {
		idx++;
		for (;; idx += (idx & -idx)) tree[idx] += diff;
	}
	ll query(int idx) {
		ll ans = 0; idx++;
		for (; idx <= n; idx -= (idx & -idx)) ans += tree[idx];
		return ans;
	}
	ll query(int l, int r) { return query(r) - query(l - 1); }
};