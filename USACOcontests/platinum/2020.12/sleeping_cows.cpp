#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int MOD = 1e9+7;
int N, S[3001], T[3001], dp[3000][2], cdp[3000][2];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N;
	for(int i = 0; i < N; i++){
		eat >> S[i];
	}
	for(int i = 0; i < N; i++){
		eat >> T[i];
	}
	sort(S, S+N);
	sort(T, T+N);
	S[N] = T[N] = 2e9;
	int spt = 0, tpt = 0;
	dp[0][0] = 1;
	while(spt < N || tpt < N){
		for(int i = 0; i < N; i++) cdp[i][0] = cdp[i][1] = 0;
		if(S[spt] <= T[tpt]){
			for(int i = 1; i < N; i++){
				cdp[i][0] += dp[i-1][0];
				cdp[i][1] += dp[i-1][1];
			}
			for(int i = 0; i < N; i++){
				cdp[i][1] += dp[i][0] + dp[i][1];
			}
			spt++;
		}else{
			for(int i = 0; i < N-1; i++){
				cdp[i][0] += (i+1) * dp[i+1][0];
				cdp[i][1] += (i+1) * dp[i+1][1];
			}
			for(int i = 0; i < N; i++){
				cdp[i][0] += dp[i][0];
			}
			tpt++;
		}
		for(int i = 0; i < N; i++) dp[i][0] = cdp[i][0] % MOD, dp[i][1] = cdp[i][1] % MOD;
		//for(int i = 0; i < N; i++) moo << dp[i][0] << ' ' << dp[i][1] << endl;
		//moo << endl;
	}
	moo << (dp[0][0] + dp[0][1]) % MOD << endl;
}