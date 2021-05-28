#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, M;
int dp[400][400];
int fact[100000];
int mem[401][401];

int bpow(int b, int e){
    int ret = 1;
    for(int i = 0; i < 32; i++){
        if((e>>i)&1) ret = ret * b % M;
        b = b * b % M;
    }
    return ret;
}

int seg(int on, int len){
    if(mem[on][len] > 0) return mem[on][len];
    return mem[on][len] = fact[on] * bpow(fact[len] * fact[on-len] % M, M-2) % M * bpow(2, len-1) % M;
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N >> M;
    fact[0] = 1;
    for(int i = 1; i < 100000; i++){
        fact[i] = fact[i-1] * i % M;
    }
    for(int i = 0; i < N; i++){
        dp[i][i] = seg(i+1, i+1);
    }
    for(int i = 1; i < N; i++){
        for(int j = 0; j <= i; j++){
            for(int k = 1; i - k > 0 && j - k >= 0; k++){
                dp[i][j] = (dp[i][j] + dp[i-k-1][j-k] * seg(j+1, k) % M) % M;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        ans = (ans + dp[N-1][i]) % M;
    }
    moo << ans << endl;
}
