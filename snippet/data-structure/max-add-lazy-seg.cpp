template<typename T, T e>
struct LazySeg{
    int n;
    vector<T> t, lz;
    LazySeg(int n){init(n);}
    LazySeg(const vector<T>& vec){init(vec);}
    void init(int _n){
        n = _n;
        reset_v(t, 4*n, e);
        reset(lz, 4*n);
    }
    void init(const vector<T>& vec){
        init(vec.size());
        for(int i=0; i < n; i++)
            upt(i, vec[i]);
    }
    void push(int num, ll s, ll e){
        t[num] += lz[num];
        if(s != e)
            for(int w : {2*num, 2*num+1})
                lz[w] += lz[num];
        lz[num] = 0;
    }
    T upt(int num, int s, int e, int l, int r, T x){
        push(num, s, e);
        if(r < s || e < l) return t[num];
        if(l <= s && e <= r){
            lz[num] += x;
            push(num, s, e);
            return t[num];
        }
        int mid = s+e>>1;
        return t[num] = max(upt(2*num, s, mid, l, r, x), upt(2*num+1, mid+1, e, l, r, x));
    }
    void upt(int l, int r, T x){upt(1, 0, n-1, l, r, x);}
    T qry(int num, int s, int e, int l, int r){
        pusu(num, s, e);
        if(r < s || e < l) return e;
        if(l <= s && e <=r) return t[num];
        int mid = s+e>>1;
        return max(qry(2*num, s, mid, l, r), qry(2*num+1, mid+1, e, l, r, x));
    }
    T qry(int l, int r){return qry(1, 0, n-1, l, r);}
};