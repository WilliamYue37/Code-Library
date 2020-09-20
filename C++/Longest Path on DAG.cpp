//must do a topological sort before running longest path
fill(dist, dist + MAXN, -1);
dist[1] = 0;
for (int u = 1; u <= N; ++u) {
	if (dist[u] != -1) {
		for (int i = 0; i < adjList[u].size(); ++i) {
			pair<int, int> v = adjList[u][i];
			dist[v.first] = max(dist[v.first], dist[u] + v.second);
		}
	}
}
