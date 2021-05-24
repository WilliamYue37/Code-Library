struct SparseTable {
	static const int B = 30;
	int N, blocks;
	vector<int> v, mask;
	vector<vector<int>> table;

	SparseTable(vector<int> _v) {
		this->v = _v;
		this->N = (int)v.size();
		blocks = N / B;
		mask = vector<int>(N);	
		table = vector<vector<int>>(blocks, vector<int>(msb(blocks) + 1));

		int cur = 0; // sliding mask
		for (int i = 0; i < N; ++i) {
			cur = (cur << 1) & ((1 << B) - 1);
			while (cur > 0 && min(v[i], v[i - msb(lsb(cur))]) == v[i]) cur ^= lsb(cur); 
			cur |= 1;
			mask[i] = cur;
		}

		for (int i = 0; i < blocks; ++i) table[i][0] = mini_query(B * i + B - 1);
		for (int j = 1; (1 << j) <= blocks; ++j) {
			for (int i = 0; i + (1 << j) - 1 < blocks; ++i) {
				table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
			}
		}
	}

	// least significant set bit
	int lsb(int num) {return num & -num;}

	// index of most significant set bit
	int msb(int num) {return __builtin_clz(1) - __builtin_clz(num);}

	int mini_query(int r, int len = B) {
		return v[r - msb(mask[r] & ((1 << len) - 1))];
	}

	int query(int l, int r) {
		if (r - l + 1 <= B) return mini_query(r, r - l + 1);
		int ret = min(mini_query(l + B - 1), mini_query(r));
		int blockL = l / B + 1, blockR = r / B - 1;
		if (blockL <= blockR) {
			int j = msb(blockR - blockL + 1);
			ret = min({ret, table[blockL][j], table[blockR - (1 << j) + 1][j]});
		}
		return ret;
	}
};
