#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int MOD = 998244353;
int T, N, M, A[1000], mxi[1000], mem[1000];
vector<int> G[1000], R[1000];
bool idle[1005], vis[1000][1000];
int sink = 0, mxd = 0;

void dfs_i(int v, int d){
	if(vis[v][d]) return;
	vis[v][d] = 1;
	mxd = max(mxd, d);
	mxi[d] = max(mxi[d], A[v]);
	for(int c : R[v]){
		dfs_i(c, d+1);
	}
}

int dfs(int v){
	if(~mem[v]) return mem[v];
	int ret = A[v];
	for(int c : R[v]){
		ret = (ret + dfs(c)) % MOD;
	}
	mem[v] = ret;
	return mem[v];
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N >> M;
		fill(idle, idle+N+2, 0);
		fill(mxi, mxi+N, 0);
		fill(mem, mem+N, -1);
		mxd = 0;
		for(int i = 0; i < N; i++){
			G[i].clear(), R[i].clear();
			fill(vis[i], vis[i]+N, 0);
		}
		for(int i = 0; i < N; i++){
			eat >> A[i];
		}
		for(int i = 0; i < M; i++){
			int u, v; eat >> u >> v;
			u--, v--;
			G[u].push_back(v);
			R[v].push_back(u);
		}
		int mxai = 0;
		for(int i = 0; i < N; i++) mxai = max(mxai, A[i]);
		if(!mxai){
			moo << 0 << endl;
			continue;
		}
		for(int i = 0; i < N; i++){
			if(!G[i].size()) sink = i;
		}
		dfs_i(sink, 0);
		int cur = 0;
		int ans = 0;
		for(int i = 0; i <= mxd; i++){
			cur = max(cur, mxi[i]);
			if(cur <= 0){
				ans++;
			}
			cur--;
		}
		int ans2 = dfs(sink);
		moo << (ans + ans2) % MOD << endl;
	}
}