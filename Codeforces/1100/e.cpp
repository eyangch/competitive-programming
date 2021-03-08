#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout

using namespace std;

int N, M, u[100000], v[100000], c[100000], deg[100000], loc[100000];
vector<int> graph[100000], topo;

bool works(int mid){
    for(int i = 0; i < N; i++) graph[i].clear();
    fill_n(deg, N, 0);
    for(int i = 0; i < M; i++){
        if(c[i] > mid){
            graph[u[i]-1].push_back(v[i]-1);
            deg[v[i]-1]++;
        }
    }
    queue<int> q;
    for(int i = 0; i < N; i++){
        if(deg[i] == 0) q.push(i);
    }
    topo.clear();
    while(!q.empty()){
        int id = q.front();
        q.pop();
        topo.push_back(id);
        for(int i : graph[id]){
            if(!--deg[i]) q.push(i);
        }
    }
    int sum = 0;
    for(int i = 0; i < N; i++) sum += deg[i];
    return (sum == 0);
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N >> M;
    for(int i = 0; i < M; i++){
        eat >> u[i] >> v[i] >> c[i];
    }
    int lo = 0, hi = 1e9, mid = 0, ans = 0;
    while(lo <= hi){
        mid = (lo + hi) / 2;
        if(works(mid)) ans = mid, hi = mid-1;
        else lo = mid+1;
    }
    works(ans);
    for(int i = 0; i < N; i++){
        loc[i] = N + i;
    }
    for(int i = 0; i < (int)topo.size(); i++){
        loc[topo[i]] = i;
    }
    vector<int> rv;
    for(int i = 0; i < M; i++){
        if(c[i] <= ans && loc[u[i]-1] > loc[v[i]-1]){
            rv.push_back(i+1);
        }
    }
    moo << ans << " " << rv.size() << endl;
    for(int i : rv) moo << i << " ";
    moo << endl;
}
