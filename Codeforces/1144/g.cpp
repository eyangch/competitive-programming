#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, a[200000];
int dp[200000][2], p[200000][2], ans[200000];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N;
    for(int i = 0; i < N; i++){
        eat >> a[i];
    }
    dp[0][0] = 1e9;
    dp[0][1] = -1;
    for(int i = 1; i < N; i++){
        dp[i][0] = -1;
        if(a[i] > a[i-1]){
            dp[i][0] = dp[i-1][0];
            p[i][0] = 0;
        }
        if(a[i] > dp[i-1][1] && a[i-1] > dp[i][0]){
            dp[i][0] = a[i-1];
            p[i][0] = 1;
        }
        dp[i][1] = 1e9;
        if(a[i] < a[i-1]){
            dp[i][1] = dp[i-1][1];
            p[i][1] = 1;
        }
        if(a[i] < dp[i-1][0] && a[i-1] < dp[i][1]){
            dp[i][1] = a[i-1];
            p[i][1] = 0;
        }
    }
    int c = 0;
    if(dp[N-1][0] == -1) c = 1;
    if(c == 1 && dp[N-1][1] == 1e9){
        moo << "NO" << endl;
        return 0;
    }
    moo << "YES" << endl;
    for(int i = N-1; i >= 0; i--){
        ans[i] = c;
        c = p[i][c];
    }
    for(int i = 0; i < N; i++){
        moo << ans[i] << ' ';
    }
    moo << endl;
}
