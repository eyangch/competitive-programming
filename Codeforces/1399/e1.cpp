#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout
#define int long long
#define f first
#define s second

using namespace std;
typedef pair<int, int> pii;

struct edge{
    int u, v, w, use;
};

int T, N, S;
vector<int> graph[100000];
edge e[100000];
int lc[100000];
priority_queue<pii> pq;

int dfs(int id, int par){
    int ret = 0;
    for(int i : graph[id]){
        if(i == par) continue;
        ret += dfs(i, id);
    }
    return (lc[id] = max(ret, 1LL));
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N >> S;
        for(int i = 0; i < N; i++) graph[i].clear();
        for(int i = 0; i < N-1; i++){
            eat >> e[i].u >> e[i].v >> e[i].w;
            e[i].u--, e[i].v--;
            graph[e[i].u].push_back(e[i].v);
            graph[e[i].v].push_back(e[i].u);
        }
        dfs(0, -1);
        pq = priority_queue<pii>();
        int w = 0;
        for(int i = 0; i < N-1; i++){
            int sub = e[i].w - e[i].w / 2;
            e[i].use = min(lc[e[i].u], lc[e[i].v]);
            pq.push({sub * e[i].use, i});
            w += e[i].w * e[i].use;
        }
        int ans = 0;
        while(w > S){
            int sub = pq.top().f, id = pq.top().s;
            pq.pop();
            w -= sub;
            ans++;
            e[id].w /= 2;
            int x = e[id].w - e[id].w / 2;
            pq.push({x * e[id].use, id});
        }
        moo << ans << endl;
    }
}
