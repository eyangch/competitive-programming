#include <bits/stdc++.h>

using namespace std;

int dp[5000][5000];
int N, M;
string a, b;

int dfs(int x, int y){
    if(x == -1) return y+1;
    if(y == -1) return x+1;
    if(~dp[x][y]) return dp[x][y];
    int ret = (a[x] != b[y]) + dfs(x-1, y-1);
    ret = min(ret, dfs(x-1, y) + 1);
    ret = min(ret, dfs(x, y-1) + 1);
    return dp[x][y] = ret;
}

int32_t main(){
    cin >> a >> b;
    N = a.size(), M = b.size();
    fill(dp[0], dp[N-1]+M, -1);
    cout << dfs(N-1, M-1) << endl;
}
