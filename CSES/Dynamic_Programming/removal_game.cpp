#include <bits/stdc++.h>
#define int long long

using namespace std;

int N;
int x[5000];
int dp[5000][5000];

int dfs(int l, int r){
    if(l > r) return 0;
    if(dp[l][r] > LLONG_MIN) return dp[l][r];
    int ret = -1e18;
    ret = max(ret, x[l] - dfs(l+1, r));
    ret = max(ret, x[r] - dfs(l, r-1));
    return dp[l][r] = ret;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    int tsum = 0;
    for(int i = 0; i < N; i++){
        cin >> x[i];
        tsum += x[i];
    }
    fill(dp[0], dp[N-1]+N, LLONG_MIN);
    int ans = dfs(0, N-1);
    cout << (tsum - ans) / 2 + ans << endl;
}
