struct SegmentTree {
    int N;
    vector<int> sum;

    SegmentTree() {}
    SegmentTree(int N) {
        this->N = 1;
        while (this->N < N) this->N <<= 1;
        sum.resize(2 * this->N + 1);
    }

    void update(int l, int r, int val) {rec(1, 0, N - 1, l, r, val, 0);} //inclusive range

    int query(int l, int r) {return rec(1, 0, N - 1, l, r, 0, 1);} //inclusive range

    void pull(int i) {
        sum[i] = sum[2 * i] + sum[2 * i + 1];
    }

    int rec(int i, int lo, int hi, int l, int r, int val, int type) {
        if (r < lo || hi < l) return 0;
        if (l <= lo && hi <= r) {
            if (type == 0) sum[i] = val;
            return sum[i];
        }

        int m = (lo + hi) / 2;
        int sumLeft = rec(2 * i, lo, m, l, r, val, type);
        int sumRight = rec(2 * i + 1, m + 1, hi, l, r, val, type);

        pull(i);

        return sumLeft + sumRight;
    }
};

struct SegmentTree2D {
    int N, M;
    vector<SegmentTree> tree;

    SegmentTree2D() {}
    SegmentTree2D(int N, int M) {
        this->N = 1; this->M = 1;
        while (this->N < N) this->N <<= 1;
        while (this->M < M) this->M <<= 1;
        tree.resize(2 * this->N + 1);
        init(1, 0, this->N - 1);
    }

    void init(int i, int lo, int hi) {
        tree[i] = SegmentTree(this->M);

        if (lo == hi) return;
          
        int m = (lo + hi) / 2;
        init(2 * i, lo, m);
        init(2 * i + 1, m + 1, hi);
    }

    void update(int x, int y, int val) {update(1, 0, N - 1, x, y, val);} //inclusive range

    int query(int x1, int x2, int y1, int y2) {return query(1, 0, N - 1, x1, x2, y1, y2);} //inclusive range

    void pull(int i, int y) {
        for (int j = 0; j < M; ++j) {
        	tree[j].update(y, y, tree[2 * j].query(y, y) + tree[2 * j + 1].query(y, y));
        }
    }

    void update(int i, int lo, int hi, int x, int y, int val) {
    	if (x == lo && x == hi) {
    	    tree[i].update(y, y, val);
    	    return;
    	}

    	int m = (lo + hi) / 2;
    	if (x <= m) update(2 * i, lo, m, x, y, val);
    	else update(2 * i + 1, m + 1, hi, x, y, val);

    	pull(i, y);
    }

    int query(int i, int lo, int hi, int x1, int x2, int y1, int y2) {
    	if (x2 < lo || hi < x1) return 0;
    	if (x1 <= lo && hi <= x2) return tree[i].query(y1, y2);

    	int m = (lo + hi) / 2;
    	return query(2 * i, lo, m, x1, x2, y1, y2) + query(2 * i + 1, m + 1, hi, x1, x2, y1, y2);
    }
};
