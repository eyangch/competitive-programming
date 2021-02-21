#include <bits/stdc++.h>
#define endl "\n"
#define int long long

using namespace std;

int MOD = 1e9+7;
int N, K, dp[4][3], p3[300000];
string s;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> s;
    for(char i : s) K += (i == '?');
    p3[0] = 1;
    for(int i = 1; i < 300000; i++){
        p3[i] = 3 * p3[i-1] % MOD;
    }
    for(int i = 0; i < N; i++){
        if(s[i] == 'a'){
            dp[0][0]++;
        }else if(s[i] == 'b'){
            dp[0][1] += dp[0][0];
            dp[1][1] += dp[1][0];
        }else if(s[i] == 'c'){
            dp[0][2] += dp[0][1];
            dp[1][2] += dp[1][1];
            dp[2][2] += dp[2][1];
        }else{
            dp[3][2] += dp[2][1];
            dp[2][2] += dp[1][1];
            dp[1][2] += dp[0][1];
            dp[2][1] += dp[1][0];
            dp[1][1] += dp[0][0];
            dp[1][0]++;
        }
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 3; k++){
                dp[j][k] %= MOD;
            }
        }
    }
    int ans = dp[0][2] * p3[K] % MOD;
    if(K > 0) ans = (ans + dp[1][2] * p3[K-1]) % MOD;
    if(K > 1) ans = (ans + dp[2][2] * p3[K-2]) % MOD;
    if(K > 2) ans = (ans + dp[3][2] * p3[K-3]) % MOD;
    cout << ans << endl;
}
