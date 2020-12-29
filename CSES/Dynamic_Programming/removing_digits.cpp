#include <bits/stdc++.h>

using namespace std;

int N;
int dp[1000001];

int32_t main(){
    scanf("%d", &N);
    fill(dp, dp+N, 1e6);
    dp[N] = 0;
    for(int i = N; i >= 0; i--){
        if(dp[i] < 1e6){
            int x = i;
            while(x > 0){
                int num = x%10;
                x /= 10;
                dp[i-num] = min(dp[i-num], dp[i]+1);
            }
        }
    }
    printf("%d\n", dp[0]);
}
