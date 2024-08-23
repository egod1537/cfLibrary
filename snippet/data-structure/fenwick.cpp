struct Fenwick{
    int n;
    vector<ll> t;
    Fenwick(int n) {init(n);}
    Fenwick(const vector<ll>& vec){ init(vec);}
    void init(int _n){
        n = _n + 1;
        reset(t, n+1);
    }
    void init(const vector<ll>& vec){
        init(vec.size());
        for(int i=0 ;  i<  n; i++)
            add(i, vec[i]);
    }
    void add(int i, ll x){
        for(i++; i < n; i +=(i&-i)) t[i] += x;
    }
    ll qry(int l, int r){
        ll ret = 0;
        for(i++; i > 0; i -=(i&-i))
            ret += t[i];
        return ret;
    }
};