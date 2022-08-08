#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, A[300000], dp[20], cdp[20];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N;
	for(int i = 0; i < N; i++){
		eat >> A[i];
	}
	fill(dp, dp+20, 1e15);
	dp[0] = 0;
	for(int i = N-1; A[i] > -1; i--){
		fill(cdp, cdp+20, 1e15);
		for(int j = 0; j < 20; j++){
			int x = N/(1<<j);
			if(i >= x){
				cdp[j] = dp[j];
			}
			if(j > 0){
				cdp[j] = min(cdp[j], dp[j-1] + A[i]);
			}
		}
		copy(cdp, cdp+20, dp);
	}
	int ans = *min_element(dp, dp+20);
	moo << ans << endl;
}