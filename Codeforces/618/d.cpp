#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, X, Y;
int deg[200000], par[200000], ans[200000];
vector<int> graph[200000];

int dfs(int i){
	int children = 0;
	int navail = 0;
	for(int c : graph[i]){
		if(c == par[i]) continue;
		par[c] = i;
		navail += dfs(c);
		ans[i] += ans[c];
		children++;
	}
	if(children == 0) return 1;
	if(navail >= 2){
		ans[i] += 2;
		return 0;
	}else{
		ans[i] += navail;
		return 1;
	}
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> X >> Y;
	for(int i = 0; i < N-1; i++){
		int u, v; eat >> u >> v;
		deg[u-1]++;
		deg[v-1]++;
		graph[u-1].push_back(v-1);
		graph[v-1].push_back(u-1);
	}
	dfs(0);
	int e = N-1;
	if(X > Y){
		int ans = e * Y;
		for(int i = 0; i < N; i++){
			if(deg[i] == N-1){
				ans -= Y;
				ans += X;
				break;
			}
		}
		moo << ans << endl;
	}else{
		moo << ans[0] * X + (e - ans[0]) * Y << endl;
	}
}