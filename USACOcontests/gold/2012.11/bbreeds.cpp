#include <bits/stdc++.h>

using namespace std;

int N;
string c;
int dp[1000][1001];

int sdif(int id){
    return 2*(c[id] == '(')-1;
}

signed main(){
    freopen("bbreeds.in", "r", stdin);
    freopen("bbreeds.out", "w", stdout);
    cin >> c;
    N = c.size();
    dp[0][1] = (c[0] == '(');
    int sum = sdif(0);
    for(int i = 0; i < N-1; i++){
        sum += sdif(i+1);
        for(int j = 0; j <= i+1; j++){
            dp[i][j] %= 2012;
            if(j+sdif(i+1) >= 0){
                dp[i+1][j+sdif(i+1)] += dp[i][j];
            }
            if(sum - j >= 0){
                dp[i+1][j] += dp[i][j];
            }
        }
    }
    cout << dp[N-1][0] * 2 % 2012 << endl;
}
