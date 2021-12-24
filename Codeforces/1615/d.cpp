#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long
#define fi first
#define se second

using namespace std;

int T, N, M, X[200000], Y[200000], V[200000], aV[200000], A[200000], B[200000], P[200000], r[200000];
vector<pair<int, int>> graph[200000];
bool sad;

void dfs(int id, int xv=0){
    if(sad) return;
    if(r[id] != -1 && r[id] != xv){
        sad = true;
        return;
    }
    if(r[id] != -1) return;
    r[id] = xv;
    for(pair<int, int> i : graph[id]){
        dfs(i.fi, xv^i.se);
        if(sad) return;
    }
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N >> M;
        sad = false;
        for(int i = 0; i < N; i++){
            graph[i].clear();
        }
        for(int i = 0; i < N-1; i++){
            eat >> X[i] >> Y[i] >> V[i];
            X[i]--, Y[i]--;
            if(V[i] != -1){
                aV[i] = __builtin_popcount(V[i]) % 2;
                graph[X[i]].push_back({Y[i], aV[i]});
                graph[Y[i]].push_back({X[i], aV[i]});
            }
        }
        for(int i = 0; i < M; i++){
            eat >> A[i] >> B[i] >> P[i];
            A[i]--, B[i]--;
            graph[A[i]].push_back({B[i], P[i]});
            graph[B[i]].push_back({A[i], P[i]});
        }
        fill(r, r+N, -1);
        for(int i = 0; i < N; i++){
            if(r[i] == -1) dfs(i);
        }
        if(sad){
            moo << "NO" << endl;
        }else{
            moo << "YES" << endl;
            for(int i = 0; i < N-1; i++){
                moo << X[i]+1 << ' ' << Y[i]+1 << ' ' << (V[i] == -1 ? r[X[i]] ^ r[Y[i]] : V[i]) << endl;
            }
        }
    }
}
