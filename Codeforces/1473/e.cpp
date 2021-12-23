#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long
#define fi first
#define se second

using namespace std;

int N, M;
vector<pair<int, int>> graph[200000];
int d[200000][4];

void dij(int b){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(int i = 0; i < N; i++){
        if(d[i][b] < 1e15){
            pq.push({d[i][b], i});
        }
    }
    while(!pq.empty()){
        int c = pq.top().fi;
        int x = pq.top().se;
        pq.pop();
        if(d[x][b] != c) continue;
        for(pair<int, int> i : graph[x]){
            if(d[i.fi][b] > c + i.se){
                d[i.fi][b] = c + i.se;
                pq.push({d[i.fi][b], i.fi});
            }
            if((b | 1) != b){
                d[i.fi][b|1] = min(d[i.fi][b|1], c);
            }
            if((b | 2) != b){
                d[i.fi][b|2] = min(d[i.fi][b|2], c + i.se*2);
            }
            if((b | 1) != b && (b | 2) != b){
                d[i.fi][3] = min(d[i.fi][3], c + i.se);
            }
        }
    }
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N >> M;
    for(int i = 0; i < M; i++){
        int u, v, w; eat >> u >> v >> w;
        graph[u-1].push_back({v-1, w});
        graph[v-1].push_back({u-1, w});
    }
    for(int i = 0; i < N; i++) fill(d[i], d[i]+4, 1e15);
    d[0][0] = 0;
    dij(0), dij(1), dij(2), dij(3);
    for(int i = 1; i < N; i++){
        moo << d[i][3] << ' ';
    }
    moo << endl;
}
