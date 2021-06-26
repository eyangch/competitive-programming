#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int MOD = 1e9+7;
int N, up[10][200], de[200], dp[200][200], inv2, invn;
vector<int> graph[200];

void dfs(int id, int par, int d){
    for(int i = 1; i < 10; i++){
        up[i][id] = up[i-1][up[i-1][id]];
    }
    de[id] = d;
    for(int i : graph[id]){
        if(i == par) continue;
        up[0][i] = id;
        dfs(i, id, d+1);
    }
}

int lca(int u, int v){
    if(de[u] < de[v]) swap(u, v);
    for(int i = 9; i >= 0; i--){
        if(de[up[i][u]] >= de[v]) u = up[i][u];
    }
    if(u == v) return u;
    for(int i = 9; i >= 0; i--){
        if(up[i][v] != up[i][u]) v = up[i][v], u = up[i][u];
    }
    return up[0][u];
}

int dist(int u, int v){
    return de[u] + de[v] - 2 * de[lca(u, v)];
}

int inv(int b){
    int ans = 1, e = MOD - 2;
    for(int i = 0; i < 32; i++){
        if((e>>i) & 1) ans = ans * b % MOD;
        b = b * b % MOD;
    }
    return ans;
}

int dpf(int s1, int s2){
    if(dp[s1][s2] >= 0) return dp[s1][s2];
    return (dp[s1][s2] = inv2 * (dpf(s1-1, s2) + dpf(s1, s2-1)) % MOD);
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N;
    inv2 = inv(2), invn = inv(N);
    for(int i = 0; i < N-1; i++){
        int u, v; eat >> u >> v;
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);
    }
    fill(dp[0], dp[0]+N, 1);
    for(int i = 1; i < N; i++) fill(dp[i]+1, dp[i]+N, -1);
    int ans = 0;
    for(int i = 0; i < N; i++){
        de[i] = 0;
        up[0][i] = i;
        dfs(i, -1, 0);
        for(int j = 0; j < N; j++){
            for(int k = j+1; k < N; k++){
                int l = lca(j, k);
                ans = (ans + dpf(de[k] - de[l], de[j] - de[l])) % MOD;
            }
        }
    }
    moo << ans * invn % MOD << endl;
}
