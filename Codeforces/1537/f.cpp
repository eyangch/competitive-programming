#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, M, v[200000], t[200000], alt[200000];
vector<int> graph[200000];
bool bipartite;

void dfs(int id, int par){
    if(alt[id] == -1) alt[id] = (id ? !alt[par] : 0);
    else{
        if(alt[id] == alt[par]) bipartite = false;
        return;
    }
    for(int i : graph[id]){
        dfs(i, id);
    }
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N >> M;
        for(int i = 0; i < N; i++) graph[i].clear();
        for(int i = 0; i < N; i++){
            eat >> v[i];
            v[i] += 1e9;
        }
        for(int i = 0; i < N; i++){
            eat >> t[i];
            t[i] += 1e9;
        }
        for(int i = 0; i < M; i++){
            int u, v; eat >> u >> v;
            graph[u-1].push_back(v-1);
            graph[v-1].push_back(u-1);
        }
        if(accumulate(v, v+N, 0LL) % 2 != accumulate(t, t+N, 0LL) % 2){
            moo << "NO" << endl;
            continue;
        }
        bipartite = true;
        fill(alt, alt+N, -1);
        dfs(0, -1);
        if(!bipartite){
            moo << "YES" << endl;
            continue;
        }
        int diff0 = 0, diff1 = 0;
        for(int i = 0; i < N; i++){
            if(alt[i]) diff1 += v[i] - t[i];
            else diff0 += v[i] - t[i];
        }
        moo << (diff0 == diff1 ? "YES" : "NO") << endl;
    }
}
