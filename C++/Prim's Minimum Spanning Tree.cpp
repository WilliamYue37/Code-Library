int dist[MAX_N];
bool used[MAX_N];

int MST() {
	fill(dist, dist + N + 1, INF); dist[1] = 0;
	int ans = 0;
	for (int i = 1; i <= N; ++i) {
		int mini = -1;
		for (int j = 1; j <= N; ++j) {
			if (!used[j] && (mini == -1 || dist[j] < dist[mini])) mini = j;
		}
		ans += dist[mini];
		used[mini] = true;
		for (int j = 1; j <= N; ++j) dist[j] = min(dist[j], adjMat[mini][j]);
	}
	return ans;
}
