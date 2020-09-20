int degree[MAXN];
stack<int> tour;

bool checkDegree() {
	for (int i = 1; i <= N; ++i) if (degree[i] % 2 == 1) return false;
	return true;
}

void eulerTour(int u) {
	if (degree[u] == 0) {
		tour.push(u);
		return;
	}

	while (degree[u]) {
		int v = 1;
		while (!adjMat[u][v]) ++v;
		--adjMat[u][v]; --adjMat[v][u]; --degree[u]; --degree[v];
		eulerTour(v);
	}

	tour.push(u);
}
