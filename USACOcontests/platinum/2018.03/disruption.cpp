#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

struct lift{
	int up[20][500000], dep[50000];
	void init(int N, vector<int> (&G)[50000], int v=0, int p=0, int d=0){
		up[0][v] = p;
		for(int i = 1; i < 20; i++){
			up[i][v] = up[i-1][up[i-1][v]];
		}
		dep[v] = d;
		for(int c : G[v]){
			if(c == p) continue;
			init(N, G, c, v, d+1);
		}
	}
	int jump(int v, int d){
		for(int i = 0; i < 20; i++){
			if((d>>i)&1){
				v = up[i][v];
			}
		}
		return v;
	}
	int lca(int u, int v){
		if(dep[u] > dep[v]) swap(u, v);
		v = jump(v, dep[v]-dep[u]);
		if(u == v){
			return u;
		}
		for(int i = 19; i >= 0; i--){
			if(up[i][u] != up[i][v]){
				u = up[i][u];
				v = up[i][v];
			}
		}
		return up[0][u];
	}
};

struct uwu{
	int u, v, r;
};

int N, M, P[50000], EI[50000], C[50000], ans[50000];
vector<int> G[50000];
pair<int, int> E[50000];
uwu A[50000];
lift L;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	freopen("disrupt.in", "r", stdin); freopen("disrupt.out", "w", stdout);
	eat >> N >> M;
	for(int i = 0; i < N-1; i++){
		int u, v; eat >> u >> v;
		u--, v--;
		E[i] = {u, v};
		G[u].push_back(v);
		G[v].push_back(u);
	}
	L.init(N, G);
	for(int i = 0; i < N-1; i++){
		int u = E[i].first, v = E[i].second;
		if(L.dep[u] > L.dep[v]){
			swap(u, v);
		}
		P[v] = u;
		EI[v] = i;
	}
	iota(C, C+N, 0);
	for(int i = 0; i < M; i++){
		int u, v, r; eat >> u >> v >> r;
		u--, v--;
		A[i] = {u, v, r};
	}
	sort(A, A+M, [](uwu a, uwu b){
		return a.r < b.r;
	});
	fill(ans, ans+N-1, -1);
	for(int i = 0; i < M; i++){
		int u = A[i].u, v = A[i].v, r = A[i].r;
		u = C[u], v = C[v];
		int lca = L.lca(u, v);
		lca = C[lca];
		for(int z = 0; z < 2; z++){
			int cnt = 0;
			while(L.dep[u] > L.dep[lca]){
				if(!~ans[EI[u]]) ans[EI[u]] = r;
				C[u] = lca;
				u = C[P[u]];
			}
			swap(u, v);
		}
	}
	for(int i = 0; i < N-1; i++){
		moo << ans[i] << endl;
	}
}