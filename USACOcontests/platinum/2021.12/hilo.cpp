#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define ll long long
#define MOD 1000000007
#define MXN 5005

using namespace std;

int N, X, H[2], sH[MXN][MXN][2], Fi[MXN+1], F[MXN+1];

int sp(int a, int b){
	return b - a + 1;
}

int inv(int x){
	int e = MOD - 2;
	ll ret = 1;
	for(int i = 0; i < 32; i++){
		if((e >> i) & 1){
			ret = ret * x % MOD;
		}
		x = (ll)x * x % MOD;
	}
	return ret;
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	F[0] = 1;
	for(int i = 1; i <= MXN; i++){
		F[i] = (ll)(F[i-1]) * i % MOD;
	}
	for(int i = 0; i <= MXN; i++){
		Fi[i] = inv(F[i]);
	}
	eat >> N >> X;
	for(int l = X; l >= 0; l--){
		for(int r = X; r <= N; r++){
			if(l == r) continue;
			H[0] = (ll)sH[l+1][r][0] * F[r-l-1] % MOD;
			H[1] = (ll)sH[l][r-1][1] * F[r-l-1] % MOD;
			sH[l][r][0] = (sH[l+1][r][0] + (ll)(H[0] + H[1] % MOD) * Fi[r-l]) % MOD;
			sH[l][r][1] = (sH[l][r-1][1] + (ll)(((H[0] + H[1]) % MOD + (ll)F[r-l-1] * (X-l) % MOD) % MOD) * Fi[r-l]) % MOD;
		}
	}
	moo << (H[0] + H[1]) % MOD << endl;
}