#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int MOD = 998244353;

int T, N, A[100001], S[100001], Q[100002], M[100001], mp[100001];
int dp[100001], dps[100001];
int f[100005], fi[100005];

int bp(int n, int e){
    int a = 1;
    for(int i = 0; i < 32; i++){
        if(e>>i & 1) a = a * n % MOD;
        n = n * n % MOD;
    }
    return a;
}

int inv(int n){
    return bp(n, MOD-2);
}

int nCr(int n, int r){
    if(n < r) return 1;
    return f[n] * fi[r] % MOD * fi[n-r] % MOD;
}

int calc(int l, int r, int mn = -1){
	if(l > r) swap(l, r);
	if(!~mn) mn = l;
	int ret = 0;
	for(int i = 0; i <= mn; i++){
		int cur = nCr(l, i) * nCr(r, i) % MOD;
		ret = (ret + cur) % MOD;
	}
	return ret;
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	f[0] = 1;
	fi[0] = 1;
	for(int i = 1; i < 100005; i++){
		f[i] = f[i-1] * i % MOD;
		fi[i] = inv(f[i]);
	}
	eat >> T;
	while(T--){
		eat >> N;
		for(int i = 1; i <= N; i++){
			eat >> A[i];
		}
		for(int i = 1; i <= N; i++){
			S[i] = S[i-1] + A[i];
		}
		Q[N+1] = 0;
		for(int i = N; i > 0; i--){
			Q[i] = Q[i+1] + A[i];
		}
		int lp = 1, rp = N, ll = 0, rl = 0;
		int ans = 1;
		while(lp <= rp){
			while(lp < rp && S[lp] != Q[rp]){
				if(S[lp] < Q[rp]) lp++;
				else rp--;
			}
			while(lp < rp && S[lp] == Q[rp]){
				lp++;
				ll++;
			}
			lp--;
			while(lp < rp && S[lp] == Q[rp]){
				rp--;
				rl++;
			}
			int x = 0;
			if(lp == rp && A[lp] == 0){
				x = calc(ll+rl-1, 1, ll+rl-1);
			}else{
				x = calc(ll, rl);
			}
			ans = ans * x % MOD;
			ll = rl = 0;
			lp++;
			if(lp >= rp) break;
		}
		if(S[N] == 0){
			ans = calc(N-1, 1, N-1);
		}
		moo << ans << endl;
	}
}