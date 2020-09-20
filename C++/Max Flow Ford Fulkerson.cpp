int N, source, sink;
int adj[MAX_N][MAX_N];
bool seen[MAX_N];

int dfs(int u, int amount) {
	if (u == sink) return amount;
	seen[u] = true;
	for (int v = 1; v <= N; ++v) {
		if (adj[u][v] > 0 && !seen[v]) {
			int sent = dfs(v, min(amount, adj[u][v]));
			if (sent > 0) {
				adj[u][v] -= sent;
				adj[v][u] += sent;
				return sent;
			}
		}
	}

	return 0;
}

int run() {
	int total = 0;
	int sent = -1;

	while (sent != 0) {
		fill(seen, seen + N, false);
		sent = dfs(source, (1 << 30));
		total += sent;
	}

	return total;
}
