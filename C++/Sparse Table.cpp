struct SparseTable {
	int N;
	vector<vector<int>> table;

	SparseTable(vector<int> v) : SparseTable((int)v.size()) {
		for (int i = 0; i < N; ++i) table[i][0] = v[i];
		init();
	}

	SparseTable(int _N) {
		this->N = _N;
		table = vector<vector<int>>(N, vector<int>(msb(N) + 1));
	}
	
	void init() {
		for (int j = 1; (1 << j) <= N; ++j) {
			for (int i = 0; (i + (1 << j) - 1) < N; ++i) {
				table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
			}
		}
	}

	int query(int l, int r) { //inclusive range
		int j = msb(r - l + 1);
		return min(table[l][j], table[r - (1 << j) + 1][j]);
	}

	// index of most significant set bit; equivalent to (int)log(num)
	int msb(int num) {return __builtin_clz(1) - __builtin_clz(num);}
};