#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, C[500000], S[500000], par[500000], sz[500000], rsz[500000];
vector<pair<int, int>> G[500000];
stack<int> cs[500000];

int dfs(int v, int p, int c){
	C[v] = c;
	S[v] = 1;
	for(pair<int, int> e : G[v]){
		if(e.first == p) continue;
		S[v] += dfs(e.first, v, e.second);
	}
	return S[v];
}

void dfs2(int v, int p){
	int c = C[v];
	sz[v] = S[v];
	if(~c){
		par[v] = cs[c].top();
		if(par[v] == 0){
			rsz[c] -= S[v];
		}else{
			sz[par[v]] -= S[v];
		}
		cs[c].push(v);
	}
	for(pair<int, int> e : G[v]){
		if(e.first == p) continue;
		dfs2(e.first, v);
	}
	if(~c){
		cs[c].pop();
	}
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N;
	for(int i = 0; i < N-1; i++){
		int u, v, x;
		eat >> u >> v >> x;
		u--, v--, x--;
		G[u].push_back({v, x});
		G[v].push_back({u, x});
	}
	dfs(0, -1, -1);
	for(int i = 0; i < N; i++){
		cs[i].push(0);
	}
	fill(rsz, rsz+N, N);
	dfs2(0, -1);
	int ans = 0;
	for(int i = 1; i < N; i++){
		int ch = sz[i];
		int pr = 0;
		int p = par[i];
		if(p == 0){
			pr = rsz[C[i]];
		}else{
			pr = sz[p];
		}
		ans += ch * pr;
	}
	moo << ans << endl;
}