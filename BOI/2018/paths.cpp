#include <bits/stdc++.h>
#define int long long

using namespace std;

int N, M, K;
int c[300000];
vector<int> graph[300000];
int dp[300000][32];
int ans = 0;

int dfs(int id, int left){
    if(dp[id][left] >= 0){
        return dp[id][left];
    }
    dp[id][left] = 0;
    for(int i : graph[id]){
        if(!(left & (1 << c[i]))){
            dp[id][left] += dfs(i, left | (1 << c[i])) + 1;
        }
    }
    return dp[id][left];
}

signed main(){
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++){
        cin >> c[i];
        c[i]--;
    }
    for(int i = 0; i < M; i++){
        int u, v; cin >> u >> v;
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);
    }
    fill(dp[0], dp[N-1]+32, -1);
    for(int i = 0; i < N; i++){
        ans += dfs(i, (1 << c[i]));
    }
    cout << ans << endl;
}
