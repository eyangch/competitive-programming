/*
ID: sireric1
LANG: C++11
TASK: milk6
*/

#include <bits/stdc++.h>

using namespace std;

int N, M;
int g[32][32];
pair<pair<int, int>, pair<int, int>> edges[1000];

int maxflow(){
    bool vis[32];
    int cap[32][32];
    int prevnode[32];
    int flow[32];
    int tflow = 0;
    copy(g[0], g[N-1]+N, cap[0]);
    while(true){
        for(int i = 0; i < N; i++){
            prevnode[i] = -1;
            flow[i] = 0;
            vis[i] = false;
        }
        flow[0] = 1e8;
        int maxflow, maxloc = -1;
        while(true){
            maxflow = 0;
            maxloc = -1;
            for(int i = 0; i < N; i++){
                if(flow[i] > maxflow && !vis[i]){
                    maxflow = flow[i];
                    maxloc = i;
                }
            }
            if(maxloc == -1 || maxloc == N-1){
                break;
            }
            vis[maxloc] = true;
            for(int i = 0; i < N; i++){
                if(flow[i] < min(maxflow, cap[maxloc][i])){
                    prevnode[i] = maxloc;
                    flow[i] = min(maxflow, cap[maxloc][i]);
                }
            }
        }
        if(maxloc == -1){
            break;
        }
        tflow += flow[N-1];
        int currnode = N-1;
        while(currnode != 0){
            int nxtnode = prevnode[currnode];
            cap[nxtnode][currnode] -= flow[N-1];
            cap[currnode][nxtnode] += flow[N-1];
            currnode = nxtnode;
        }
    }
    return tflow;
}

int32_t main(){
    freopen("milk6.in", "r", stdin);
    freopen("milk6.out", "w", stdout);
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int s, e, c; cin >> s >> e >> c;
        g[s-1][e-1] += c;
        edges[i] = {{-c, i}, {s-1, e-1}};
    }
    int mxtf = maxflow();
    cout << mxtf;
    vector<int> ans;
    sort(edges, edges+M);
    int rmv = 0;
    for(int i = 0; i < M; i++){
        int s = edges[i].second.first, e = edges[i].second.second, c = -edges[i].first.first, id = edges[i].first.second;
        g[s][e] -= c;
        int mxf = maxflow();
        if(mxf + c == mxtf){
            ans.push_back(id);
            g[s][e] += c;
            rmv += c;
            if(rmv == mxtf) break;
        }else{
            g[s][e] += c;
        }
    }
    sort(ans.begin(), ans.end());
    cout << " " << ans.size() << endl;
    for(int i : ans){
        cout << i+1 << endl;
    }
}
