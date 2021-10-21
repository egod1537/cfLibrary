template<typename T, class = typename enable_if<is_integral<T>::value>::type>
struct RMMQSeg {
	int n;
	T inf;
	vector<T> minseg, maxseg;
	void Init(int _n, T _inf) {
		n = _n;
		inf = _inf;
		minseg.clear(); minseg.resize(4 * n, inf);
		maxseg.clear(); maxseg.resize(4 * n, -inf);
	}
	void update(int num, int s, int e, int idx, T diff) {
		if (idx < s || e < idx) return;
		if (s == e) { minseg[num] = maxseg[num] = diff; return; }
		int mid = s + e >> 1;
		update(2 * num, s, mid, idx, diff);
		update(2 * num + 1, mid + 1, e, idx, diff);
		minseg[num] = min(minseg[2 * num], minseg[2 * num + 1]);
		maxseg[num] = max(maxseg[2 * num], maxseg[2 * num + 1]);
	}
	void update(int idx, T diff) { update(1, 0, n - 1, idx, diff); }
	T minquery(int num, int s, int e, int l, int r) {
		if (r < s || e < l) return inf;
		if (l <= s && e <= r)return minseg[num];
		int mid = s + e >> 1;
		return min(minquery(2 * num, s, mid, l, r), minquery(2 * num + 1, mid + 1, e, l, r));
	}
	T minquery(int l, int r) { return minquery(1, 0, n - 1, l, r); }
	T maxquery(int num, int s, int e, int l, int r) {
		if (r < s || e < l) return -inf;
		if (l <= s && e <= r)return maxseg[num];
		int mid = s + e >> 1;
		return max(maxquery(2 * num, s, mid, l, r), maxquery(2 * num + 1, mid + 1, e, l, r));
	}
	T maxquery(int l, int r) { return maxquery(1, 0, n - 1, l, r); }
};