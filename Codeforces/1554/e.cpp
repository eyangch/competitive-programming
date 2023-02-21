#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int MOD = 998244353;
int T, N, ans[100001];
vector<int> G[100000];

int dfs(int v, int p, int d){
	int cn = 0;
	for(int c : G[v]){
		if(c == p) continue;
		cn += dfs(c, v, d);
		if(cn < 0){
			return -1e9;
		}
	}
	if(cn % d == 0){
		return 1;
	}
	if((cn+1) % d == 0){
		return 0;
	}
	return -1e9;
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N;
		for(int i = 0; i < N; i++){
			G[i].clear();
		}
		fill(ans, ans+N+1, 0);
		for(int i = 0; i < N-1; i++){
			int u, v; eat >> u >> v;
			u--, v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		ans[1] = 1;
		for(int i = 0; i < N-1; i++){
			ans[1] = ans[1] * 2 % MOD;
		}
		for(int i = 2; i < N; i++){
			if((N-1) % i == 0){
				int x = dfs(0, 0, i);
				ans[i] = max(x, 0LL);
			}
		}
		for(int i = N-1; i > 0; i--){
			if(!ans[i]) continue;
			for(int j = 2*i; j <= N-1; j += i){
				ans[i] = (ans[i] + MOD - ans[j]) % MOD;
			}
		}
		for(int i = 1; i <= N; i++){
			moo << ans[i] << ' ';
		}
		moo << endl;
	}
}