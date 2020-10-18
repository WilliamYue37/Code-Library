vector<int> dijkstra(int start) {
	vector<int> dist(N + 1, INF);
	priority_queue<pi, vector<pi>, greater<pi>> pq;
	pq.push({start, 0}); //u, dist
	dist[start] = 0;
	while (!pq.empty()) {
		int u = pq.top().ff, d = pq.top().ss; pq.pop();
		if (d > dist[u]) continue;
		for (auto edge : adj[u]) {
			int v = edge.ff, w = edge.ss;
			if (dist[u] + w < dist[v]) {
				pq.push({v, dist[u] + w});
				dist[v] = dist[u] + w;
			}
		}
	}
	return dist;
}
