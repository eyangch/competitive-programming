/*
Solution: O(N + M)
BFS bash. One bfs to find distances from capital.
Another bfs from each node to find nodes able to be reached without action 2
Another bfs after taking action 2 once.
*/

#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> graph[200000], rgraph[200000];
int dist[200000], vis[200000];
bool vis1[200000], vis2[200000], vis3[200000];
int ans[200000];

void bfs3(int x, int d){
    queue<int> q;
    q.push(x);
    while(!q.empty()){
        int id = q.front();
        q.pop();
        if(vis3[id]) continue;
        vis3[id] = true;
        ans[id] = min(ans[id], d);
        for(int i : rgraph[id]){
            if(dist[i] >= dist[id]) continue;
            q.push(i);
        }
    }
}

void bfs2(int x, int d){
    queue<int> q;
    q.push(x);
    while(!q.empty()){
        int id = q.front();
        q.pop();
        if(vis2[id]) continue;
        vis2[id] = true;
        ans[id] = min(ans[id], d);
        for(int i : rgraph[id]){
            if(dist[i] >= dist[id]){
                bfs3(i, d);
            }else{
                q.push(i);
            }
        }
    }
}

void bfs1(){
    queue<pair<int, int>> q;
    q.push({0, 0});
    while(!q.empty()){
        int id = q.front().first, d = q.front().second;
        q.pop();
        if(vis1[id]) continue;
        vis1[id] = true;
        bfs2(id, d);
        for(int i : graph[id]){
            q.push({i, d+1});
        }
    }
}

int32_t main(){
    int T; cin >> T;
    while(T--){
        cin >> N >> M;
        for(int i = 0; i < N; i++){
            vis[i] = vis1[i] = vis2[i] = vis3[i] = false;
            ans[i] = 1e9;
            graph[i].clear();
            rgraph[i].clear();
        }
        for(int i = 0; i < M; i++){
            int u, v; cin >> u >> v;
            graph[u-1].push_back(v-1);
            rgraph[v-1].push_back(u-1);
        }
        queue<pair<int, int>> q;
        q.push({0, 0});
        while(!q.empty()){
            int id = q.front().first, d = q.front().second;
            q.pop();
            if(vis[id]) continue;
            vis[id] = true;
            dist[id] = d;
            for(int i : graph[id]){
                q.push({i, d+1});
            }
        }
        bfs1();
        for(int i = 0; i < N; i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}
