vector<int> primeFactorization(int n) {
	vector<int> ret;
	while (n % 2 == 0) {
		n /= 2; ret.push_back(2);
	}

	for (int i = 3; i * i <= n; i += 2) {
		while (n % i == 0) {
			n /= i; ret.push_back(i);
		}
	}

	if (n > 2) ret.push_back(n);

	return ret;
}
