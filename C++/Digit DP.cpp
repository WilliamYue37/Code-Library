int a, b, d, k;
string num;
int memo[MAX_LEN][MAX_K][2];

int dp(int i, int c, int f) {
    if (c > k) return 0;
    if (i == num.size()) return (c == k) ? 1 : 0;
    if (memo[i][c][f] != -1) return memo[i][c][f];
    int res = 0;
    int limit = (f == 0 ? num[i] - '0' : 9);
    for (int j = 0; j <= limit; ++j) {
        int nf = f, nc = c;
        if (f == 0 && j < limit) nf = 1;
        if (j == d) ++nc;
        res += dp(i + 1, nc, nf);
    }
    return memo[i][c][f] = res;
}
