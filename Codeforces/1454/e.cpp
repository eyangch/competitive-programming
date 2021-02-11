#include <bits/stdc++.h>
#define int long long
#define endl "\n"

using namespace std;

int T, N;
vector<int> graph[200000], cur;
bool vis[200000], cycle[200000], found_cycle = false;

int dfs(int id, int par){
    int ans = 1;
    for(int i : graph[id]){
        if(i == par || cycle[i]) continue;
        ans += dfs(i, id);
    }
    return ans;
}

void cyclef(int id, int par){
    if(vis[id]){
        for(int i = (int)cur.size() - 1; i >= 0; i--){
            cycle[cur[i]] = true;
            if(cur[i] == id) break;
        }
        found_cycle = true;
        return;
    }
    cur.push_back(id);
    vis[id] = true;
    for(int i : graph[id]){
        if(i == par) continue;
        cyclef(i, id);
        if(found_cycle) return;
    }
    vis[id] = false;
    cur.pop_back();
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 0; i < N; i++){
            graph[i].clear();
        }
        found_cycle = false;
        fill(vis, vis+N, false);
        fill(cycle, cycle+N, false);
        cur.clear();
        for(int i = 0; i < N; i++){
            int u, v; cin >> u >> v;
            graph[u-1].push_back(v-1);
            graph[v-1].push_back(u-1);
        }
        cyclef(0, -1);
        int ans = 0;
        for(int i = 0; i < N; i++){
            if(cycle[i]){
                int nodes = dfs(i, -1);
                ans += (nodes * (nodes - 1)) + (2 * (N - nodes) * nodes);
            }
        }
        cout << ans / 2 << endl;
    }
}
