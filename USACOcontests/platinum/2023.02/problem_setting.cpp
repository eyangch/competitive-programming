#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int MOD = 1e9+7;

int f[100001];
int N, M;
string S[20];
int C[1<<20], sos[1<<20][21];

int inv(int x){
	int e = MOD-2;
	int ret = 1;
	for(int i = 0; i < 32; i++){
		if((e >> i) & 1){
			ret = (ret * x) % MOD;
		}
		x = x * x % MOD;
	}
	return ret;
}

int ncr(int n, int r){
	return f[n] * inv(f[r]) % MOD * inv(f[n-r]) % MOD;
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	f[0] = 1;
	for(int i = 1; i <= 100000; i++){
		f[i] = f[i-1] * i % MOD;
	}
	eat >> N >> M;
	for(int i = 0; i < M; i++){
		eat >> S[i];
	}
	for(int i = 0; i < N; i++){
		int cur = 0;
		for(int j = 0; j < M; j++){
			if(S[j][i] == 'H') cur |= (1<<j);
		}
		C[cur]++;
	}
	for(int i = 0; i < (1<<M); i++){
		int base = 0;
		for(int j = 1; j <= C[i]; j++){
			base = (base + ncr(C[i], j) * f[j]) % MOD;
		}
		sos[i][0] = 1;
		for(int j = 0; j < M; j++){
			if((i>>j)&1){
				sos[i][j+1] = (sos[i][j] + sos[i ^ (1<<j)][j]) % MOD;
			}else{
				sos[i][j+1] = sos[i][j];
			}
		}
		int real = sos[i][M] * base % MOD;
		sos[i][0] = real;
		for(int j = 0; j < M; j++){
			if((i>>j)&1){
				sos[i][j+1] = (sos[i][j] + sos[i ^ (1<<j)][j]) % MOD;
			}else{
				sos[i][j+1] = sos[i][j];
			}
		}
	}
	moo << sos[(1<<M)-1][M] << endl;
}