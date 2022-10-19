#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, K, S[200000], ans;
vector<int> G[200000];

int dfs(int v, int pm){
	vector<int> res;
	int nc = G[v].size();
	ans += pm * S[v];
	if(nc == 0){
		return S[v];
	}
	for(int c : G[v]){
		res.push_back(dfs(c, pm/nc));
	}
	int rem = pm % nc;
	sort(res.begin(), res.end(), greater<int>());
	for(int i = 0; i < rem; i++){
		ans += res[i];
	}
	return S[v] + res[rem];
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N >> K;
		for(int i = 0; i < N; i++){
			G[i].clear();
		}
		for(int i = 1; i < N; i++){
			int p; eat >> p;
			G[p-1].push_back(i);
		}
		for(int i = 0; i < N; i++){
			eat >> S[i];
		}
		ans = 0;
		dfs(0, K);
		moo << ans << endl;
	}
}