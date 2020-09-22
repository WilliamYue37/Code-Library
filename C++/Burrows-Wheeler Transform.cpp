struct SuffixArray {
	int N;
	string T;
	vector<int> RA, tempRA;
	vector<int> SA, tempSA;
	vector<int> c; // used for radix sort
	vector<int> owner; // for generalized suffix arrays - stores the owner of the first string in suffix_i; owner of special characters is -1; !NOTE! - has to be computed in main method when inputing strings
	vector<int> Phi, PLCP, LCP; // Phi stores previous suffix

	SuffixArray() {}
	SuffixArray(string T) {
		N = sz(T);
		this->T = T;
		RA.resize(N + 1); tempRA.resize(N + 1);
		SA.resize(N + 1); tempSA.resize(N + 1);
		c.resize(max(300, N + 1));
		Phi.resize(N + 1); PLCP.resize(N + 1); LCP.resize(N + 1);
		constructSA();
		computeLCP();
	}

	void countingSort(int k) {
		int sum, maxi = max(300, N); // up to 255 ASCII chars or length of string
		fill(c.begin(), c.end(), 0);
		for (int i = 0; i < N; ++i) {
			++c[i + k < N ? RA[i + k] : 0];
		}
		for (int i = sum = 0; i < maxi; ++i) {
			int t = c[i]; c[i] = sum; sum += t;
		}
		for (int i = 0; i < N; ++i) {
			tempSA[c[SA[i] + k < N ? RA[SA[i] + k] : 0]++] = SA[i];
		}
		for (int i = 0; i < N; ++i) {
			SA[i] = tempSA[i];
		}
	}

	void constructSA() {
		int r;
		for (int i = 0; i < N; ++i) RA[i] = T[i];
		for (int i = 0; i < N; ++i) SA[i] = i;
		for (int k = 1; k < N; k <<= 1) {
			countingSort(k);
			countingSort(0);
			tempRA[SA[0]] = r = 0;
			for (int i = 1; i < N; ++i) {
				tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i - 1]] && RA[SA[i] + k] == RA[SA[i - 1] + k]) ? r : ++r;
			}
			for (int i = 0; i < N; ++i) {
				RA[i] = tempRA[i];
			}
			if (RA[SA[N - 1]] == N - 1) break;
		}
	}

	void computeLCP() {
		int L;
		Phi[SA[0]] = -1;
		for (int i = 1; i < N; ++i) {
			Phi[SA[i]] = SA[i - 1];
		}
		for (int i = L = 0; i < N; ++i) {
			if (Phi[i] == -1) {PLCP[i] = 0; continue;}
			while (T[i + L] == T[Phi[i] + L]) ++L;
			PLCP[i] = L;
			L = max(L - 1, 0);
		}
		for (int i = 0; i < N; ++i) {
			LCP[i] = PLCP[SA[i]];
		}
	}

	pi stringMatching(string P) {
		int lo = 0, hi = N - 1, mid = lo;
		while (lo < hi) {
			mid = (lo + hi) / 2;
			int res = T.compare(SA[mid], N - SA[mid], P);
			if (res >= 0) hi = mid;
			else lo = mid + 1;
		}
		if (T.compare(SA[lo], N - SA[lo], P) != 0) return {-1, -1};
		pi ans; ans.ff = lo;
		lo = 0; hi = N - 1; mid = lo;
		while (lo < hi) {
			mid = (lo + hi) / 2;
			int res = T.compare(SA[mid], N - SA[mid], P);
			if (res > 0) hi = mid;
			else lo = mid + 1;
		}
		if (T.compare(SA[hi], N - SA[hi], P) != 0) --hi;
		ans.ss = hi;
		return ans;
	}

	pi LRS() {
		int idx = 0, maxLCP = -1;
		for (int i = 1; i < N; ++i) {
			if (LCP[i] > maxLCP) {
				maxLCP = LCP[i], idx = i;
			}
		}
		return {maxLCP, idx};
	}

	pi LCS() {
		int idx = 0, maxLCP = -1;
		for (int i = 1; i < N; ++i) {
			if (owner[SA[i]] != owner[SA[i - 1]] && LCP[i] > maxLCP) {
				maxLCP = LCP[i], idx = i;
			}
		}
		return {maxLCP, idx};
	}
};

string BWT(string T) {
	SuffixArray sa(T);
	string res;
	for (int i = 0; i < sz(T); ++i) {
		res += sa.SA[i] == 0 ? '$' : T[sa.SA[i] - 1];
	}
	return res;
}

string reverseBWT(string T) {
	vector<int> pre1(sz(T)), pre2(26);
	for (int i = 0; i < sz(T); ++i) {
		if (T[i] != '$') pre1[i] = pre2[T[i] - 'a']++;
	}
	for (int i = 1; i < 26; ++i) pre2[i] += pre2[i - 1];
	string res = "$";
	int row = 0;
	while (T[row] != '$') {
		res = T[row] + res;
		row = (T[row] == 'a' ? 0 : pre2[T[row] - 'a' - 1]) + pre1[row] + 1;
	}
	return res;
}
