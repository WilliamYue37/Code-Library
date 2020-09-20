int kadane(vector<int> &a) {
	int maxEndingHere = 0, maxSoFar = 0;
	for (int i = 0; i < a.size(); ++i) {
		maxEndingHere = max(maxEndingHere + a[i], 0);
		maxSoFar = max(maxSoFar, maxEndingHere);
	}
	return maxSoFar;
}
