template<typename T, class = typename enable_if<is_integral<T>::value>::type>
struct SumLazySeg {
	int n;
	vector<T> seg, lazy;
	void Init(int _n) {
		n = _n;
		seg.clear(); seg.resize(4 * n);
		lazy.clear(); lazy.resize(4 * n);
	}
	void updatelazy(int num, int s, int e) {
		seg[num] += (e - s + 1) * lazy[num];
		if (s != e) {
			lazy[2 * num] += lazy[num];
			lazy[2 * num + 1] += lazy[num];
		}
		lazy[num] = 0;
	}
	T update(int num, int s, int e, int l, int r, T diff) {
		updatelazy(num, s, e);
		if (r < s || e < l) return seg[num];
		if (l < s && e <= r) {
			lazy[num] += diff;
			updatelazy(num, s, e);
			return seg[num];
		}
		int mid = s + e >> 1;
		return seg[num] = update(2 * num, s, mid, l, r, diff) + update(2 * num + 1, mid + 1, e, l, r, diff);
	}
	void update(int l, int r, T diff) { update(1, 0, n - 1, l, r, diff); }
	T query(int num, int s, int e, int l, int r) {
		updatelazy(num, s, e);
		if (r < s || e < l) return 0;
		if (l < s && e <= r) return seg[num];
		int mid = s + e >> 1;
		return query(2 * num, s, mid, l, r) + query(2 * num + 1, mid + 1, e, l, r);
	}
	T query(int l, int r) { return query(1, 0, n - 1, l, r); }
};