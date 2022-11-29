#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int MOD = 1e9+7;
int f[200001], fi[200001];

int N, K;
vector<int> G[200000];
int tot[200000], sub[200000], sz[200000], ans[200000], sum;

void t(int &x){
	x = (x % MOD + MOD) % MOD;
}

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
    if(n < r) return 0;
    return f[n] * fi[r] % MOD * fi[n-r] % MOD;
}

void dfs(int v, int p){
	sz[v] = 1;
	for(int c : G[v]){
		if(c == p) continue;
		dfs(c, v);
		sz[v] += sz[c];
		sub[v] += nCr(sz[c], K);
	}
	tot[v] = nCr(sz[v], K);
	sum += sz[v] * (tot[v] - sub[v]);
	t(sum);
}

void reroot(int o, int n){
	sum -= sz[o] * (tot[o] - sub[o]) + sz[n] * (tot[n] - sub[n]);
	sub[o] -= nCr(sz[n], K);
	sz[o] -= sz[n];
	sz[n] = N;
	tot[o] = nCr(sz[o], K);
	sub[n] += tot[o];
	tot[n] = nCr(N, K);
	sum += sz[o] * (tot[o] - sub[o]) + sz[n] * (tot[n] - sub[n]);
	t(sum);
}

void dfs_ans(int v, int p){
	if(~ans[v]) assert(ans[v] == sum);
	else ans[v] = sum;
	for(int c : G[v]){
		if(c == p) continue;
		reroot(v, c);
		dfs_ans(c, v);
		reroot(c, v);
	}
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> K;
	f[0] = 1;
	for(int i = 1; i <= N; i++){
		f[i] = f[i-1] * i % MOD;
	}
	for(int i = 0; i <= N; i++){
		fi[i] = inv(f[i]);
	}
	for(int i = 0; i < N-1; i++){
		int u, v; eat >> u >> v;
		u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(0, -1);
	fill(ans, ans+N, -1);
	dfs_ans(0, -1);
	moo << accumulate(ans, ans+N, 0LL) % MOD << endl;
}