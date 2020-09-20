int counter = 0, numOfSCC = 0;
int pre[MAX_N], low[MAX_N], id[MAX_N];
vector<int> stk;

int start = 1;
bool blocked[MAX_N];
vector<int> blockMap[MAX_N];
vector<vector<int>> cycles;

void DFSLowLink(int u) {
	pre[u] = low[u] = counter++;
	stk.push_back(u);
	for (int v: adj[u]) {
		if (v < start) continue; // simulate removing nodes
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

void unblock(int u) {
	blocked[u] = false;
	for (int v: blockMap[u]) {
		if (v < start || id[u] != id[v]) continue; // check if node has been removed and if it's in the same SCC
		if (blocked[v]) unblock(v);
	}
	blockMap[u].clear();
}

bool dfs(int u) {
	bool foundCycle = false;
	stk.push_back(u);
	blocked[u] = true;

	for (int v: adj[u]) {
		if (v < start || id[u] != id[v]) continue; 
		if (v == start) {
			vector<int> cycle = stk;
			cycle.push_back(start);
			cycles.push_back(cycle);
			foundCycle = true;
		}
		else if (!blocked[v]) foundCycle |= dfs(v);
	}

	if (foundCycle) unblock(u);
	else {
		for (int v: adj[u]) {
			if (v < start || id[u] != id[v]) continue;
			blockMap[v].push_back(u);
		}
	}

	stk.pop_back();
	return foundCycle;
}

void nextStart() {
	vector<int> SCCsize(numOfSCC);
	for (int i = start; i <= N; ++i) ++SCCsize[id[i]];
	while (start <= N && SCCsize[id[start]] == 1) ++start; 
}

// Time - O((E + V) * (c + 1)) where c is the number of cycles
// Space - O(E + V)
// run this method to initiate Johnson's Cycle finding Algorithm
void findCycles() {
	while (start <= N) {
		counter = 0, numOfSCC = 0;
		memset(pre, -1, sizeof pre);
		memset(low, -1, sizeof low);
		memset(id, -1, sizeof id);
		stk.clear();
		for (int i = start; i <= N; ++i) {
			if (pre[i] == -1) DFSLowLink(i);
		}
		nextStart(); // don't run the algorithm on SCCs with size 1
		if (start > N) break; // no SCC with a sz > 1

		stk.clear();
		memset(blocked, false, sizeof blocked);
		for (int i = 1; i <= N; ++i) blockMap[i].clear();
		dfs(start);
		++start;
	}
}
