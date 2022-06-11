#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N;
vector<int> graph[300000];

int dfs(int i, int p){
    int tc = 0;
    for(int c : graph[i]){
        if(c == p) continue;
        tc++;
    }
    if(tc == 0) return 1;
    if(tc == 1) return 2;
    int mn_bad = 99999999;
    for(int c : graph[i]){
        if(c == p) continue;
        mn_bad = min(mn_bad, dfs(c, i));
    }
    return mn_bad + 2;
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N;
        for(int i = 0; i < N; i++) graph[i].clear();
        for(int i = 0; i < N-1; i++){
            int u, v; eat >> u >> v;
            graph[u-1].push_back(v-1);
            graph[v-1].push_back(u-1);
        }
        int bad = dfs(0, -1);
        moo << N - bad << endl;
    }
}
