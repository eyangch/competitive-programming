#include <bits/stdc++.h>
#define int long long

using namespace std;

int MOD = 1e9+7;

int N, K, Q;
int a[5000], oc[5000], dp[5001][5000];

int32_t main(){
    cin >> N >> K >> Q;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    fill(dp[0], dp[0]+N, 1);
    for(int i = 1; i < K+1; i++){
        dp[i][0] = dp[i-1][1];
        dp[i][N-1] = dp[i-1][N-2];
        for(int j = 1; j < N-1; j++){
            dp[i][j] = (dp[i][j] + dp[i-1][j-1] + dp[i-1][j+1]) % MOD;
        }
    }
    for(int i = 0; i < K+1; i++){
        for(int j = 0; j < N; j++){
            oc[j] = (oc[j] + dp[i][j] * dp[K-i][j]) % MOD;
        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        ans = (ans + oc[i] * a[i]) % MOD;
    }
    for(int i = 0; i < Q; i++){
        int id, x; cin >> id >> x;
        id--;
        ans = (((ans + oc[id] * (x - a[id])) % MOD) + MOD) % MOD;
        a[id] = x;
        cout << ans << endl;
    }
}
