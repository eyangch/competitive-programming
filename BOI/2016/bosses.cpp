#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
#define f first
#define s second

int N;
bool vis[5000];
vector<int> graph[5000];
vector<int> tree[5000];

pii dfs(int id){
    int res = 1;
    int total = 0;
    for(int i : tree[id]){
        pii x = dfs(i);
        res += x.f;
        total += x.s;
    }
    return pii(res, res + total);
}

signed main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        int k; cin >> k;
        for(int j = 0; j < k; j++){
            int x; cin >> x;
            graph[x-1].push_back(i);
        }
    }
    int ans = 1e9;
    for(int i = 0; i < N; i++){
        fill(vis, vis+N, false);
        for(int j = 0; j < N; j++){
            tree[j].clear();
        }
        queue<pii> q;
        q.push(pii(-1, i));
        int e = 0;
        while(!q.empty()){
            int id = q.front().s, pv = q.front().f;
            q.pop();
            if(vis[id]) continue;
            vis[id] = true;
            if(pv != -1){
                tree[pv].push_back(id);
                e++;
            }
            for(int j : graph[id]){
                q.push(pii(id, j));
            }
        }
        if(e == N-1){
            ans = min(ans, dfs(i).s);
        }
    }
    cout << ans << endl;
}
