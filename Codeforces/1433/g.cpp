#include <bits/stdc++.h>
#define endl "\n"
#define f first
#define s second

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N, M, K, di[1000][1000];
pii e[1000], p[1000];
vector<pii> graph[1000];

void dij(int src){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, src});
    while(!pq.empty()){
        int id = pq.top().s, d = pq.top().f;
        pq.pop();
        if(di[src][id] != d) continue;
        for(pii i : graph[id]){
            if(di[src][i.f] > d + i.s){
                di[src][i.f] = d + i.s;
                pq.push({d + i.s, i.f});
            }
        }
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            di[i][j] = 1e9;
        }
        di[i][i] = 0;
    }
    for(int i = 0; i < M; i++){
        int x, y, w; cin >> x >> y >> w;
        graph[x-1].push_back({y-1, w});
        graph[y-1].push_back({x-1, w});
        e[i] = {x-1, y-1};
    }
    for(int i = 0; i < N; i++){
        dij(i);
    }
    for(int i = 0; i < K; i++){
        cin >> p[i].f >> p[i].s;
        p[i].f--, p[i].s--;
    }
    int ans = 2e9;
    for(int i = 0; i < M; i++){
        int cost = 0;
        for(int j = 0; j < K; j++){
            cost += min({di[p[j].f][p[j].s], di[p[j].f][e[i].f] + di[e[i].s][p[j].s], di[p[j].f][e[i].s] + di[e[i].f][p[j].s]});
            if(cost >= ans) break;
        }
        ans = min(ans, cost);
    }
    cout << ans << endl;
}
