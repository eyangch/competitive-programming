#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int find(int u, int (&par)[100000]){
    if(par[u] == u){
        return u;
    }
    par[u] = find(par[u], par);
    return par[u];
}

void un(int u, int v, int (&par)[100000], int (&sz)[100000]){
    u = find(u, par);
    v = find(v, par);
    if(u == v){
        return;
    }
    if(sz[u] < sz[v]){
        par[u] = v;
        sz[v] += sz[u];
    }else{
        par[v] = u;
        sz[u] += sz[v];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    return 0;
}
