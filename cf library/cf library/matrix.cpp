template<typename T>
struct Matrix {
	vector<vector<T>> mat;
	int w, h;
	Matrix() {}
	Matrix(int _w, int _h) { w = _w, h = _h, mat.resize(w, vector<T>(h)); }
	Matrix(int _w, int _h, T t) { w = _w, h = _h, mat.resize(w, vector<T>(h, t)); }

	vector<T>& operator[](unsigned int idx) { return mat[idx]; }

	Matrix<T> Reverse() {
		int n = min(w, h);
		Matrix<T> arr(n, 2 * n); arr.mat.assign(mat.begin(), mat.end());
		for (int i = 0; i < n; i++) arr[i].resize(2 * n);
		for (int i = 0; i < n; i++) {
			for (int j = n; j < 2 * n; j++)
				if (i == j - n) arr[i][j] = 1;
		}
		for (int i = 0; i < n; i++) {
			T t = arr[i][i];
			for (int j = i; j < 2 * n; j++) arr[i][j] /= t;
			for (int j = 0; j < n; j++)
			{
				if (i != j)
				{
					t = arr[j][i];
					for (int k = 0; k < 2 * n; k++)
						arr[j][k] -= t * arr[i][k];
				}
			}
		}
		Matrix<T> ans(n, n);
		for (int i = 0; i < n; i++) for (int j = n; j < 2 * n; j++)
			ans[i][j - n] = arr[i][j];
		return ans;
	}
};
template<typename T>
Matrix<T> matmultiply(Matrix<T> a, Matrix<T> b) {
	Matrix<T> ans(a.w, b.h);

	for (int i = 0; i < a.w; i++) {
		for (int j = 0; j < b.h; j++) {
			T& ret = ans[i][j];
			for (int k = 0; k < b.w; k++)
				ret += a[i][k] * b[k][j];
		}
	}
	return ans;
}
Matrix<ll> matmultiply(Matrix<ll> a, Matrix<ll> b, ll mod = 0) {
	Matrix<ll> ans(a.w, b.h);

	for (int i = 0; i < a.w; i++) {
		for (int j = 0; j < b.h; j++) {
			ll& ret = ans[i][j];
			for (int k = 0; k < b.w; k++) {
				ret += a[i][k] * b[k][j];
				if (mod) ret = ret % mod;
			}
		}
	}
	return ans;
}
Matrix<int> matmultiply(Matrix<int> a, Matrix<int> b, ll mod = 0) {
	Matrix<int> ans(a.w, b.h);

	for (int i = 0; i < a.w; i++) {
		for (int j = 0; j < b.h; j++) {
			int& ret = ans[i][j];
			for (int k = 0; k < b.w; k++) {
				ret += a[i][k] * b[k][j];
				if (mod) ret = ret % mod;
			}
		}
	}
	return ans;
}
Matrix<ll> llmatOne(int w, int h) { return Matrix<ll>(w, h, 1); }
Matrix<ld> ldmatOne(int w, int h) { return Matrix<ld>(w, h, 1.0); }
template<typename T>
Matrix<T> operator+(Matrix<T> a, Matrix<T> b) {
	assert(a.w == b.w && a.h == b.h);
	Matrix<T> ans(a.w, a.h);
	for (int i = 0; i < a.w; i++) for (int j = 0; j < a.h; j++)
		ans[i][j] = a[i][j] + b[i][j];
	return ans;
}
template<typename T>
Matrix<T> operator-(Matrix<T> a, Matrix<T> b) {
	assert(a.w == b.w && a.h == b.h);
	Matrix<T> ans(a.w, a.h);
	for (int i = 0; i < a.w; i++) for (int j = 0; j < a.h; j++)
		ans[i][j] = a[i][j] - b[i][j];
	return ans;
}
template<typename T>
Matrix<T> operator*(Matrix<T> a, Matrix<T> b) {
	return matmultiply(a, b);
}
template<typename T>
Matrix<T> operator%(Matrix<T> a, ll b) {
	for (int i = 0; i < a.w; i++)
		for (int j = 0; j < a.h; j++)
			a[i][j] %= b;
	return a;
}
template<typename T>
Matrix<T> operator%(ll b, Matrix<T> a) {
	return a % b;
}

template<typename T>
ostream& operator<<(ostream& os, Matrix<T> mat) {
	for (int i = 0; i < mat.w; i++) {
		for (int j = 0; j < mat.h; j++)
			os << mat[i][j] << " ";
		os << "\n";
	}
	return os;
}

Matrix<ll> mypow(Matrix<ll> x, ll cnt, ll mod = 0) {
	if (!cnt) return llmatOne(x.w, x.h);
	if (cnt == 1) return x;
	Matrix<ll> mid = mypow(x, cnt / 2, mod);
	Matrix<ll> ans = matmultiply(mid, mid, mod);
	if (cnt % 2) { ans = matmultiply(x, ans, mod); }
	return ans;
}