#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int MOD = 998244353;
int N, a[500], dp[500][2000];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N;
    for(int i = 0; i < N; i++){
        char x; eat >> x;
        if(x == '-') a[i] = -1;
        else{
            int y; eat >> y;
            a[i] = y;
        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        if(a[i] == -1) continue;
        vector<int> v;
        for(int j = 0; j < N; j++){
            if(a[j] == -1) v.push_back(-1);
            else if(a[j] < a[i]) v.push_back(1);
            else if(a[j] > a[i]) v.push_back(0);
            else if(j < i) v.push_back(1);
            else if(j > i) v.push_back(0);
            else v.push_back(0);
        }
        dp[0][1000] = dp[0][1000+max(0LL, v[0])] = 0;
        if(i != 0) dp[0][1000]++, dp[0][1000+max(0LL, v[0])]++;
        else dp[0][1000] = 1;
        int mn = 1000, mx = max(1000LL, 1000+v[0]);
        for(int j = 1; j < N; j++){
            for(int k = mn; k <= mx; k++){
                dp[j][k] = dp[j][k+v[j]] = 0;
            }
            if(j == i){
                for(int k = mn; k <= mx; k++){
                    dp[j][k] = dp[j-1][k];
                }
                continue;
            }
            int nmn = mn, nmx = mx;
            for(int k = mn; k <= mx; k++){
                nmx = max(nmx, k+v[j]);
                if(j > i) dp[j][k+v[j]] += dp[j-1][k];
                if(j < i) dp[j][max(1000LL, k+v[j])] += dp[j-1][k];
                dp[j][k] += dp[j-1][k];
            }
            mn = nmn, mx = nmx;
            for(int k = mn; k <= mx; k++){
                while(dp[j][k] > MOD) dp[j][k] -= MOD;
            }
        }
        for(int j = 1000; j <= mx; j++){
            ans += a[i] * dp[N-1][j];
            ans %= MOD;
        }
    }
    moo << ans << endl;
}
