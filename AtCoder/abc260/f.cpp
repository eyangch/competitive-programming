#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int S, T, M, V[3000][3000];
vector<int> G[400000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> S >> T >> M;
	for(int i = 0; i < M; i++){
		int u, v; eat >> u >> v;
		u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i = 0; i < T; i++){
		for(int j = 0; j < T; j++){
			V[i][j] = -1;
		}
	}
	int ans1 = -1, ans2 = -1, ans3 = -1, ans4 = -1;
	for(int i = 0; i < S; i++){
		for(int j : G[i]){
			for(int k : G[i]){
				if(j == k) continue;
				if(~V[j-S][k-S]){
					ans1 = i+1;
					ans2 = V[j-S][k-S]+1;
					ans3 = j+1;
					ans4 = k+1;
				}else{
					V[j-S][k-S] = i;
				}
			}
		}
		if(~ans1) break;
	}
	if(~ans1){
		moo << ans1 << ' ' << ans2 << ' ' << ans3 << ' ' << ans4 << endl;
	}else{
		moo << -1 << endl;
	}
}