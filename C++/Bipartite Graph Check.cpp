bool isBipartite = true;
int color[MAX_N];
void dfs(int u, int c) {
	color[u] = c;
	for (auto v: adjList[u]) {
		if (color[v] == 0) dfs(v, 3 - c);
		if (color[u] == color[v]) isBipartite = false;
	}
}
