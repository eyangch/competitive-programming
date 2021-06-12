#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, M;
vector<int> graph[100000];
vector<int> comp;
bool vis[100000];

int dfsc(int id){
    if(vis[id]) return 0;
    vis[id] = true;
    int sz = 1;
    for(int i : graph[id]){
        sz += dfsc(i);
    }
    return sz;
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N >> M;
        for(int i = 0; i < N; i++) graph[i].clear();
        fill(vis, vis+N, 0);
        for(int i = 0; i < M; i++){
            int u, v; eat >> u >> v;
            graph[u-1].push_back(v-1);
            graph[v-1].push_back(u-1);
        }
        comp.clear();
        for(int i = 0; i < N; i++){
            int sz = dfsc(i);
            if(sz != 0) comp.push_back(sz);
        }
        int c = comp.size();
        if(c == 1) moo << "LOSE" << endl;
        else if(c == 2) moo << "WIN" << endl;
        else{
            int oddc = 0;
            for(int i : comp){
                oddc += i % 2;
            }
            int edgeslft = c - 3;
            int want = !((N * (N-1) / 2 - M) % 2);
            int turns = edgeslft / 2;
            turns += (want == 0 && edgeslft % 2 == 1);
            turns += (want == 1 && oddc == c);
            int delodd = (oddc - turns * 2 < 2);
            if(delodd != want) moo << "WIN" << endl;
            else moo << "LOSE" << endl;
        }
    }
}
