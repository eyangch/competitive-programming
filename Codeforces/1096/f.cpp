#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

struct BIT{
	int a[200001], N;
	void init(int N){
		this->N = N;
	}
	void upd(int i, int x){
		for(i++; i <= N; i += i & -i){
			a[i] += x;
		}
	}
	int qry(int i){
		int ret = 0;
		for(i++; i > 0; i -= i & -i){
			ret += a[i];
		}
		return ret;
	}
};

int MOD = 998244353;
int N, P[200000], F[300000], cn1, bf[200000], af[200000], lt[200000], gt[200000];
bool pres[200000];
BIT bit;

int inv(int n){
	int e = MOD-2;
	int ans = 1;
	while(e){
		if(e & 1){
			ans = ans * n % MOD;
		}
		n = n * n % MOD;
		e >>= 1;
	}
	return ans;
}

int nc2(int n){
	return n * (n-1) % MOD * 499122177 % MOD;
}

int fact(int n){
	return F[max(0LL, n)];
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	F[0] = 1;
	for(int i = 1; i < 300000; i++){
		F[i] = F[i-1] * i % MOD;
	}
	eat >> N;
	for(int i = 0; i < N; i++){
		eat >> P[i];
		if(~P[i]) P[i]--, pres[P[i]] = 1;
		else cn1++;
	}
	for(int i = 1; i < N; i++){
		bf[i] = bf[i-1];
		if(!~P[i-1]) bf[i]++;
	}
	for(int i = N-2; i >= 0; i--){
		af[i] = af[i+1];
		if(!~P[i+1]) af[i]++;
	}
	for(int i = 1; i < N; i++){
		lt[i] = lt[i-1];
		if(!pres[i-1]) lt[i]++;
	}
	for(int i = N-2; i >= 0; i--){
		gt[i] = gt[i+1];
		if(!pres[i+1]) gt[i]++;
	}
	bit.init(N);
	int cnt = 0;
	for(int i = N-1; i >= 0; i--){
		if(!~P[i]) continue;
		cnt += bit.qry(P[i]);
		bit.upd(P[i], 1);
	}
	cnt = cnt * fact(cn1) % MOD;
	for(int i = 0; i < N; i++){
		if(!~P[i]) continue;
		int cur = (af[i] * lt[P[i]] + bf[i] * gt[P[i]]) % MOD * fact(cn1-1) % MOD;
		cnt = (cnt + cur) % MOD;
	}
	for(int i = 0; i < N; i++){
		if(pres[i]) continue;
		int cur = lt[i] * nc2(cn1) % MOD * fact(cn1-2) % MOD;
		cnt = (cnt + cur) % MOD;
	}
	moo << cnt * inv(fact(cn1)) % MOD << endl;
}