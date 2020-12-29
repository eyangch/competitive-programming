#include <bits/stdc++.h>

using namespace std;

int MOD = 1e9+7;

int N, M;
int x[100000];
long long dp[100000][102];

int32_t main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> x[i];
    }
    int ans = 1;
    if(x[0] == 0){
        fill(dp[0]+1, dp[0]+M+1, 1);
        ans = M;
    }
    else dp[0][x[0]] = 1;
    for(int i = 1; i < N; i++){
        ans = 0;
        for(int j = 1; j <= M; j++){
            if(x[i] == 0 || x[i] == j){
                dp[i][j] = (dp[i][j] + dp[i-1][j] + dp[i-1][j-1] + dp[i-1][j+1]) % MOD;
                ans = (ans + dp[i][j]) % MOD;
            }
        }
    }
    cout << ans << endl;
}
