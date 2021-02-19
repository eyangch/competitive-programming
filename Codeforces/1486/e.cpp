#include <bits/stdc++.h>
#define endl "\n"
#define fi first
#define se second

using namespace std;
typedef pair<int, int> pii;

int N, M, di[100000], mn[100000];
vector<pii> graph[100000];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int v, u, w; cin >> v >> u >> w;
        graph[v-1].push_back({u-1, w});
        graph[u-1].push_back({v-1, w});
    }
    fill(mn, mn+N, 1e9);
    fill(di, di+N, 1e9);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    di[0] = 0;
    pq.push({0, 0});
    while(!pq.empty()){
        int id = pq.top().se, d = pq.top().fi;
        pq.pop();
        if(di[id] != d) continue;
        for(pii i : graph[id]){
            if(mn[i.fi] <= i.se) continue;
            mn[i.fi] = i.se;
            for(pii j : graph[i.fi]){
                int nd = d + (i.se+j.se) * (i.se+j.se);
                if(di[j.fi] > nd){
                    di[j.fi] = nd;
                    pq.push({nd, j.fi});
                }
            }
        }
    }
    for(int i = 0; i < N; i++){
        cout << (di[i] < 1e9 ? di[i] : -1) << " ";
    }
    cout << endl;
}
