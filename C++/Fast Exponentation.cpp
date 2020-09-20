int fastExpo(int base, int e) {
    int ans = 1;
    while (e != 0) {
        if (e % 2 == 1) ans = (ll)ans * base % MOD;
        base = (ll)base * base % MOD;
        e /= 2;
    }
    return ans;
}
