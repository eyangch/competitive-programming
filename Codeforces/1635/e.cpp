#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long
#define fi first
#define se second

using namespace std;

int N, M, O[200000], Q2[200000], Q3[200000], din[200000], tcnt, ans[200000];
bool Q1[200000];
vector<int> ori[200000], topo[200000];

void add_edge(int x, int y, bool s){
    if(s ^ (O[x] == 2)) swap(x, y);
    topo[x].push_back(y);
}

bool dfs(int v, int o){
    if(O[v] > 0){
        if(O[v] != o) return false;
        return true;
    }
    O[v] = o;
    bool ret = true;
    for(int i : ori[v]){
        ret &= dfs(i, 3-o);
    }
    return ret;
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N >> M;
    for(int i = 0; i < M; i++){
        int t, x, y;
        eat >> t >> x >> y;
        x--, y--;
        Q1[i] = t-1;
        Q2[i] = x;
        Q3[i] = y;
        ori[x].push_back(y);
        ori[y].push_back(x);
    }
    for(int i = 0; i < N; i++){
        if(O[i] > 0) continue;
        if(!dfs(i, 1)){
            moo << "NO" << endl;
            return 0;
        }
    }
    for(int i = 0; i < M; i++){
        add_edge(Q2[i], Q3[i], Q1[i]);
    }
    for(int i = 0; i < N; i++){
        for(int j : topo[i]) din[j]++;
    }
    queue<int> q;
    for(int i = 0; i < N; i++){
        if(din[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int v = q.front();
        q.pop();
        ans[v] = ++tcnt;
        for(int i : topo[v]){
            if(--din[i] == 0) q.push(i);
        }
    }
    if(*min_element(ans, ans+N) == 0){
        moo << "NO" << endl;
        return 0;
    }
    moo << "YES" << endl;
    for(int i = 0; i < N; i++){
        moo << (O[i] == 1 ? 'L' : 'R') << ' ' << ans[i] << endl;
    }
}
