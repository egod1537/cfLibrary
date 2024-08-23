template<typename T>
struct StaticMax {
    int n, lv;
    vector<vector<T>> t;
    vector<int> pw;
    StaticMax(){}
    StaticMax(const vector<T>& vec) { init(vec); }
    void init(const vector<T>& vec) {
        lv = 0; n = vec.size();
        while ((1 << lv) < n) lv++;
        lv++;
        reset(t, lv); reset(pw, n+1);
        for (int i = 0; i < lv; i++)
            for (int j = (1 << i); j < (1 << (i + 1)); j++)
                if(j <= n) pw[j] = i;
        for (int i = 0; i < lv; i++) t[i].resize(n);
        for (int i = 0; i < n; i++) t[0][i] = vec[i];

        for (int i = 1; i < lv; i++)
            for (int j = 0; j < n; j++)
                t[i][j] = max(t[i - 1][j], t[i - 1][min(n-1, j + (1 << (i-1)))]);
    }
    T qry(int l, int r) {
        int d = pw[r - l + 1];
        return max(t[d][l], t[d][r-(1 << d)+1]);
    }
};