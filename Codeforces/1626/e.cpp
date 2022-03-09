#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long
#define fi first
#define se second

using namespace std;

struct edge{
    int v, n;
};

int N, ans[300000];
bool C[300000];
vector<edge> graph[300000];
set<int> active[300000];

void dfs_e(int v, int p){
    for(auto it = active[v].begin(); it != active[v].end();){
        edge &e = graph[v][*it];
        if(e.v == p){
            it++;
            continue;
        }
        if(++e.n == 2) it = active[v].erase(it);
        else it++;
        dfs_e(e.v, v);
    }
}

void dfs_a(int v){
    for(edge e : graph[v]){
        if(ans[e.v] || !e.n || (e.n == 1 && ans[v] == 1)) continue;
        ans[e.v] = e.n;
        dfs_a(e.v);
    }
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N;
    for(int i = 0; i < N; i++) eat >> C[i];
    for(int i = 0; i < N-1; i++){
        int u, v; eat >> u >> v;
        u--, v--;
        graph[u].push_back({v, 0});
        graph[v].push_back({u, 0});
        active[u].insert(active[u].size());
        active[v].insert(active[v].size());
    }
    for(int i = 0; i < N; i++){
        if(C[i]) dfs_e(i, -1);
    }
    for(int i = 0; i < N; i++){
        if(C[i]){
            ans[i] = 2;
            dfs_a(i);
        }
    }
    for(int i = 0; i < N; i++){
        moo << (ans[i] > 0) << ' ';
    }
    moo << endl;
}
