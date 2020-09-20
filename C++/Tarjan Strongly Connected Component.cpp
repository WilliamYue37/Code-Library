int counter = 0, numOfSCC = 0;
vector<int> pre(MAX_N, -1), low(MAX_N, -1), id(MAX_N, -1), stk;
void DFSLowLink(int u) {
	pre[u] = low[u] = counter++;
	stk.push_back(u);
	for (int v: adj[u]) {
		if (pre[v] == -1) DFSLowLink(v);
		low[u] = min(low[u], low[v]);
	}
	if (low[u] == pre[u]) {
		while (true) {
			int j = stk.back(); stk.pop_back();
			id[j] = numOfSCC;
			low[j] = N + 1;
			if (u == j) break;
		}
		++numOfSCC;
	}
}
