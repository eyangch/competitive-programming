#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, MOD;
int f[3000001], fi[3000001], iv[3000001];

int nCr(int n, int r){
    if(n < r) return 0;
    return f[n] * fi[r] % MOD * fi[n-r] % MOD;
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> MOD;
	f[0] = fi[0] = 1;
	iv[0] = iv[1] = 1;
	for(int i = 2; i <= 3*N; i++){
		iv[i] = iv[MOD % i] * (MOD - MOD/i) % MOD;
	}
	for(int i = 1; i <= 3*N; i++){
		f[i] = f[i-1] * i % MOD;
		fi[i] = iv[i] * fi[i-1] % MOD;
	}
	int ans0 = 1;
	int ans1 = (f[N] - 1) + (f[2*N] - 1 - (f[N] - 1)) * 2;
	int ans2 = ((f[N] * f[2*N] % MOD * nCr(2*N, N) % MOD * 2 % MOD - (ans0 + ans1)) % MOD + MOD) % MOD;
	for(int i = 0; i <= N; i++){
		ans2 -= nCr(N, N-i) * nCr(N, i) % MOD * nCr(2*N-i, N) % MOD * f[N] % MOD * f[N] % MOD * f[N] % MOD;
	}
	ans2 = (ans2 % MOD + MOD) % MOD;
	int ans3 = ((f[3*N] - ans0 - ans1 - ans2) % MOD + MOD) % MOD;
	moo << (ans1 + 2 * ans2 % MOD + 3 * ans3 % MOD) % MOD << endl;
}