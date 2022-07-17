#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

struct DSU{
	int par[100000], sz[100000];
	void init(int N){
		fill(sz, sz+N, 1);
		iota(par, par+N, 0);
	}
	int find(int u){
		if(par[u] == u) return u;
		return (par[u] = find(par[u]));
	}
	void un(int u, int v){
		u = find(u), v = find(v);
		if(sz[u] > sz[v]){
			swap(u, v);
		}
		par[u] = v;
		sz[v] += sz[u];
	}
};

int N, M, K, dep[100000], up[20][100000], add[100000];
bool ans[100000];
pair<int, int> E[200000];
vector<int> graph[100000];
DSU dsu;

void dfs(int v, int p, int d){
	dep[v] = d;
	for(int i = 1; i < 20; i++){
		up[i][v] = up[i-1][up[i-1][v]];
	}
	for(int c : graph[v]){
		if(c == p) continue;
		up[0][c] = v;
		dfs(c, v, d+1);
	}
}

int jump(int u, int x){
	for(int i = 19; i >= 0; i--){
		if((x >> i) & 1) u = up[i][u];
	}
	return u;
}

void dfs2(int v, int p, int sum){
	sum += add[v];
	if(sum == K) ans[v] = 1;
	for(int c : graph[v]){
		if(c == p) continue;
		dfs2(c, v, sum);
	}
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> M;
	dsu.init(N);
	for(int i = 0; i < M; i++){
		int u, v; eat >> u >> v;
		u--, v--;
		if(dsu.find(u) != dsu.find(v)){
			graph[u].push_back(v);
			graph[v].push_back(u);
			dsu.un(u, v);
		}else{
			E[K++] = {u, v};
		}
	}
	dfs(0, -1, 0);
	for(int i = 0; i < K; i++){
		int u = E[i].first, v = E[i].second;
		if(dep[u] > dep[v]) swap(u, v);
		int dst = dep[v] - dep[u];
		if(jump(v, dst) == u){
			add[0]++;
			add[jump(v, dst-1)]--;
			add[v]++;
		}else{
			add[u]++;
			add[v]++;
		}
	}
	dfs2(0, -1, 0);
	for(int i = 0; i < N; i++){
		moo << ans[i];
	}
	moo << endl;
}