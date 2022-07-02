#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int MOD = 1e9+7;
int N, a[1000];
int dp[1001][20001];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N;
	for(int i = 0; i < N; i++){
		eat >> a[i];
	}
	dp[0][10000] = 1;
	int ans = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j+a[i] <= 20000; j++){
			dp[i+1][j+a[i]] = (dp[i][j] + dp[i+1][j+a[i]]) % MOD;
			dp[i+1][j] = (dp[i][j+a[i]] + dp[i+1][j]) % MOD;
		}
		ans = (ans + dp[i+1][10000]) % MOD;
		/*for(int j = 0; j <= 20000; j++){
			ans = (ans + dp[i+1][j] * dp[i][j] % MOD) % MOD;
			dp[i+1][j] = (dp[i][j] + dp[i+1][j]) % MOD;
		}*/
		dp[i+1][10000]++;
	}
	moo << ans << endl;
}