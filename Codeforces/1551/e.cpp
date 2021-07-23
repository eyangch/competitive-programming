#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, K, a[2000], v[2000], sfx[2001][2001], dp[2001][2001];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N >> K;
        for(int i = 0; i < N; i++){
            eat >> a[i];
            a[i]--;
            v[i] = i - a[i];
        }
        for(int i = 0; i < N; i++){
            sfx[N][i] = 0;
        }
        for(int i = N-1; i >= 0; i--){
            for(int j = 0; j < N; j++){
                sfx[i][j] = sfx[i+1][j] + (v[i] == j);
            }
        }
        dp[0][0] = sfx[0][0];
        dp[0][1] = sfx[1][1];
        int ans = 1e17;
        for(int i = 1; i < N; i++){
            dp[i][0] = dp[i-1][0];
            for(int j = 1; j <= N; j++){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] - sfx[i][j-1] + sfx[i+1][j]);
            }
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j <= N; j++){
                if(dp[i][j] >= K) ans = min(ans, j);
            }
        }
        moo << (ans == 1e17 ? -1 : ans) << endl;
    }
}
