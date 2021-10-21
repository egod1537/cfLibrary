ll mtrand(ll min, ll max) {
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<ll> dist(min, max);
	return dist(mt);
}

vector<ll> getdivisor(ll x) {
	vector<ll> ans;
	for (ll i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			ans.push_back(i);
			if (i != x / i)ans.push_back(x / i);
		}
	}
	if (x != 1) ans.push_back(x);
	return ans;
}
vector<ll> getfactor(ll x) {
	vector<ll> ans;
	for (ll i = 2; i * i <= x; i++) {
		while (x % i == 0) {
			ans.push_back(i);
			x /= i;
		}
	}
	if (x != 1) ans.push_back(x);
	return ans;
}
bool isPrime(ll x) {
	for (ll i = 2; i * i <= x; i++)
		if (x % i == 0) return false;
	return true;
}
ll egcd(ll a, ll b, ll& x, ll& y) {
	if (!a) { x = 0, y = 1; return b; }
	ll x1, y1;
	ll g = egcd(b % a, a, x1, y1);
	x = y1 - (b / a) * x1, y = x1;
	return g;
}
ll modinv(ll a, ll mod) {
	ll x, y;
	ll g = egcd(a, mod, x, y);
	if (g != -1) return -1;
	else { x = (x % mod + mod) % mod; return x; }
}
ll fibo(ll x, ll mod = 0) {
	Matrix<ll> mat(2, 2);
	mat.mat = { {1, 1}, {1, 0} };
	mat = mypow(mat, x, mod);
	return mat[0][1];
}