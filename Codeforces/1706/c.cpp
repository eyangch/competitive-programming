#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, H[100000], dp[2][100000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N;
		for(int i = 0; i < N; i++){
			eat >> H[i];
		}
		int ans = 1e15;
		/*for(int pass = 0; pass < 2; pass++){
			int cans = 0;
			for(int i = 1; i < N-1; i += 2){
				int th = max(H[i-1], H[i+1]) + 1;
				if(th > H[i]){
					cans += th - H[i];
				}
			}
			ans = min(ans, cans);
			if(N & 1) break;
			for(int i = 0; i < N-1; i++){
				swap(H[i], H[i+1]);
			}
			N--;
		}*/
		for(int i = 0; i < N; i++){
			dp[0][i] = 0, dp[1][i] = 0;
		}
		for(int i = 1; i < N-1; i += 2){
			if(i > 1) dp[0][i] = dp[0][i-2];
			else dp[1][i] = 0;
			int th = max(H[i-1], H[i+1]) + 1;
			if(th > H[i]){
				dp[0][i] += th - H[i];
			}
		}
		for(int i = N-2; i > 0; i -= 2){
			if(i < N-2) dp[1][i] = dp[1][i+2];
			else dp[1][i] = 0;
			int th = max(H[i-1], H[i+1]) + 1;
			if(th > H[i]){
				dp[1][i] += th - H[i];
			}
		}
		if(N & 1) ans = dp[0][N-2];
		else{
			ans = min(dp[0][N-3], dp[1][2]);
			for(int i = 1; i < N-3; i += 2){
				ans = min(ans, dp[0][i] + dp[1][i+3]);
			}
		}
		moo << ans << endl;
	}
}