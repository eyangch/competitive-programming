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
        graph[b-1].push_back(a-1);
        deg[a-1]++;
    }
    vector<int> ans;
    priority_queue<int> pq;
    for(int i = 0; i < N; i++){
        if(!deg[i]) pq.push(i);
    }
    while(!pq.empty()){
        int id = pq.top();
        pq.pop();
        ans.push_back(id);
        for(int i : graph[id]){
            if(!--deg[i]){
                pq.push(i);
            }
        }
    }
    for(int i = N-1; i >= 0; i--){
        cout << ans[i]+1 << " ";
    }
    cout << endl;
}
