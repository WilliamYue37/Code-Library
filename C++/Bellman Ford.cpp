pair<int, bool> bellmanFord() {
	bool hasNegativeCycle = false;
	vector<int> dist(N + 1, INF);
	dist[1] = 0;
	for (int i = 0; i < N - 1; ++i) {
		for (int u = 1; u <= N; ++u) {
			for (int j = 0; j < sz(adj[u]); ++j) {
				pi v = adj[u][j];
				dist[v.ff] = min(dist[v.ff], dist[u] + v.ss);
			}
		}
	}

	for (int u = 1; u <= N; ++u) {
		for (int j = 0; j < sz(adj[u]); ++j) {
			pi v = adj[u][j];
			if (dist[v.ff] > dist[u] + v.ss) {
				hasNegativeCycle = true;
			}
		}
	}

	return {dist[N], hasNegativeCycle};
}