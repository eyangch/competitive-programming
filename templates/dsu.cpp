#include <bits/stdc++.h>

using namespace std;

int find(int u){
    if(par[u] == u){
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
    if(sz[u] > sz[v]){
        swap(u, v);
    }
    par[u] = v;
    sz[v] += sz[u];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    return 0;
}
