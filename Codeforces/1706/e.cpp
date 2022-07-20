#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

struct DSU{
	int par[100000], sz[100000], a[100000], N;
	vector<int> c[100000];
	void init(int N){
		fill(sz, sz+N, 1);
		iota(par, par+N, 0);
		fill(a, a+N, 1e15);
		for(int i = 0; i < N; i++){
			c[i].clear();
			c[i].push_back(i);
		}
		this->N = N;
	}
	int find(int u){
		if(u == par[u]) return u;
		return find(par[u]);
	}
	void un(int u, int v, int x){
		u = find(u), v = find(v);
		if(u == v) return;
		if(sz[u] > sz[v]) swap(u, v);
		for(int i : c[u]){
			c[v].push_back(i);
			par[i] = v;
			if(i > 0 && par[i] == par[i-1]){
				a[i] = min(a[i], x);
			}
			if(i < N-1 && par[i] == par[i+1]){
				a[i+1] = min(a[i+1], x);
			}
		}
		c[u].clear();
		sz[v] += sz[u];
	}
};

struct sparse_table{
	int N, st[20][100000], lg2[100001];
	void init(int N, int (&arr)[100000]){
		for(int i = 0; i < N; i++){
			st[0][i] = arr[i];
		}
		this->N = N;
		lg2[1] = 0;
		for(int i = 2; i <= N; i++){
			lg2[i] = lg2[i/2] + 1;
		}
		for(int i = 1; i < 20; i++){
			for(int j = 0; j + (1<<i) <= N; j++){
				st[i][j] = max(st[i-1][j], st[i-1][j+(1<<(i-1))]);
			}
		}
	}
	int qry(int l, int r){
		if(l == r) return st[0][l];
		int lg = lg2[r - l + 1];
		return max(st[lg][l], st[lg][r-(1<<(lg))+1]);
	}
};

int T, N, M, Q;
DSU dsu;
sparse_table st;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N >> M >> Q;
		dsu.init(N);
		for(int i = 0; i < M; i++){
			int u, v; eat >> u >> v;
			u--, v--;
			//moo << "Edge: " << u << ' ' << v << endl;
			dsu.un(u, v, i+1);
		}
		st.init(N, dsu.a);
		/*moo << "DSU.A: ";
		for(int i = 0; i < N; i++){
			moo << dsu.a[i] << ' ';
		}
		moo << endl;*/
		for(int i = 0; i < Q; i++){
			int l, r; eat >> l >> r;
			l--, r--;
			if(l == r){
				moo << 0 << ' ';
			}else{
				//moo << l << ' ' << r << endl; moo.flush();
				moo << st.qry(l+1, r) << ' ';
			}
		}
		moo << endl;
	}
}