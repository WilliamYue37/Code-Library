int fastExpo(int base, int e) {
    int ans = 1;
    while (e != 0) {
        if (e % 2 == 1) ans = (ll)ans * base % MOD;
        base = (ll)base * base % MOD;
        e /= 2;
    }
    return ans;
}

namespace modOp {
    int add(int a, int b, int mod = MOD) {return ((ll)a + b + mod) % mod; /*int r = a + b; if (r >= mod) r -= mod; return r;*/}
    void ADD(int& a, int b, int mod = MOD) {a = ((ll)a + b + mod) % mod; /*a += b; if (a >= mod) a -= mod;*/}
    int sub(int a, int b, int mod = MOD) {return ((ll)a - b + mod) % mod; /*int r = a - b; if (r < 0) r += mod; return r;*/}
    void SUB(int& a, int b, int mod = MOD) {a = ((ll)a - b + mod) % mod; /*a -= b; if (a < 0) a += mod;*/}
    int mul(int a, int b, int mod = MOD) {return (ll)a * b % mod;}
    void MUL(int& a, int b, int mod = MOD) {a = (ll)a * b % mod;}
    int divide(int a, int b, int mod = MOD) {return (ll)a * fastExpo(b, mod - 2) % mod;}
    void DIVIDE(int& a, int b, int mod = MOD) {a = (ll)a * fastExpo(b, mod - 2) % mod;}
}
using namespace modOp;
