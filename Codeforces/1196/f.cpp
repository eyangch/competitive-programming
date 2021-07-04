#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long
#define f first
#define s second

using namespace std;
typedef pair<int, int> pii;

int N, M, K;
vector<pii> graph[200000];
set<pii> vis;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N >> M >> K;
    K = K * 2;
    for(int i = 0; i < M; i++){
        int u, v, w; eat >> u >> v >> w;
        graph[u-1].push_back({v-1, w});
        graph[v-1].push_back({u-1, w});
    }
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
    int mx = 0;
    for(int i = 0; i < N; i++){
        vis.insert({i, i});
        for(pii j : graph[i]){
            if(pq.size() >= 1000 && j.s > mx) continue;
            mx = max(mx, j.s);
            pq.push({j.s, {i, j.f}});
        }
    }
    while(!pq.empty()){
        int d = pq.top().f, start = pq.top().s.f, cur = pq.top().s.s;
        pq.pop();
        if(vis.count({start, cur})) continue;
        vis.insert({start, cur});
        if(--K == 0){
            moo << d << endl;
            return 0;
        }
        for(pii i : graph[cur]){
            if(pq.size() >= 1000 && d+i.s > mx) continue;
            mx = max(mx, d+i.s);
            pq.push({d + i.s, {start, i.f}});
        }
    }
}
