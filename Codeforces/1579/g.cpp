#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long
#define f first
#define s second

using namespace std;

int T, N, a[10000], dp[2001], cdp[2001];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N;
        for(int i = 0; i < N; i++){
            eat >> a[i];
        }
        fill(dp, dp+2001, 1e17);
        dp[0] = 0;
        for(int i = 0; i < N; i++){
            fill(cdp, cdp+2001, 1e17);
            for(int j = 0; j < 2001; j++){
                if(dp[j] == 1e17) continue;
                if(j + a[i] < 2001) cdp[j+a[i]] = min(cdp[j+a[i]], max(dp[j], j+a[i]));
                if(j - a[i] >= 0) cdp[j-a[i]] = min(cdp[j-a[i]], dp[j]);
                else cdp[0] = min(cdp[0], dp[j] + a[i] - j);
            }
            copy(cdp, cdp+2001, dp);
        }
        moo << *min_element(dp, dp+2001) << endl;
    }
}
