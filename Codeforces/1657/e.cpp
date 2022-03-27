#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long
#define fi first
#define se second

using namespace std;

int MOD = 998244353;
int N, K, f[300], fi[300], dp[260][260];

int bp(int n, int e){
    int a = 1;
    for(int i = 0; i < 32; i++){
        if(e>>i & 1) a = a * n % MOD;
        n = n * n % MOD;
    }
    return a;
}

int inv(int n){
    return bp(n, MOD-2);
}

int nCr(int n, int r){
    if(n < r) return 0;
    return f[n] * fi[r] % MOD * fi[n-r] % MOD;
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N >> K;
    N--;
    f[0] = 1;
    for(int i = 1; i < 300; i++) f[i] = f[i-1] * i % MOD;
    for(int i = 0; i < 300; i++) fi[i] = inv(f[i]);
    for(int i = 1; i <= K; i++){
        dp[0][i] = dp[0][i-1] + N;
    }
    for(int i = 1; i < N; i++){
        for(int j = 1; j <= K; j++){
            dp[i][j] = bp(K-j+1, nCr(i+1, 2)) * nCr(N, i+1) % MOD;
            for(int k = 0; k < i; k++){
                dp[i][j] = (dp[i][j] + nCr(N-1-k, i-k) * bp(K-j+1, (nCr(i-k, 2) + (i-k) * (k+1) % MOD)) % MOD * dp[k][j-1]) % MOD;
            }
            dp[i][j] = (dp[i][j-1] + dp[i][j]) % MOD;
        }
    }
    moo << dp[N-1][K] << endl;
}
