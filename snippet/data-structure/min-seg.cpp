template<typename T, T e>
struct MinSeg {
    int n;
    vector<T> t;
    MinSeg() {}
    MinSeg(int _n) {init(_n);}
    MinSeg(const vector<T> vec) { init(vec); }
    void init(int _n) {
        n = _n;
        reset_v(t, 2*n,e);
    }
    void init(const vector<T>& vec) {
        init(vec.size());
        for (int i = n; i < 2 * n; i++)
            t[i] = vec[i-n];
        for (int i = n - 1; i >= 1; i--)
            t[i] = min(t[i << 1], t[i << 1 | 1]);
    }
    void add(int i, T x) {
        for (t[i += n] = x; i >>= 1;)
            t[i] = min(t[i << 1], t[i << 1 | 1]);
    }
    T get(int i) { return t[i += n]; }
    T qry(int l, int r) {
        T ret = e;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ret = min(ret, t[l++]);
            if (r & 1) ret = min(ret, t[--r]);
        }
        return ret;
    }
};