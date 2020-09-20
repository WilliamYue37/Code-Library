void rec(int l, int r, int optl, int optr) {
	if (l > r) return;
	int m = (l + r) / 2;
	pi ans = {INF, -1};
	for (int i = optl; i <= min(m - 1, optr); ++i) {
		ans = min(ans, {dp[k - 1][i] + getCost(i + 1, m), i});
	}
	dp[k][m] = ans.ff;
	rec(l, m - 1, optl, ans.ss);
	rec(m + 1, r, ans.ss, optr);
}
