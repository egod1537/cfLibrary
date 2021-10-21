template<typename T, class = typename enable_if<is_integral<T>::value>::type>
struct SumSeg {
	int n;
	vector<T> seg;
	void Init(int _n) {
		n = _n;
		seg.clear(); seg.resize(4 * n);
	}
	T update(int num, int s, int e, int idx, T diff) {
		if (idx < s || e < idx) return seg[num];
		if (s == e) return seg[num] = diff;
		int mid = s + e >> 1;
		return seg[num] = update(2 * num, s, mid, idx, diff) + update(2 * num + 1, mid + 1, e, idx, diff);
	}
	void update(int idx, T diff) { update(1, 0, n - 1, idx, diff); }
	void addupdate(int idx, T diff) { update(idx, query(idx, idx) + diff); }

	T query(int num, int s, int e, int l, int r) {
		if (r < s || e < l) return 0;
		if (l <= s && e <= r) return seg[num];
		int mid = s + e >> 1;
		return query(2 * num, s, mid, l, r) + query(2 * num + 1, mid + 1, e, l, r);
	}
	T query(int l, int r) { return query(1, 0, n - 1, l, r); }
};