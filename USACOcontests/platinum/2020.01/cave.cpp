#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define f first
#define s second
#define int long long

using namespace std;

int MOD = 1e9+7;
int N, M;
string s[1000];
int ways[1000][1000];
int par[1000][1000];
vector<int> graph[2][1000];
bool vis[2][1000];
bool active[1000][1000];

void dfs(int group, int id, int lvl, int p){
    if(vis[group][id]) return;
    vis[group][id] = 1;
    if(group == 0){
        par[lvl][id] = p;
    }
    for(int i : graph[group][id]){
        dfs(!group, i, lvl, p);
    }
}

int32_t main(){
    freopen("cave.in", "r", stdin);
    freopen("cave.out", "w", stdout);
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N >> M;
    for(int i = 0; i < N; i++){
        eat >> s[i];
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            ways[i][j] = 1;
        }
    }
    for(int i = N-2; i > 0; i--){
        for(int j = 0; j < M; j++){
            graph[0][j].clear();
            graph[1][j].clear();
            vis[0][j] = vis[1][j] = 0;
        }
        int cur = 0;
        for(int j = 0; j < M; j++){
            if(s[i][j] == '#') cur = j+1;
            else par[i][j] = cur;
        }
        for(int j = 0; j < M; j++){
            if(s[i][j] == '#' || s[i+1][j] == '#') continue;
            int u = par[i][j];
            int v = par[i+1][j];
            graph[0][u].push_back(v);
            graph[1][v].push_back(u);
        }
        for(int j = 0; j < M; j++){
            if(s[i][j] == '#' || vis[0][j]) continue;
            dfs(0, j, i, par[i][j]);
        }
        for(int j = 0; j < M; j++){
            if(s[i][j] == '#') continue;
            par[i][j] = par[i][par[i][j]];
        }
        for(int j = 0; j < M; j++){
            vis[1][j] = 0;
        }
        for(int j = 0; j < M; j++){
            if(s[i][j] == '#' || s[i+1][j] == '#') continue;
            int p0 = par[i][j];
            int p1 = par[i+1][j];
            if(vis[1][p1]) continue;
            vis[1][p1] = 1;
            ways[i][p0] = ways[i][p0] * ways[i+1][p1] % MOD;
            active[i+1][p1] = 0;
        }
        for(int j = 0; j < M; j++){
            if(s[i][j] == '#') continue;
            active[i][par[i][j]] = 1;
        }
        for(int j = 0; j < M; j++){
            if(j == par[i][j]) ways[i][j] = (ways[i][j] + 1) % MOD;
        }
    }
    int ans = 1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(active[i][j]){
                ans = ans * ways[i][j] % MOD;
            }
        }
    }
    moo << ans << endl;
}
