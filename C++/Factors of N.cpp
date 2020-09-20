vector<int> factors(int n) {
	vector<int> ret;
	for (int j = 1; j * j <= n; ++j) {
		if (n % j == 0) {
			ret.push_back(j);
			if (n / j != j) ret.push_back(n / j);
		}
	}
	return ret;
}
