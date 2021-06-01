#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, M, ans[100001];
bool dp[100001];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N >> M;
    dp[0] = true;
    fill(ans, ans+M+1, -1);
    for(int i = 0; i < N; i++){
        int t, x, y; eat >> t >> x >> y;
        if(t == 1){
            int add = (x+99999) / 100000;
            for(int j = M-1; j >= 0; j--){
                if(dp[j]){
                    int cur = j;
                    for(int k = 0; k < y; k++){
                        cur += add;
                        if(cur > M || dp[cur]) break;
                        dp[cur] = true;
                    }
                }
            }
        }else{
            for(int j = M; j >= 0; j--){
                if(dp[j]){
                    int cur = j;
                    for(int k = 0; k < y; k++){
                        cur = (cur * x + 99999) / 100000;
                        if(cur > M || dp[cur]) break;
                        dp[cur] = true;
                    }
                }
            }
        }
        for(int j = 0; j <= M; j++){
            if(dp[j] && ans[j] == -1) ans[j] = i+1;
        }
    }
    for(int i = 1; i <= M; i++){
        moo << ans[i] << " ";
    }
    moo << endl;
}
