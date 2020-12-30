#include <bits/stdc++.h>

using namespace std;

int N, K;
int b[15][15];

int score(int btmsk){
    int alr = 0;
    for(int i = 0; i < N; i++){
        if(btmsk & (1<<i)) alr++;
    }
    int mx[15][15];
    fill(mx[0], mx[N-1]+N, 1e9);
    int mxsums[15];
    fill(mxsums, mxsums+N, 1e9);
    vector<int> sums[15];
    for(int i = 0; i < N; i++){
        vector<int> csum;
        csum.push_back(0);
        for(int j = 0; j < N; j++){
            csum[csum.size()-1] += b[i][j]; 
            if(btmsk & (1<<j)){
                csum.push_back(0);
            }
        }
        sums[i] = csum;
        if(i > 0){
            for(int j = 0; j < alr+1; j++){
                sums[i][j] += sums[i-1][j];
            }
        }
        mxsums[i] = 0;
        for(int j : sums[i]){
            mxsums[i] = max(mxsums[i], j);
        }
        for(int j = 0; j < i; j++){
            mx[j][i] = 0;
            for(int k = 0; k < alr+1; k++){
                mx[j][i] = max(mx[j][i], sums[i][k] - sums[j][k]);
            }
        }
    }
    int dp[15][15];
    fill(dp[0], dp[N-1]+N, 1e9);
    for(int i = 0; i < N; i++){
        dp[i][0] = mxsums[i];
        for(int j = 1; j <= i; j++){
            for(int k = 0; k < i; k++){
                dp[i][j] = min(dp[i][j], max(dp[k][j-1], mx[k][i]));
            }
        }
    }
    if(K - alr >= N || K - alr < 0) return 1e9;
    return dp[N-1][K-alr];
}

int32_t main(){
    freopen("partition.in", "r", stdin);
    freopen("partition.out", "w", stdout);
    scanf("%d%d", &N, &K);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &b[i][j]);
        }
    }
    int ans = 1e9;
    for(int i = 0; i < (1<<(N-1)); i++){
        ans = min(ans, score(i));
    }
    printf("%d\n", ans);
}
