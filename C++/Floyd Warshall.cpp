for (int k = 1; k <= N; ++k) {
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
		}
	}
}
