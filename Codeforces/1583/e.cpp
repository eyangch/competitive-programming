#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, M, Q;
vector<int> graph[300000], tg[300000];
int a[300000], b[300000], oc[300000];
bool vis[300000];
int d[300000];

void dfs(int id){
    for(int i : graph[id]){
        if(vis[i]) continue;
        vis[i] = true;
        tg[id].push_back(i), tg[i].push_back(id);
        dfs(i);
    }
}

void dfsd(int id, int par, int di){
    d[id] = di;
    for(int i : tg[id]){
        if(i == par) continue;
        dfsd(i, id, di+1);
    }
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N >> M;
    for(int i = 0; i < M; i++){
        int u, v; eat >> u >> v;
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);
    }
    eat >> Q;
    for(int i = 0; i < Q; i++){
        eat >> a[i] >> b[i];
        a[i]--, b[i]--;
        oc[a[i]]++, oc[b[i]]++;
    }
    int bad = 0;
    for(int i = 0; i < N; i++){
        bad += oc[i] % 2;
    }
    if(bad){
        moo << "NO" << endl << bad/2 << endl;
        return 0;
    }
    moo << "YES" << endl;
    vis[0] = true;
    dfs(0);
    for(int i = 0; i < Q; i++){
        dfsd(b[i], -1, 0);
        vector<int> ans;
        int v = a[i];
        ans.push_back(v);
        while(v != b[i]){
            for(int j : tg[v]){
                if(d[j] < d[v]) v = j;
            }
            ans.push_back(v);
        }
        moo << ans.size() << endl;
        for(int j : ans) moo << j+1 << ' ';
        moo << endl;
    }
}
