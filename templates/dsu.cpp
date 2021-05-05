#include <bits/stdc++.h>

using namespace std;

int find(int u){
    if(par[u] == u) return u;
    return (par[u] = find(par[u]);
}

void un(int u, int v){
    u = find(u), v = find(v);
    if(u == v) return;
    if(sz[u] > sz[v]) swap(u, v);
    par[u] = v;
    sz[v] += sz[u];
}
