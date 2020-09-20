int block(int i) {return i/(int)sqrt(MAX_N);}

struct Query {
    int idx, l, r;

    bool operator < (const Query& q) const {
        if (block(this->l) == block(q.l)) return this->r < q.r;
        return block(this->l) < block(q.l);
    }
};

int N, Q;
int total;
int arr[MAX_N], cnt[MAX_N], ans[MAX_Q];
Query queries[MAX_Q];

void add(int pos) {
    ++cnt[arr[pos]];
    if (cnt[arr[pos]] == 1) ++total;
}

void remove(int pos) {
    --cnt[arr[pos]];
    if (cnt[arr[pos]] == 0) --total;
}

void solve() {
    sort(queries, queries + Q);

    int currL = 0, currR = -1;
    for (int i = 0; i < Q; ++i) {
        int l = queries[i].l, r = queries[i].r;
        while (currL < l) remove(currL++);
        while (currL > l) add(--currL);
        while (currR < r) add(++currR);
        while (currR > r) remove(currR--);
        ans[queries[i].idx] = total;
    }
}
