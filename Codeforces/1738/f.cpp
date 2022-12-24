#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, D[1000], I[1000];
bool vis[1000];
vector<int> G[1000];
int ans[1000];

void dfs(int v, int c){
	if(vis[v]) return;
	vis[v] = 1;
	ans[v] = c;
	for(int e : G[v]){
		dfs(e, c);
	}
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N;
		for(int i = 0; i < N; i++){
			G[i].clear();
			eat >> D[i];
		}
		iota(I, I+N, 0);
		sort(I, I+N, [](int a, int b){
			return D[a] > D[b];
		});
		fill(vis, vis+N, 0);
		for(int i = 0; i < N; i++){
			int j = I[i];
			if(vis[j]) continue;
			for(int k = 0; k < D[j]; k++){
				moo << "? " << j+1 << endl;
				moo.flush();
				int v; eat >> v;
				v--;
				G[j].push_back(v);
				G[v].push_back(j);
				if(vis[v]){
					break;
				}
				vis[v] = 1;
			}
			vis[j] = 1;
		}
		fill(vis, vis+N, 0);
		for(int i = 0; i < N; i++){
			dfs(i, i+1);
		}
		moo << "! ";
		for(int i = 0; i < N; i++){
			moo << ans[i] << ' ';
		}
		moo << endl;
		moo.flush();
	}
}