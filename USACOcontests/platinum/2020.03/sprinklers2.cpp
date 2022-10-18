#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout

using namespace std;

int MOD = 1e9+7;
int N, mp[2001][2001][2], p2[2001];
long long dp[2001][2001][2];
char S[2000][2000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	freopen("sprinklers2.in", "r", stdin); freopen("sprinklers2.out", "w", stdout);
	p2[0] = 1;
	for(int i = 1; i <= 2000; i++){
		p2[i] = p2[i-1] * 2 % MOD;
	}
	eat >> N;
	for(int i = 0; i < N; i++){
		eat >> S[i];
	}
	for(int i = 0; i < N; i++){
		for(int j = N-1; j >= 0; j--){
			mp[i][j][0] = (S[i][j] == '.');
			mp[j][i][1] = (S[j][i] == '.');
			if(j != N-1){
				mp[i][j][0] += mp[i][j+1][0];
				mp[j][i][1] += mp[j+1][i][1];
			}
		}
	}
	dp[0][0][0] = dp[0][0][1] = 1;
	for(int i = 0; i <= N; i++){
		for(int j = 0; j <= N; j++){
			if(i > 0){
				int m = mp[i-1][j][0];
				dp[i][j][0] = dp[i-1][j][0] * p2[m] % MOD;
			}
			if(j > 0 && S[i][j-1] == '.' && i < N){
				int m = mp[i][j-1][1];
				dp[i][j][0] = (dp[i][j][0] 
					+ dp[i][j-1][1] * p2[m-1] % MOD) % MOD;
			}
			if(j > 0){
				int m = mp[i][j-1][1];
				dp[i][j][1] = dp[i][j-1][1] * p2[m] % MOD;
			}
			if(i > 0 && S[i-1][j] == '.' && j < N){
				int m = mp[i-1][j][0];
				dp[i][j][1] = (dp[i][j][1]
					+ dp[i-1][j][0] * p2[m-1] % MOD) % MOD;
			}
		}
	}
	moo << (dp[N][N][0] + dp[N][N][1]) % MOD << endl;
}