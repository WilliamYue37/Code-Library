int cnt = 0;
map<vector<int>, int> stateid;
map<int, vector<int>> stateis;
vector<int> a;

bool ok() {
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			for (int k = j + 1; k < N; ++k) {
				for (int l = k + 1; l < N; ++l) {
					if (a[i] == a[k] && a[j] == a[l] && a[i] != a[j]) return false;
				}
			}
		}
	}
	return true;
}

void dfs(int x, int y) {
	if (x == N) {
		if (ok()) {
			stateid[a] = cnt;
			stateis[cnt] = a;
			++cnt;
		}
	}
	else {
		for (int i = 0; i <= y; ++i) {
			a[x] = i;
			dfs(x + 1, max(i + 1, y));
		}
	}
}

// initiate by running dfs(0, 0) in main method;
