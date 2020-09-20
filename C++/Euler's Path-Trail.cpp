int degree[MAXN];
stack<int> path;

bool checkDegree() {
	int odd = 0, even = 0;
	for (int i = 1; i <= N; ++i) {
		if (degree[i] % 2 == 1) ++odd;
		else ++even;
	}
	return odd == 2 || odd == 0;
}

void eulerPath(int u) { //must start on an odd degree node if an odd degree node is present
	if (degree[u] == 0) {
		path.push(u);
		return;
	}

	while (degree[u]) {
		int v = 1;
		while (!adjMat[u][v]) ++v;
		--adjMat[u][v]; --adjMat[v][u]; --degree[u]; --degree[v];
		eulerPath(v);
	}

	path.push(u);
}
