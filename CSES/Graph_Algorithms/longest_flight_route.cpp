#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int N, M, dp[100000], deg[100000];
vector<int> graph[100000], rgraph[100000];
bool rch[100000];

void dfs(int id){
    if(rch[id]) return;
    rch[id] = true;
    for(int i : graph[id]){
        dfs(i);
    }
}

int32_t main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b;
        graph[a-1].push_back(b-1);
        deg[b-1]++;
        rgraph[b-1].push_back(a-1);
    }
    dfs(0);
    for(int i = 0; i < N; i++){
        if(!rch[i]){
            for(int j : graph[i]){
                deg[j]--;
            }
        }
    }
    fill_n(&dp[0], 100000, -2);
    queue<int> q;
    q.push(0);
    dp[0] = 0;
    while(!q.empty()){
        int id = q.front();
        q.pop();
        for(int i : graph[id]){
            dp[i] = max(dp[i], dp[id]+1);
            if(!--deg[i]){
                q.push(i);
            }
        }
    }
    stack<int> ans;
    int v = N-1;
    if(dp[v] == -2){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    while(true){
        ans.push(v);
        for(int i : rgraph[v]){
            if(dp[i] == dp[v]-1){
                v = i;
                goto bad_practice;
            }
        }
        break;
        bad_practice:;
    }
    cout << ans.size() << endl;
    while(!ans.empty()){
        cout << ans.top() + 1 << " ";
        ans.pop();
    }
    cout << endl;
}
