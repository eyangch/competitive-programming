#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int MOD = 1e9+7, m2 = 500000004;
int T, N, M, K, dp[2001][2001];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N >> M >> K;
        int a = M, s = N-M;
        for(int i = 0; i <= a; i++){
            dp[i][0] = i * K % MOD;
        }
        for(int i = 0; i <= s; i++){
            dp[0][i] = 0;
        }
        for(int i = 1; i <= a; i++){
            for(int j = 1; j <= s; j++){
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) * m2 % MOD;
            }
        }
        moo << dp[a][s] << endl;
    }
}
