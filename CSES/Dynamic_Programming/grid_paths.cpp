#include <bits/stdc++.h>

using namespace std;

int MOD = 1e9+7;

int N;
string g[1000];
int dp[1000][1000];

int dfs(int x, int y){
    if(x < 0 || y < 0 || x >= N || y >= N || g[x][y] == '*') return 0;
    if(dp[x][y] >= 0) return dp[x][y];
    return dp[x][y] = ((x+y == 2*(N-1)) + dfs(x+1, y) + dfs(x, y+1)) % MOD;
}

int32_t main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> g[i];
    }
    fill(dp[0], dp[N-1]+N, -1);
    cout << dfs(0, 0) << endl;
}
