void FFT(vector<base>& f, base w) {
	int n = f.size();
	if (n == 1) return;

	int half = n >> 1;
	vector<base> even(half), odd(half);
	for (int i = 0; i < n; i++)
		(i % 2 ? odd : even)[i >> 1] = f[i];

	FFT(even, w * w); FFT(odd, w * w);

	base wp(1, 0);
	for (int i = 0; i < half; i++) {
		f[i] = even[i] + wp * odd[i];
		f[i + half] = even[i] - wp * odd[i];
		wp *= w;
	}
}

vector<base> FFTmultiply(vector<base>& a, vector<base>& b) {
	int n = 1;
	while (n < a.size() + 1 || n < b.size() + 1) n *= 2;
	n *= 2;
	a.resize(n); b.resize(n);
	vector<base> c(n);

	base w(cos(2 * PI / n), sin(2 * PI / n));
	FFT(a, w); FFT(b, w);

	for (int i = 0; i < n; i++) c[i] = a[i] * b[i];

	FFT(c, base(1, 0) / w);
	for (int i = 0; i < n; i++) {
		c[i] /= base(n, 0);
		c[i] = base(round(c[i].real()), round(c[i].imag()));
	}
	return c;
}