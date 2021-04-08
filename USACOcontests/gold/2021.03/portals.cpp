#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout

using namespace std;

int N, c[100000], p[100000][4], par[200000], sz[200000], srt[100000];

int find(int u){
    if(u == par[u]) return u;
    return (par[u] = find(par[u]));
}

bool un(int u, int v){
    u = find(u), v = find(v);
    if(u == v) return false;
    if(sz[u] < sz[v]) swap(u, v);
    par[v] = u;
    sz[u] += sz[v];
    return true;
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N;
    iota(par, par+2*N, 0);
    fill(sz, sz+2*N, 1);
    for(int i = 0; i < N; i++){
        eat >> c[i] >> p[i][0] >> p[i][1] >> p[i][2] >> p[i][3];
        p[i][0]--, p[i][1]--, p[i][2]--, p[i][3]--;
        un(p[i][0], p[i][1]);
        un(p[i][2], p[i][3]);
    }
    iota(srt, srt+N, 0);
    sort(srt, srt+N, [](int a, int b){
        return c[a] < c[b];
    });
    int ans = 0;
    for(int i = 0; i < N; i++){
        int id = srt[i];
        if(un(p[id][0], p[id][2])){
            ans += c[id];
        }
    }
    moo << ans << endl;
}
