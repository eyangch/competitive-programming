#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, A[5000], f[5000], dp[5000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N;
		for(int i = 0; i < N; i++){
			eat >> A[i];
			A[i]--;
		}
		fill(dp, dp+N, -1e9);
		dp[0] = 1;
		for(int i = 1; i < N; i++){
			fill(f, f+N, 0);
			int mf = 0;
			for(int j = i-1; j >= 0; j--){
				if((i - j) % 2 == 1 && mf <= (i-j-1)/2 && A[j] == A[i]){
					dp[i] = max(dp[i], dp[j]+1);
				}
				mf = max(mf, ++f[A[j]]);
			}
			if(mf <= i/2 && i % 2 == 0) dp[i] = max(dp[i], 1LL);
		}
		int ans = 0;
		fill(f, f+N, 0);
		int cmf = 0;
		for(int i = N-1; i >= 0; i--){
			if((N - i) % 2 == 1 && cmf <= (N-i-1)/2){
				ans = max(ans, dp[i]);
			}
			cmf = max(cmf, ++f[A[i]]);
		}
		moo << ans << endl;
	}
}