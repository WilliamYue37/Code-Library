int inDegree[MAXN]; queue<int> q;
void topologicalSort(vector<int> &ordering) { //returns topsort in vector "ordering"
	for (int u = 1; u <= N; ++u) if (inDegree[u] == 0) q.push(u);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		ordering.push_back(u);
		for (int v: adjList[u]) {
			--inDegree[v];
			if (inDegree[v] == 0) q.push(v);
		}
	}
}
