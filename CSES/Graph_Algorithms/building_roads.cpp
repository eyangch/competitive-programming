#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> graph[100000];
int vis[100000];

void dfs(int id){
    if(vis[id]) return;
    vis[id] = true;
    for(int i : graph[id]) dfs(i);
}

int32_t main(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }
    dfs(0);
    vector<int> ans;
    for(int i = 0; i < N; i++){
        if(!vis[i]){
            ans.push_back(i+1);
            dfs(i);
        }
    }
    cout << ans.size() << endl;
    for(int i : ans){
        cout << 1 << " " << i << endl;
    }
}
