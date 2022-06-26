#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, M, W[200000], S;
vector<int> graph[200000];
int de[200000], vis[200000];
int mxd = 0;

void dfs(int i, int p){
	if(vis[i]){
		return;
	}
	vis[i] = true;
	int cde = 0;
	bool all_de = 1;
	for(int c : graph[i]){
		if(c == p) continue;
		dfs(c, i);
		if(~de[c]){
			cde = max(cde, de[c]);
		}else{
			all_de = 0;
		}
	}
	if(all_de){
		de[i] = W[i] + cde;
	}
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> M;
	for(int i = 0; i < N; i++){
		eat >> W[i];
	}
	for(int i = 0; i < M; i++){
		int u, v; eat >> u >> v;
		graph[u-1].push_back(v-1);
		graph[v-1].push_back(u-1);
	}
	fill(de, de+N, -1);
	eat >> S;
	dfs(S-1, -1);
	int ans1 = 0, ans2 = 0;
	for(int i = 0; i < N; i++){
		if(~de[i]){
			ans2 = max(ans2, de[i]);
		}else{
			ans1 += W[i];
		}
	}
	moo << ans1 + ans2 << endl;
}