#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> graph[100000];
int team[100000];

bool dfs(int id, int t){
    if(team[id] > 0){
        if(team[id] != t){
            return false;
        }
        return true;
    }
    team[id] = t;
    for(int i : graph[id]){
        if(!dfs(i, (2-t) + 1)){
            return false;   
        }
    }
    return true;
}

int32_t main(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }
    for(int i = 0; i < N; i++){
        if(team[i]) continue;
        if(!dfs(i, 1)){
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    for(int i = 0; i < N; i++){
        cout << team[i] << " ";
    }
    cout << endl;
}
