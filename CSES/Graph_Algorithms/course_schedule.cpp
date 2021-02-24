#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int N, M, deg[100000];
vector<int> graph[100000];

int32_t main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b;
        graph[a-1].push_back(b-1);
        deg[b-1]++;
    }
    vector<int> ans;
    queue<int> q;
    for(int i = 0; i < N; i++){
        if(!deg[i]) q.push(i);
    }
    while(!q.empty()){
        int id = q.front();
        q.pop();
        ans.push_back(id);
        for(int i : graph[id]){
            if(!--deg[i]){
                q.push(i);
            }
        }
    }
    if((int)ans.size() < N){
        cout << "IMPOSSIBLE" << endl;
    }else{
        for(int i : ans){
            cout << i+1 << " ";
        }
    }
    cout << endl;
}
