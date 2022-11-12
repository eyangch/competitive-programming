#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, A[200000], dwn[200000], ans;
vector<int> G[200000];

void dfsD(int v, int p){
	for(int c : G[v]){
		if(c == p) continue;
		dfsD(c, v);
		if(A[c] < A[v]){
			dwn[v] += dwn[c];
		}
	}
	dwn[v]++;
}

int dfsU(int v, int p){
	int ret = dwn[v];
	int mx = 0;
	for(int c : G[v]){
		if(c == p) continue;
		int x = dfsU(c, v);
		if(A[c] > A[v]) mx = max(mx, x);
	}
	ret += mx;
	ans = max(ans, ret);
	//moo << v << ' ' << ret << endl;
	return ret;
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	for(int tc = 1; tc <= T; tc++){
		moo << "Case #" << tc << ": ";
		eat >> N;
		for(int i = 0; i < N; i++){
			eat >> A[i];
			G[i].clear();
		}
		fill(dwn, dwn+N, 0);
		ans = 0;
		for(int i = 0; i < N-1; i++){
			int u, v; eat >> u >> v;
			u--, v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfsD(0, -1);
		dfsU(0, -1);
		moo << ans << endl;
	}
}