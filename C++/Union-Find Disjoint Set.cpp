struct DSU {
	int numOfComponents;
	vector<int> parent, rank, size;

	DSU() {}

	DSU(int n) {
		parent.resize(n + 1); rank.resize(n + 1); size.resize(n + 1);
		numOfComponents = n;
		for (int i = 1; i <= n; ++i) {
			parent[i] = i;
			rank[i] = 0;
			size[i] = 1;
		}
	}

	int find(int a) {
		return parent[a] == a ? a : (parent[a] = find(parent[a]));
	}

	void unionSet(int a, int b) {
		a = find(a); b = find(b);
		if (rank[a] > rank[b]) {
			parent[b] = parent[a];
			size[a] += size[b];
		}
		else {
			parent[a] = parent[b];
			size[b] += size[a];
		}
		if (rank[a] == rank[b]) ++rank[b];
		--numOfComponents;
	}
};
