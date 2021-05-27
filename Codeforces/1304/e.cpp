#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout

using namespace std;

int N, Q, depth[100000], up[100000][20];
vector<int> graph[100000];

void dfs(int id){
    for(int i = 1; i < 20; i++){
        up[id][i] = up[up[id][i-1]][i-1];
    }
    for(int i : graph[id]){
        if(i == up[id][0]) continue;
        depth[i] = depth[id]+1;
        up[i][0] = id;
        dfs(i);
    }
}

int LCA(int u, int v){
    if(depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for(int i = 0; i < 20; i++){
        if((diff >> i) & 1) u = up[u][i];
    }
    if(u == v) return u;
    for(int i = 19; i >= 0; i--){
        if(up[u][i] != up[v][i]) u = up[u][i], v = up[v][i];
    }
    return up[u][0];
}

int dist(int u, int v){
    int lca = LCA(u, v);
    return depth[u] - depth[lca] + depth[v] - depth[lca];
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N;
    for(int i = 0; i < N-1; i++){
        int u, v; eat >> u >> v;
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);
    }
    depth[0] = up[0][0] = 0;
    dfs(0);
    eat >> Q;
    while(Q--){
        int x, y, a, b, k; eat >> x >> y >> a >> b >> k;
        x--, y--, a--, b--;
        int d1 = dist(a, b), d2 = dist(a, x) + 1 + dist(y, b), d3 = dist(a, y) + 1 + dist(x, b);
        if(d1 % 2 == k % 2 && d1 <= k || d2 % 2 == k % 2 && d2 <= k || d3 % 2 == k % 2 && d3 <= k){
            moo << "YeS" << endl;
        }else{
            moo << "nO" << endl;
        }
    }
}
