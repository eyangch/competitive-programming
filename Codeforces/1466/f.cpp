#include <bits/stdc++.h>
#define endl "\n"
#define moo cout

using namespace std;

const int MOD = 1e9+7;
int N, M, par[500000], sz[500000];

int find(int u){
    if(par[u] == u) return u;
    return (par[u] = find(par[u]));
}

void un(int u, int v){
    u = find(u), v = find(v);
    if(u == v) return;
    if(sz[u] > sz[v]) swap(u, v);
    sz[v] += sz[u];
    par[u] = v;
}

int32_t main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin >> N >> M;
    fill(sz, sz+M+1, 1);
    iota(par, par+M+1, 0);
    vector<int> s;
    for(int i = 0; i < N; i++){
        int k; cin >> k;
        int a, b = M+1; cin >> a;
        if(k == 2) cin >> b;
        if(find(--a) != find(--b)){
            un(a, b);
            s.push_back(i);
        }
    }
    int ans = 1;
    for(int i = 0; i < (int)s.size(); i++) ans = ans * 2 % MOD;
    moo << ans << " " << s.size() << endl;
    for(int i : s){
        moo << i+1 << " ";
    }
    moo << endl;
}
