#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> obs[50000];

vector<int> solve(int X){
    vector<int> dag[100000];
    int deg[100000];
    fill(deg, deg+N, 0);
    for(int i = 0; i < X; i++){
        for(int j = 1; j < (int)obs[i].size(); j++){
            dag[obs[i][j-1]].push_back(obs[i][j]);
            deg[obs[i][j]]++;
        }
    }
    vector<int> ret;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < N; i++){
        if(!deg[i]){
            pq.push(i);
        }
    }
    while(!pq.empty()){
        int id = pq.top();
        pq.pop();
        ret.push_back(id);
        for(int i : dag[id]){
            if(!(--deg[i])){
                pq.push(i);
            }
        }
    }
    return ret;
}

int32_t main(){
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);
    scanf("%d%d", &N, &M);
    for(int i = 0; i < M; i++){
        int m; scanf("%d", &m);
        for(int j = 0; j < m; j++){
            int x; scanf("%d", &x);
            obs[i].push_back(x-1);
        }
    }
    int lo = 0, hi = M, mid = 0;
    while(lo < hi){
        mid = (lo + (hi-lo)/2);
        if((int)solve(mid).size() < N){
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }
    while((int)solve(mid).size() == N) mid++;
    while((int)solve(mid).size() < N) mid--;
    vector<int> ans = solve(mid);
    for(int i = 0; i < N; i++){
        printf((i == N-1 ? "%d\n" : "%d "), ans[i]+1);
    }
}
