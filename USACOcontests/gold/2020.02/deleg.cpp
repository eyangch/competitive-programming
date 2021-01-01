#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> graph[100000];
vector<int> ord;
int parent[100000];
int dp[100000];
int cmb[100000];

void dfs(int id, int par){
    for(int i : graph[id]){
        if(i != par) dfs(i, id);
    }
    parent[id] = par;
    ord.push_back(id);
}

bool solve(int len){
    for(int id : ord){
        int active = 0;
        for(int i : graph[id]){
            if(i == parent[id]) continue;
            int nv = dp[i];
            if(nv < len-1){
                if(cmb[len - nv - 1] > 0){
                    cmb[len - nv - 1]--;
                    active--;
                }else{
                    cmb[nv + 1]++;
                    active++;
                }
            }
        }
        int ans = 0;
        for(int i : graph[id]){
            if(i == parent[id]) continue;
            if(cmb[dp[i]+1]) ans = dp[i]+1;
            cmb[dp[i]+1] = 0;
        }
        if(active > 1){
            return false;
        }
        if(active == 0){
            dp[id] = 0;
        }else{
            dp[id] = ans % len;
        }
    }
    if(dp[0] == 0) return true;
    return false;
}

int32_t main(){
    freopen("deleg.in", "r", stdin);
    freopen("deleg.out", "w", stdout);
    scanf("%d", &N);
    for(int i = 0; i < N-1; i++){
        int u, v; scanf("%d%d", &u, &v);
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);
    }
    dfs(0, 0);
    for(int i = 1; i < N; i++){
        bool ok = false;
        if((N-1) % i == 0){
            ok = (solve(i));
        }
        printf("%d", ok);
    }
    printf("\n");
}
