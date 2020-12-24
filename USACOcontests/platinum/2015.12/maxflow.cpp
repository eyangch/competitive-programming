#include <bits/stdc++.h>

using namespace std;

int N, K, M;
vector<int> graph[50000];
int depth[50000];
int parent[50000];
vector<int> etour;
int occ[50000];
int st[17][100000];
int lg2[100000];
int pfx[50000];
int ans = 0;

int idminf(int x, int y){
    return (depth[etour[x]] <= depth[etour[y]] ? x : y);
}

int query(int l, int r){
    if(l > r) swap(l, r);
    int p2 = lg2[r-l+1];
    return idminf(st[p2][l], st[p2][r-(1<<p2)+1]);
}

void dfsdepth(int id, int par, int d){
    depth[id] = d;
    parent[id] = par;
    for(int i : graph[id]){
        if(i == par) continue;
        dfsdepth(i, id, d+1);
    }
}

void dfstour(int id, int par){
    occ[id] = etour.size();
    etour.push_back(id);
    for(int i : graph[id]){
        if(i == par) continue;
        dfstour(i, id);
        etour.push_back(id);
    }
}

int dfsans(int id, int par){
    int curr = pfx[id];
    for(int i : graph[id]){
        if(i == par) continue;
        curr += dfsans(i, id);
    }
    ans = max(ans, curr);
    return curr;
}
    
signed main(){
    freopen("maxflow.in", "r", stdin);
    freopen("maxflow.out", "w", stdout);
    cin >> N >> K;
    for(int i = 0; i < N-1; i++){
        int x, y; cin >> x >> y;
        graph[x-1].push_back(y-1);
        graph[y-1].push_back(x-1);
    }
    dfsdepth(0, -1, 0); 
    dfstour(0, -1);
    M = etour.size();
    iota(st[0], st[0]+M, 0);
    lg2[1] = 0;
    for(int i = 2; i <= M; i++){
        lg2[i] = lg2[i/2]+1;
    }
    for(int i = 1; i <= lg2[M]; i++){
        for(int j = 0; j + (1<<i) - 1 < M; j++){
            st[i][j] = idminf(st[i-1][j], st[i-1][j+(1<<(i-1))]);
        }
    }
    for(int i = 0; i < K; i++){
        int s, t; cin >> s >> t;
        s--; t--;
        pfx[s]++; pfx[t]++;
        int lca = etour[query(occ[s], occ[t])];
        pfx[lca]--;
        if(parent[lca] >= 0){
            pfx[parent[lca]]--;
        }
    }
    dfsans(0, -1);
    cout << ans << endl;
}
