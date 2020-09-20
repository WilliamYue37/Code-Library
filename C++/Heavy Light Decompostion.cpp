class HeavyLight {
public:
	int parent[MAXN], heavy[MAXN], depth[MAXN], root[MAXN], treePos[MAXN];
	SegmentTree segtree;

	HeavyLight() {
		fill(heavy, heavy + MAXN, -1);
		parent[0] = -1, depth[0] = 0;
		DFS(0);
		for (int i = 0, currentPos = 0; i < N; ++i) {
			if (parent[i] == -1 || heavy[parent[i]] != i) {
				for (int j = i; j != -1; j = heavy[j]) {
					root[j] = i;
					treePos[j] = currentPos++;
				}
			}
		}
	}

	int DFS(int u) {
		int size = 1, maxSubtree = 0;
		for (int v: adjList[u]) if(v != parent[u]) {
			parent[v] = u;
			depth[v] = depth[u] + 1;
			int subtree = DFS(v);
			if (subtree > maxSubtree) {
				heavy[u] = v;
				maxSubtree = subtree;
			}
			size += subtree;
		}
		return size;
	}

	template <typename BinaryOperation>
	void processPath(int u, int v, BinaryOperation op) {
		for (; root[u] != root[v]; v = parent[root[v]]) {
			if (depth[root[u]] > depth[root[v]]) swap(u, v);
			op(treePos[root[v]], treePos[v]);
		}
		if (depth[u] > depth[v]) swap(u, v);
		op(treePos[u] + 1, treePos[v]);
	}

	void modifyPath(int u, int v, int value) {
		processPath(u, v, [this, &value](int l, int r) {segtree.update(l, r, value);});
	}

	int queryPath(int u, int v) {
		int res = 0;
		processPath(u, v, [this, &res](int l, int r) {res += segtree.query(l, r);});
		return res;
	}
};
