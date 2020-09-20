struct BIT {
	int N;
	vector<int> bit;

	BIT() {}

	BIT(int N) {
		this->N = N;
		bit = vector<int>(N + 1);
	}

	int query(int index) {
		++index; int sum = 0;
		while (index > 0) {
			sum += bit[index];
			index -= index & -index;
		}
		return sum;
	}

	int query(int l, int r) {
		return query(r) - (l == 0 ? 0 : query(l - 1));
	}

	void update(int index, int val) {
		++index;
		while (index <= N) {
			bit[index] += val;
			index += index & -index;
		}	
	}
};
