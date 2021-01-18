#include <bits/stdc++.h>

using namespace std;

int a, b;
int dp[501][501];

int dfs(int x, int y){
    if(x == y) return 0;
    if(~dp[x][y]) return dp[x][y];
    int ret = 1e9;
    for(int i = x-1; i > 0; i--){
        ret = min(ret, dfs(i, y) + dfs(x-i, y) + 1);
    }
    for(int i = y-1; i > 0; i--){
        ret = min(ret, dfs(x, i) + dfs(x, y-i) + 1);
    }
    return dp[x][y] = ret;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;
    fill(dp[0], dp[a]+b+1, -1);
    cout << dfs(a, b) << endl;
}
