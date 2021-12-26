#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long
#define fi first
#define se second

using namespace std;

int N, K;
vector<int> graph[200000];
int d[200000], o[200000], p[200000], f[200000];
bool vis[200000];

void dfs(int id=0, int par=0, int di=0){
    int ch = 0;
    p[id] = par;
    for(int i : graph[id]){
        if(i == par) continue;
        ch++;
        dfs(i, id, di+1);
    }
    if(!ch) d[id] = di;
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N >> K;
    for(int i = 0; i < N-1; i++){
        int u, v; eat >> u >> v;
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);
    }
    dfs();
    iota(o, o+N, 0);
    sort(o, o+N, [](int a, int b){
        return d[a] > d[b];
    });
    for(int i = 0; i < N; i++){
        if(d[o[i]] == 0) break;
        int cur = o[i];
        while(!vis[cur]){
            vis[cur] = true;
            cur = p[cur];
            f[o[i]]++;
        }
    }
    sort(o, o+N, [](int a, int b){
        return f[a] > f[b];
    });
    int ans = -1e15, r = 0, b = N;
    for(int i = 0; i < K; i++){
        b -= f[o[i]], r++;
        ans = max(ans, (N - r - min(N/2, b)) * (r - min(N/2, b)));
    }
    moo << ans << endl;
}
