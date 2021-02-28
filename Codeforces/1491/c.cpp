#include <bits/stdc++.h>
#define endl "\n"
#define int long long

using namespace std;

int T, N, s[5000], dp[5001];

int32_t main(){
    cin.tie(0) -> sync_with_stdio(false);
    cin >> T;
    while(T--){
        cin >> N;
        int ans = 0;
        for(int i = 0; i < N; i++){
            cin >> s[i];
            dp[i] = 0;
        }
        for(int i = 0; i < N; i++){
            ans -= min(s[i]-1, dp[i]);
            dp[i+1] += max(0LL, dp[i] - (s[i]-1));
            ans += max(0LL, s[i] - max(1LL, N - i-1));
            s[i] = min(s[i], max(1LL, N-i-1));
            for(int j = i+2; j < N && j - i <= s[i]; j++){
                dp[j]++;
                ans++;
            }
        }
        cout << ans << endl;
    }
}
