#include <bits/stdc++.h>

using namespace std;

struct pair_hash{
    size_t operator () (pair<int, int> const &p) const{
        return (hash<int>()(p.first) ^ hash<int>()(p.second));
    }
};

int N, M, K;
unordered_set<pair<int, int>, pair_hash> broken;
pair<int, int> fix[200000], conn[200000];
int par[100000], sz[100000];
int components, ans[200000];

int find(int u){
    if(u == par[u]){
        return u;
    }
    par[u] = find(par[u]);
    return par[u];
}

void un(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v){
        return;
    }
    components--;
    if(sz[u] < sz[v]) swap(u, v);
    par[v] = u;
    sz[u] += sz[v];
}

signed main(){
    cin >> N >> M >> K;
    for(int i = 0; i < M; i++){
        cin >> conn[i].first >> conn[i].second;
        if(--conn[i].first > --conn[i].second) swap(conn[i].first, conn[i].second);
    }
    for(int i = 0; i < K; i++){
        cin >> fix[i].first >> fix[i].second;
        if(--fix[i].first > --fix[i].second) swap(fix[i].first, fix[i].second);
        broken.insert(fix[i]);
    }
    components = N;
    iota(par, par+N, 0);
    fill(sz, sz+N, 1);
    for(int i = 0; i < M; i++){
        if(!broken.count(conn[i])){
            un(conn[i].first, conn[i].second);
        }
    }
    for(int i = K-1; i >= 0; i--){
        ans[i] = components;
        un(fix[i].first, fix[i].second);
    }
    for(int i = 0; i < K; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}
