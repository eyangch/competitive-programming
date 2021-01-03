/*
ID: sireric1
LANG: C++11
TASK: theme
*/

#include <bits/stdc++.h>

using namespace std;

int N;
int dif[5000];
int dp[5000];

int32_t main(){
    freopen("theme.in", "r", stdin);
    freopen("theme.out", "w", stdout);
    cin >> N; N--;
    int prev; cin >> prev;
    for(int i = 0; i < N; i++){
        int x; cin >> x;
        dif[i] = x - prev;
        prev = x;
    }
    fill(dp, dp+N, 0);
    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = N-1; j > i+1; j--){
            if(dif[i] == dif[j] && dp[j-1] < (j-i-1)){
                dp[j] = dp[j-1]+1;
                ans = max(ans, dp[j]);
            }else{
                dp[j] = 0;
            }
        }
    }
    cout << (ans < 4 ? 0 : ans+1) << endl;
}
