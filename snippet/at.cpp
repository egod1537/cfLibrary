// https://github.com/egod1537/cfLibrary

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt")
#include <bits/stdc++.h>
#include <unordered_map>
#include <random>
#include <cassert>
using namespace std;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define rev(x) {reverse(all(x));}
#define compress(x) {sort(all(x)); x.erase(unique(all(x)), x.end()); x.shrink_to_fit();}
#define sz(x) ((int)x.size())
#define MIN(x) *min_element(all(x))
#define MAX(x) *max_element(all(x))
#define LB(x) distance((c).begin(), lower_bound(all(c), (x)))
#define UB(x) distance((c).begin(), upper_bound(all(c), (x)))
#define cmpsort(x, y) sort(all(x), [&](auto& a, auto &b) -> bool{y});
#define sq(x) ((x) * (x))
#define pceil(x, y) ((x) / (y) + ((x) % (y) > 0))
#define debug(x) cout << (#x) << " " << x << "\n";
#define setprecision(x) {(cout << fixed).precision(x);}
#define stk_clear(x){while(x.size()) x.pop();}
#define que_clear(x){while(x.size()) x.pop();}
#define reset(x, n) {x.clear(); x.resize(n);}
#define reset_v(x, n, y) {x.clear(); x.resize(n, y);}
#define fi first
#define se second
#define x first
#define y second
typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<ll, ll> pi;
typedef pair<double, double> pd;
typedef pair<ld, ld> pld;
typedef complex<double> base;
const double PI = 3.14159265358979323846;
template<typename T>
pair<T, T> operator+(const pair<T, T> a, const pair<T, T> b) { return pair<T, T>(a.fi + b.fi, a.se + b.se); }
template<typename T>
pair<T, T> operator-(const pair<T, T> a, const pair<T, T> b) { return pair<T, T>(a.fi - b.fi, a.se - b.se); }
template<typename T>
pair<T, T> operator*(const pair<T, T> a, ll b) { return pair<T, T>(a.fi * b, a.se * b); }
template<typename T>
pair<T, T> operator*(ll b, const pair<T, T> a) { return pair<T, T>(a.fi * b, a.se * b); }
template<typename T>
pair<T, T> operator*(const pair<T, T> a, double b) { return pair<T, T>(a.fi * b, a.se * b); }
template<typename T>
pair<T, T> operator*(double b, const pair<T, T> a) { return pair<T, T>(a.fi * b, a.se * b); }
template<typename T>
ostream& operator<<(ostream& os, pair<T, T> p) {
    os << "(" << p.fi << ", " << p.second << ")";
    return os;
}
template<typename T>
ostream& operator<<(ostream& os, vector<T> vec) {
    for (T w : vec) os << w << " ";
    return os;
}
template<typename T>
ostream& operator<<(ostream& os, list<T> lt) {
    for (T w : lt) os << w << " ";
    return os;
}
template<typename T>
ostream& operator<<(ostream& os, stack<T> stk) {
    stack<T> t;
    while (stk.size()) t.push(stk.top()), stk.pop();
    while (t.size()) os << t.top() << " ", t.pop();
    return os;
}
template<typename T>
ostream& operator<<(ostream& os, queue<T> que) {
    while (que.size()) os << que.front() << " ", que.pop();
    return os;
}
template<typename T>
ostream& operator<<(ostream& os, deque<T> dq) {
    for (T w : dq) os << w << " ";
    return os;
}
int dx4[4] = { 1, 0, -1, 0 };
int dy4[4] = { 0, 1, 0, -1 };
int dx8[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy8[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dir2num(char c) {
    if (c == 'D') return 0;
    else if (c == 'R') return 1;
    else if (c == 'U') return 2;
    else return 3;
}
char num2dir(int i) { return "DRUL"[i]; }
template<typename T>
T SUM(const vector<T>& vec) {
    T ret = 0;
    for (auto&& x : vec) ret += x;
    return ret;
}
template<typename T>
vector<int> argsort(const vector<T>& vec) {
    vector<int> ret(sz(vec));
    iota(all(ret), 0);
    cmpsort(ret, return vec[a] == vec[b] ? a < b : vec[a] < vec[b];);
    return ret;
}
template<typename T>
istream& operator>>(istream& is, vector<T>& vec){
    for(auto& s : vec) is >> s;
    return is; 
}
template<typename T>
istream& operator>>(istream& is, pair<T, T>& p){
    return is >> p.first >> p.second;
}
ll dst(pi a, pi b){
    ll dx = a.x-b.x, dy = a.y-b.y;
    return dx*dx+dy*dy;
}
ll ccw(pi a, pi b, pi c){
    return (b.x-a.x)*(c.y - a.y)-(c.x-a.x)*(b.y-a.y);
}
template<typename T>
vector<T> filter(vector<T> vec, function<bool(T)> pred){
    vector<T> ret;
    copy_if(all(vec), back_inserter(ret), pred);
    return ret;
}
template<typename T1, typename T2>
vector<T2> trans(vector<T1> vec, function<T2(T1)> func){
    vector<T2> ret(vec.size());
    transform(all(vec), ret.begin(), func);
    return ret;
}
void solve() {

}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int tc = 1;
    for (int i = 1; i <= tc; i++) solve();
    return 0;
}