vector<int> precompute(string s) {
	vector<int> lps(s.size());
	int j = 0;
	for (int i = 1; i < s.size();) {
		if (s[i] == s[j]) lps[i] = ++j, ++i;
		else if (j != 0) j = lps[j - 1];
		else lps[i] = 0, ++i;
	}
	return lps;
}

bool KMP(string s, string p) { //s = text, p = pattern
	vector<int> lps = precompute(p);
	int i = 0, j = 0;
	while (i < s.size() && j < p.size()) {
		if (s[i] == p[j]) ++i, ++j;
		else if (j != 0) j = lps[j - 1];
		else ++i;
	}
	return j == p.size();
}
