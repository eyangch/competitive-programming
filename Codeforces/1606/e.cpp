#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int MOD = 998244353;
int N, X;
int dp[501][501], p[501][501], fact[501], cmb[501][501];

int inv(int x){
	int e = MOD - 2;
	int ret = 1;
	for(int i = 0; i < 32; i++){
		if((e >> i) & 1){
			ret = ret * x % MOD;
		}
		x = x * x % MOD;
	}
	return ret;
}

int nCr(int n, int r){
	if(r > n || r < 0) return 1;
	return fact[n] * inv(fact[n-r] * fact[r] % MOD) % MOD;
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	for(int i = 0; i < 501; i++){
		p[i][0] = 1;
		for(int j = 1; j < 501; j++){
			p[i][j] = p[i][j-1] * i % MOD;
		}
	}
	fact[0] = 1;
	for(int i = 1; i < 501; i++){
		fact[i] = fact[i-1] * i % MOD;
	}
	for(int i = 0; i < 501; i++){
		for(int j = 0; j < 501; j++){
			cmb[i][j] = nCr(i, j);
		}
	}
	eat >> N >> X;
	for(int i = 0; i < X; i++){
		dp[0][i] = N;
	}
	int ans = 0;
	for(int i = 1; i < N; i++){
		ans = 0;
		for(int j = i; j < X; j++){
			for(int k = 0; i-k >= 0; k++){
				dp[i][j] = (dp[i][j] + dp[i-k][j-i] * cmb[N-i+k][k] % MOD * p[min(X, i)][k]) % MOD;
			}
			ans = (ans + dp[i][j]) % MOD;
		}
	}
	moo << ((p[X][N] - ans * inv(N)) % MOD + MOD) % MOD << endl;
}