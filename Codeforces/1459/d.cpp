#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int N, a[100], b[100], tB, dp[2][100][10001];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i] >> b[i];
        tB += b[i];
    }
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 100; j++){
            for(int k = 0; k < 10001; k++){
                dp[i][j][k] = -1e9;
            }
        }
    }
    dp[0][0][a[0]] = b[0];
    for(int i = 0; i < N; i++){
        double ans = 0;
        for(int j = i; j < N; j++){
            for(int k = 0; k < 10001; k++){
                if(j > 0){
                    dp[i%2][j][k] = dp[i%2][j-1][k];
                    if(k-a[j] >= 0 && i > 0){
                        dp[i%2][j][k] = max(dp[i%2][j][k], dp[(i-1)%2][j-1][k-a[j]] + b[j]);
                    }
                }
                if(i == 0 && a[j] == k) dp[i%2][j][k] = max(dp[i%2][j][k], b[j]);
                ans = max(ans, min((double)k, (double)dp[i%2][j][k] + (double)(tB - dp[i%2][j][k]) / 2));
            }
        }
        cout << ans << " ";
    }
    cout << endl;
}
