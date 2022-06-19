#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, b[200000], p[200000], rt, pt, ans[200000], sum[200000], g[200000], msum = 0;
bool vis[200000];

/*void dfs(int i, int csum){
    for(int j = 0; j < g[i]; j++){
        int v = p[++pt];
        if(b[v] != i){
            rt = -1;
            return;
        }
        int c = msum - csum + 1;
        ans[v] = c;
        msum = csum + c;
        dfs(v, csum + c);
        if(rt == -1) return;
    }
}*/

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N;
        for(int i = 0; i < N; i++) g[i] = sum[i] = vis[i] = 0;
        for(int i = 0; i < N; i++){
            eat >> b[i];
            b[i]--;
            if(b[i] == i){
                rt = i;
                continue;
            }
            g[b[i]]++;
        }
        for(int i = 0; i < N; i++){
            eat >> p[i];
            p[i]--;
        }
        pt = 0;
        if(p[0] != rt){
            moo << -1 << endl;
            continue;
        }
        msum = 0;
        ans[rt] = 0;
        vis[rt] = 1;
        // dfs(rt, 0);
        for(int i = 1; i < N; i++){
            int v = p[i];
            if(!vis[b[v]]){
                rt = -1;
                break;
            }
            int c = msum - sum[b[v]] + 1;
            msum = sum[b[v]] + c;
            ans[v] = c;
            sum[v] = msum;
            vis[v] = true;
        }
        if(rt == -1){
            moo << -1 << endl;
        }else{
            for(int i = 0; i < N; i++){
                moo << ans[i] << ' ';
            }
            moo << endl;
        }
    }
}
