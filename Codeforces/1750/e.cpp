#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

struct DSU{
	int par[200001], sz[200001], mn[200001], c[200001], l[200001], r[200001];
	void init(int N, int (&p)[200001]){
		fill(sz, sz+N, 1);
		copy(p, p+N, mn);
		iota(par, par+N, 0);
		iota(l, l+N, 0);
		iota(r, r+N, 0);
		iota(c, c+N, 0);
	}
	int find(int u){
		if(u == par[u]) return u;
		return (par[u] = find(par[u]));
	}
	void un(int u, int v){
		u = find(u), v = find(v);
		if(u == v) return;
		if(sz[u] < sz[v]) swap(u, v);
		sz[u] += sz[v];
		par[v] = par[u];
		l[u] = min(l[u], l[v]);
		r[u] = max(r[u], r[v]);
		if(mn[u] > mn[v]){
			c[u] = c[v];
		}
		mn[u] = min(mn[u], mn[v]);
	}
};

int T, N, P[200001], I[200001];
string S;
DSU dsu;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N >> S;
		P[0] = 0;
		for(int i = 1; i <= N; i++){
			if(S[i-1] == '('){
				P[i] = P[i-1] + 1;
			}else{
				P[i] = P[i-1] - 1;
			}
		}
		dsu.init(N+1, P);
		iota(I, I+N+1, 0);
		sort(I, I+N+1, [](int a, int b){
			if(P[a] == P[b]) return a > b;
			return P[a] < P[b];
		});
		int add = 0;
		for(int i = 0; i < N+1; i++){
			int j = I[i];
			add += P[j] * i;
		}
		int sub = 0;
		for(int i = N; i >= 0; i--){
			int j = I[i];
			int r = j+1;
			while(r <= N){
				r = dsu.find(r);
				if(dsu.mn[r] > P[j]){
					dsu.un(j, r);
				}else{
					r = dsu.c[r];
					break;
				}
				r = dsu.find(r);
				r = dsu.r[r]+1;
			}
			int l = j-1;
			while(l >= 0){
				l = dsu.find(l);
				if(dsu.mn[l] >= P[j]){
					dsu.un(j, l);
				}else{
					l = dsu.c[l];
					break;
				}
				l = dsu.find(l);
				l = dsu.l[l]-1;
			}
			int d = (r-j) * (j-l) - 1;
			sub += d * P[j];
		}
		moo << add - sub << endl;
	}
}