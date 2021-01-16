#include <bits/stdc++.h>

using namespace std;

long long MOD = 1e9+7;

int T, N;
long long dp[1000001][2][2][2]; // UL, UR, MID

long long sum(int i){
    long long ret = 0;
    for(int x = 0; x < 2; x++){
        for(int y = 0; y < 2; y++){
            for(int z = 0; z < 2; z++){
                ret += dp[i][x][y][z];
            }
        }
    }
    return ret;
}

int32_t main(){
    cin >> T;
    dp[0][1][1][1] = dp[0][1][1][0] = 1;
    for(int i = 1; i < 1000000; i++){
        dp[i][0][0][0] = (dp[i-1][0][0][0] + dp[i-1][1][1][0]) % MOD;
        dp[i][1][1][0] = dp[i][1][1][1] = sum(i-1) % MOD;
        dp[i][0][0][1] = dp[i][1][0][1] = dp[i][0][1][1] = (dp[i-1][0][0][1] + dp[i-1][1][1][1] + dp[i-1][0][1][1] + dp[i-1][1][0][1]) % MOD;
    }
    while(T--){
        cin >> N;
        cout << sum(N-1) % MOD << endl;
    }
}
