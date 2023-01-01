#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, K, X, Y, A[200000], M[200000], D[200000], S[200000];
vector<int> G[200000];

void dfs_sub(int v, int p, int d){
	S[v] = M[v];
	D[v] = d;
	for(int c : G[v]){
		if(c == p) continue;
		dfs_sub(c, v, d+1);
		S[v] += S[c];
	}
}

int ans;
void dfs(int v, int p){
	if(S[v] == 0) return;
	ans++;
	for(int c : G[v]){
		if(c == p) continue;
		dfs(c, v);
	}
	ans++;
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N >> K >> X >> Y;
		X--, Y--;
		for(int i = 0; i < N; i++){
			G[i].clear();
			M[i] = 0;
		}
		for(int i = 0; i < K; i++){
			eat >> A[i];
			A[i]--;
			M[A[i]]++;
		}
		M[Y]++;
		for(int i = 0; i < N-1; i++){
			int u, v; eat >> u >> v;
			u--, v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs_sub(X, -1, 0);
		ans = -D[Y]-2;
		dfs(X, -1);
		moo << ans << endl;
	}
}