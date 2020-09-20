vector<ll> dijkstra(int start) {
	vector<ll> dist(N + 1, INF);
	priority_queue<pl, vector<pl>, greater<pl>> pq;
	pq.push({start, 0}); //u, dist
	dist[start] = 0;
	while (!pq.empty()) {
		ll u = pq.top().ff, d = pq.top().ss; pq.pop();
		if (d > dist[u]) continue;
		for (auto edge : adjList[u]) {
			ll v = edge.ff, w = edge.ss;
			if (dist[u] + w < dist[v]) {
				pq.push({v, dist[u] + w});
				dist[v] = dist[u] + w;
			}
		}
	}
	return dist;
}
