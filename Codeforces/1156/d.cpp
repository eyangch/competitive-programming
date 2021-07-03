#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, par[2][200000], sz[2][200000];

int find(int u, int i){
    return (u == par[i][u] ? u : par[i][u] = find(par[i][u], i));
}

void un(int u, int v, int i){
    u = find(u, i), v = find(v, i);
    if(u == v) return;
    if(sz[i][u] < sz[i][v]) swap(u, v);
    sz[i][u] += sz[i][v];
    par[i][v] = par[i][u];
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N;
    for(int i = 0; i < 2; i++) fill(sz[i], sz[i]+N, 1), iota(par[i], par[i]+N, 0);
    for(int i = 0; i < N-1; i++){
        int u, v, c; eat >> u >> v >> c;
        un(u-1, v-1, c);
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        ans += sz[0][find(i, 0)] + sz[1][find(i, 1)] - 2 + (sz[0][find(i, 0)] - 1) * (sz[1][find(i, 1)] - 1);
    }
    moo << ans << endl;
}
