/*
ID: sireric1
TASK: money
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    freopen("money.in", "r", stdin);
    freopen("money.out", "w", stdout);
    ll V, N, coins[25];
    cin >> V >> N;
    for(int i = 0; i < V; i++){
        cin >> coins[i];
    }
    sort(coins, coins + V);
    ll dp[N+1];
    fill(dp, dp + N + 1, 0);
    dp[0] = 1;
    for(int i = 0; i < V; i++){
        for(int j = coins[i]; j < N + 1; j++){
            dp[j] += dp[j - coins[i]];
        }
    }
    cout << dp[N] << endl;
    return 0;
}
