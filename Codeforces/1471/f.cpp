#include <bits/stdc++.h>

using namespace std;

int T, N, M;
vector<int> graph[300000];
int vis[300000], tch[300000];
vector<int> ans;

void dfs(int id, bool t){
    if(vis[id]) return;
    if(t){
        for(int i : graph[id]){
            if(tch[i]) return;
        }
    }
    vis[id] = true;
    tch[id] = t;
    if(t) ans.push_back(id+1);
    for(int i : graph[id]){
        dfs(i, !t);
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--){
        cin >> N >> M;
        ans.clear();
        for(int i = 0; i < N; i++){
            graph[i].clear();
            vis[i] = false;
            tch[i] = false;
        }
        for(int i = 0; i < M; i++){
            int u, v; cin >> u >> v;
            graph[u-1].push_back(v-1);
            graph[v-1].push_back(u-1);
        }
        dfs(0, true);
        bool pos = true;
        for(int i = 0; i < N; i++){
            pos &= vis[i];
        }
        if(pos){
            cout << "YES" << endl << ans.size() << endl;
            for(int i : ans){
                cout << i << " ";
            }
            cout << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}
