#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, M;
int p2[5001];
int ans[5001], dp[5001], sum[5001];
// ans[i] = 111...111
// dp[i] = prefix of i 1's
// sum[i] = sum of all dp[k] of length j, j+k = i

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> M;
	p2[0] = 1;
	for(int i = 1; i <= N; i++){
		p2[i] = p2[i-1] * 2 % M;
	}
	ans[1] = 1;
	for(int i = 2; i <= N; i++){
		sum[i]++;
	}
	for(int i = 2; i <= N; i++){
		for(int j = 1; j < i; j++){
			int x = i-2*j-1;
			dp[j] = ans[j] * (1 + (x >= 0 ? sum[x] : 0)) % M;
		}
		int cs = accumulate(dp, dp+i, 0LL) % M;
		ans[i] = dp[i] = (p2[i-1] - cs + M) % M;
		int ac = 0;
		for(int j = i; j <= N; j++){
			ac = (ac + dp[j-i]) % M;
			sum[j] = (sum[j] + ac) % M;
		}
	}
	moo << ans[N] << endl;
}