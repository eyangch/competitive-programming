#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, M, ans[400000], vis[3][400000];
vector<int> graph[400000];

void dfs(int id, int t){
    if(vis[t][id] == 2){
        if(t < 2){
            dfs(id, 2);
        }
        return;
    }
    if(vis[t][id] == 1){
        if(t < 1){
            dfs(id, 1);
        }
        return;
    }
    ans[id] = max(ans[id], t);
    vis[t][id] = 2;
    for(int i : graph[id]){
        dfs(i, t);
    }
    vis[t][id] = 1;
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N >> M;
        for(int i = 0; i < N; i++) graph[i].clear();
        for(int i = 0; i < M; i++){
            int u, v; eat >> u >> v;
            graph[u-1].push_back(v-1);
        }
        fill(ans, ans+N, -1);
        for(int i = 0; i < 3; i++) fill(vis[i], vis[i]+N, 0);
        dfs(0, 0);
        for(int i = 0; i < N; i++){
            moo << ((ans[i] + 2) % 4 - 1) << ' ';
        }
        moo << endl;
    }
}
