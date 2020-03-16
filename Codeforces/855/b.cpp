#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ll N, P, Q, R;
    cin >> N >> P >> Q >> R;
    ll a[N];
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    ll dp[N][3];
    dp[0][0] = P * a[0];
    dp[0][1] = dp[0][0] + Q * a[0];
    dp[0][2] = dp[0][1] + R * a[0];
    for(int i = 1; i < N; i++){
        dp[i][0] = max(P * a[i], dp[i-1][0]);
        dp[i][1] = max(dp[i][0] + Q * a[i], dp[i-1][1]);
        dp[i][2] = max(dp[i][1] + R * a[i], dp[i-1][2]);
    }
    cout << dp[N-1][2] << endl;
    return 0;
}
