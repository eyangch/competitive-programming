#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, M;
vector<pair<int, int>> G[200005];
pair<int, int> E[200005];
int ans[200005], D[200005];
bool vis[200005];
bool altv[200005];

void dfs(int v, int d){
	vis[v] = 1;
	D[v] = d;
	for(pair<int, int> e : G[v]){
		if(vis[e.first]) continue;
		ans[e.second] = 1;
		dfs(e.first, d+1);
	}
}

void sanity(){
	int cnt1 = accumulate(ans, ans+M, 0);
	assert(cnt1 == N-1);
	fill(altv, altv+N, 0);
	for(int i = 0; i < M; i++){
		if(!ans[i]){
			altv[E[i].first] = altv[E[i].second] = 1;
		}
	}
	int cnt0 = accumulate(altv, altv+N, 0);
	if(M >= N) assert(cnt0 > M-N+1);
	fill(altv, altv+N, 0);
	for(int i = 0; i < M; i++){
		if(ans[i]){
			altv[E[i].first] = altv[E[i].second] = 1;
		}
	}
	int cntx = accumulate(altv, altv+N, 0);
	//moo << N << ' ' << cntx << endl; moo.flush();
	assert(cntx == N);
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N >> M;
		fill(ans, ans+M, 0);
		for(int i = 0; i < N; i++){
			G[i].clear();
		}
		for(int i = 0; i < M; i++){
			int u, v; eat >> u >> v;
			u--, v--;
			G[u].push_back({v, i});
			G[v].push_back({u, i});
			E[i] = {u, v};
		}
		fill(vis, vis+N, 0);
		dfs(0, 0);
		if(M == N+2){
			fill(altv, altv+N, 0);
			int targ = 0;
			for(int i = 0; i < M; i++){
				if(!ans[i]){
					altv[E[i].first] = altv[E[i].second] = 1;
					targ = i;
				}
			}
			int cnt = accumulate(altv, altv+N, 0);
			if(cnt == 3){
				int u = E[targ].first;
				int v = E[targ].second;
				if(D[u] < D[v]) swap(u, v);
				for(pair<int, int> i : G[u]){
					int w = i.first;
					if(D[w] < D[u] && ans[i.second]){
						ans[i.second] = 0;
						break;
					}
				}
				ans[targ] = 1;
			}
		}
		sanity();
		for(int i = 0; i < M; i++){
			moo << ans[i];
		}
		moo << endl;
	}
}