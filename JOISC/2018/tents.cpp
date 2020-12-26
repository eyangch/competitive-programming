#include <bits/stdc++.h>

using namespace std;

long long MOD = 1e9+7;

int H, W;
long long dp[3001][3001];

signed main(){
    cin >> H >> W;
    for(int i = 0; i <= W; i++) dp[0][i] = 1; // one way to make nothing
    for(int i = 0; i <= H; i++) dp[i][0] = 1;
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            if(i > 0){
                dp[i][j] += dp[i-1][j]; // nothing on row i up to j
            }if(i > 0 && j > 0){
                dp[i][j] += 4 * j * dp[i-1][j-1]; // one "unattached" tent on row i up to j
            }if(i > 0 && j > 1){
                dp[i][j] += j * (j-1) / 2 * dp[i-1][j-2]; // two attached tents facing each other on row i up to j
            }if(i > 1 && j > 0){
                dp[i][j] += j * (i-1) * dp[i-2][j-1]; // one tent on row i attached to another from prev (0...i-1)
            }
            dp[i][j] %= MOD;
        }
    }
    cout << (dp[H][W]-1+MOD) % MOD << endl;
}
