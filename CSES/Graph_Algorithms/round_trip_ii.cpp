#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int N, M;
vector<int> graph[100000], cycle;
bool vis1[100000], vis2[100000], fcycle;

void dfs(int id){
    if(vis2[id]){
        fcycle = true;
        cycle.push_back(id);
        return;
    }
    if(vis1[id]) return;
    vis1[id] = true;
    vis2[id] = true;
    cycle.push_back(id);
    for(int i : graph[id]){
        dfs(i);
        if(fcycle) return;
    }
    cycle.pop_back();
    vis2[id] = false;
}

int32_t main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b;
        graph[a-1].push_back(b-1);
    }
    for(int i = 0; i < N; i++){
        dfs(i);
        if(fcycle){
            stack<int> ans;
            int v = cycle.back();
            cycle.pop_back();
            ans.push(v);
            while(cycle.back() != v){
                ans.push(cycle.back());
                cycle.pop_back();
            }
            ans.push(v);
            cout << ans.size() << endl;
            while(!ans.empty()){
                cout << ans.top()+1 << " ";
                ans.pop();
            }
            cout << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}
