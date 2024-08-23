namespace _{
    typedef long long ll;
    typedef pair<ll, ll> pi;
    #define x first
    #define y second
    ll ccw(pi a, pi b, pi c){
        return (b.x-a.x) * (c.y- a.y)- (c.x-a.x)*(b.y-a.y);
    }
    ll dst(pi a, pi b){
        ll dx = a.x-b.x, dy = a.y-b.y;
        return dx*dx+dy*dy;
    }
    vector<pi> convex_hull(vector<pi>& pt){
        swap(pt[0], *min_element(pt.begin(), pt.end()));
        sort(pt.begin()+1, pt.end(), [&](auto& a, auto& b) -> bool{
            ll cw = ccw(pt[0], a, b);
            if(cw != 0) return cw > 0;
            return dst(pt[0], a) < dst(pt[0], b);
        });
        vector<pi> hull;
        for(auto& p : pt){
            while(hull.size() > 1 && ccw(hull[hull.size() - 2], hull.back(), p) <= 0)
                hull.pop_back();
            hull.push_back(p);
        }
        return hull;
    }
}