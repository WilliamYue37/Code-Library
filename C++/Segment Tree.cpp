struct SegmentTree {
    int N;
    vector<int> mini, delta;

    SegmentTree() {}
    SegmentTree(int N) {
        this->N = N;
        mini.resize(4 * N + 1);
        delta.resize(4 * N + 1);
        //you don't need to init unless default values are not zero
        //init(1, 0, this->N - 1);
    }

    void update(int l, int r, int val) {rec(1, 0, N - 1, l, r, val, 0);} //inclusive range

    int query(int l, int r) {return rec(1, 0, N - 1, l, r, 0, 1);} //inclusive range

    void init(int i, int lo, int hi) {
        //if default segtree values are not zero, initialize node i
        if (lo == hi) return;
          
        int m = (lo + hi) / 2;
        init(2 * i, lo, m);
        init(2 * i + 1, m + 1, hi);
    }

    void push(int i) {
        delta[2 * i] += delta[i];
        delta[2 * i + 1] += delta[i];
        delta[i] = 0;
    }

    void pull(int i) {
        mini[i] = min(mini[2 * i] + delta[2 * i], mini[2 * i + 1] + delta[2 * i + 1]);
    }

    int rec(int i, int lo, int hi, int l, int r, int val, int type) {
        if (r < lo || hi < l) return INF;
        if (l <= lo && hi <= r) {
            if (type == 0) delta[i] += val;
            return mini[i] + delta[i];
        }

        push(i);

        int m = (lo + hi) / 2;
        int minLeft = rec(2 * i, lo, m, l, r, val, type);
        int minRight = rec(2 * i + 1, m + 1, hi, l, r, val, type);

        pull(i);

        return min(minLeft, minRight);
    }
};
