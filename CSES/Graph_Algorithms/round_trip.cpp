#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> graph[100000];
bool vis[100000];
bool term;
deque<int> path;

void dfs(int id, int par){
    path.push_back(id);
    if(vis[id]){
        while(true){
            if(path.front() == id){
                break;
            }
            path.pop_front();
        }
        term = true;
        return;
    }
    vis[id] = true;
    for(int i : graph[id]){
        if(i == par) continue;
        dfs(i, id);
        if(term) return;
    }
    path.pop_back();
}

int32_t main(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }
    for(int i = 0; i < N; i++){
        if(vis[i]) continue;
        dfs(i, i);
        if(term){
            cout << path.size() << endl;
            while(!path.empty()){
                cout << path.front() + 1 << " ";
                path.pop_front();
            }
            cout << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}
