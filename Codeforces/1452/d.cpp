#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int MOD = 998244353;
int N, dp[200000];

int bpow(int b, int e){
    int ret = 1;
    for(int i = 0; i < 31; i++){
        if((e>>i)&1) ret = ret * b % MOD;
        b = b * b % MOD;
    }
    return ret;
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N;
    dp[0] = dp[1] = 1;
    for(int i = 2; i < N; i++) dp[i] = (dp[i-1] + dp[i-2]) % MOD;
    moo << dp[N-1] * bpow(2, N * (MOD-2) % (MOD-1)) % MOD << endl;
}
