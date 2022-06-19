#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, K, X[200000], up[200000][20];
bool F[200000], mk[200000];
vector<int> graph[200000];

void dfsF(int i, int p, int d){
    up[i][0] = p;
    for(int j = 1; j < 20; j++){
        up[i][j] = up[up[i][j-1]][j-1];
    }
    int jmpd = d/2;
    int v = i;
    for(int i = 0; i < 20; i++){
        if(((jmpd >> i) & 1) == 1){
            v = up[v][i];
        }
    }
    if(F[i]) F[v] = 1;
    for(int u : graph[i]){
        if(u == p) continue;
        dfsF(u, i, d+1);
    }
}

bool dfsL(int i, int p){
    int c = 0;
    int ret = 0;
    if(F[i]){
        mk[i] = 1;
        return 0;
    }
    for(int u : graph[i]){
        if(u == p) continue;
        c++;
        ret |= dfsL(u, i);
    }
    if(c == 0) return 1;
    return ret;
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N >> K;
        for(int i = 0; i < N; i++){
            graph[i].clear();
        }
        fill(F, F+N, 0);
        fill(mk, mk+N, 0);
        for(int i = 0; i < K; i++) eat >> X[i];
        for(int i = 0; i < K; i++) F[--X[i]] = 1;
        for(int i = 0; i < N-1; i++){
            int u, v; eat >> u >> v;
            graph[u-1].push_back(v-1);
            graph[v-1].push_back(u-1);
        }
        dfsF(0, 0, 0);
        if(dfsL(0, 0)){
            moo << -1 << endl;
        }else{
            int ans = accumulate(mk, mk+N, 0);
            moo << ans << endl;
        }
    }
}
