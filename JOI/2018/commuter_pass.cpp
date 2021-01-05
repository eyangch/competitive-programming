#include <bits/stdc++.h>
#define int long long

using namespace std;

int N, M, S, T, U, V;
vector<pair<int, int>> graph[100000];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int dists[100000], distt[100000], distu[100000], distv[100000];
int dp[100000], ans;

void dij(int start, int (&dist)[100000]){
    pq.push({0, start});
    fill(dist, dist+N, 1e17);
    dist[start] = 0;
    while(!pq.empty()){
        int id = pq.top().second, d = pq.top().first;
        pq.pop();
        if(dist[id] != d) continue;
        for(pair<int, int> i : graph[id]){
            if(d + i.second < dist[i.first]){
                dist[i.first] = d + i.second;
                pq.push({dist[i.first], i.first});
            }
        }
    }
}

int dfs(int id, int (&dar)[100000]){
    if(~dp[id]) return dp[id];
    dp[id] = distu[id];
    for(pair<int, int> i : graph[id]){
        if(dar[i.first] == dar[id] - i.second){
            dp[id] = min(dp[id], dfs(i.first, dar));
        }
    }
    ans = min(ans, dp[id] + distv[id]);
    return dp[id];
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> S >> T >> U >> V;
    S--, T--, U--, V--;
    for(int i = 0; i < M; i++){
        int a, b, c; cin >> a >> b >> c;
        graph[a-1].push_back({b-1, c});
        graph[b-1].push_back({a-1, c});
    }
    dij(S, dists), dij(T, distt), dij(U, distu), dij(V, distv);
    ans = distu[V];
    fill(dp, dp+N, -1);
    dfs(T, dists);
    fill(dp, dp+N, -1);
    dfs(S, distt);
    cout << ans << endl;
}
