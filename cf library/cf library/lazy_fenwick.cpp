struct LazyFenwick {
	int n;
	vector<ll> tree;
	void Init(int _n) {
		n = _n;
		tree.resize(n + 1);
	}
	void upt(int idx, ll diff) {
		idx++;
		for (;; idx += (idx & -idx)) tree[idx] += diff;
	}
	void update(int l, int r, ll diff) {
		upt(l, diff); upt(r + 1, -diff);
	}
	ll query(int idx) {
		ll ans = 0; idx++;
		for (; idx > 0; idx -= (idx & -idx)) ans += tree[idx];
		return ans;
	}
};