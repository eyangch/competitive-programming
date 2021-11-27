#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long
#define f first
#define s second

using namespace std;

int MOD = 1e9+7;
int T, N, K;
vector<int> graph[100];
vector<int> subtl;
int dp[101][101];

void dfs(int i, int d, int p){
    if((int)subtl.size() == d) subtl.push_back(0);
    subtl[d]++;
    for(int j : graph[i]){
        if(j == p) continue;
        dfs(j, d+1, i);
    }
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N >> K;
        for(int i = 0; i < N; i++) graph[i].clear();
        for(int i = 0; i < N-1; i++){
            int u, v; eat >> u >> v;
            graph[u-1].push_back(v-1);
            graph[v-1].push_back(u-1);
        }
        if(K == 2){
            moo << N * (N-1) / 2 << endl;
            continue;
        }
        int ans = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < 101; j++){
                dp[j][0] = 1;
                for(int k = 1; k < 101; k++){
                    dp[j][k] = -1e17;
                }
            }
            for(int j : graph[i]){
                subtl.clear();
                dfs(j, 0, i);
                for(int k = 0; k < (int)subtl.size(); k++){
                    for(int l = K; l >= 0; l--){
                        if(dp[k][l] == -1e17) continue;
                        if(dp[k][l+1] == -1e17) dp[k][l+1] = 0;
                        dp[k][l+1] = (dp[k][l+1] + dp[k][l] * subtl[k] % MOD) % MOD;
                    }
                }
            }
            for(int j = 0; j < 101; j++){
                ans = (ans + max(0LL, dp[j][K])) % MOD;
            }
        }
        moo << ans << endl;
    }
}
