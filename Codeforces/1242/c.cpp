#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int K, N[15], A[15][5000], bsum[15];
pair<int, int> dp[1<<15], ans[15];
vector<int> V[1<<15];
map<int, int> M;

void dfs(int x){
	if(dp[x].first == x){
		vector<int> cur = V[x];
		for(int i = 0; i < (int)cur.size(); i++){
			int pv = (i+cur.size()-1) % cur.size();
			ans[M[cur[i]]] = {cur[i], M[cur[pv]]};
		}
	}else{
		dfs(dp[x].first);
		dfs(dp[x].second);
	}
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	int sum = 0;
	eat >> K;
	for(int i = 0; i < K; i++){
		eat >> N[i];
		for(int j = 0; j < N[i]; j++){
			eat >> A[i][j];
			M[A[i][j]] = i;
			bsum[i] += A[i][j];
			sum += A[i][j];
		}
	}
	if(sum % K){
		moo << "NO" << endl;
		return 0;
	}
	sum /= K;
	for(int i = 0; i < (1<<K); i++){
		dp[i] = {-1, -1};
	}
	dp[0] = {0, 0};
	for(int i = 0; i < K; i++){
		for(int j = 0; j < N[i]; j++){
			bool vis[K];
			fill(vis, vis+K, 0);
			int cur_b = i, cur = A[i][j];
			int visn = 0;
			vector<int> swp;
			//moo << i << ' ' << j << endl;
			while(true){
				if(vis[cur_b]) break;
				//moo << cur << ' ';
				swp.push_back(cur);
				vis[cur_b] = 1;
				visn++;
				int csum = bsum[cur_b];
				int nsum = csum - cur;
				int targ = sum - nsum;
				auto it = M.find(targ);
				if(it == M.end()){
					cur = 1e15;
					break;
				}
				cur_b = it->second;
				cur = targ;
			}
			//moo << endl << endl;
			if(cur != A[i][j]) continue;
			int mask = 0;
			for(int k = 0; k < K; k++){
				if(vis[k]) mask |= (1<<k);
			}
			dp[mask].first = mask;
			dp[mask].second = 0;
			V[mask] = swp;
		}
	}
	for(int i = 0; i < (1<<K); i++){
		for(int j = i; j > 0; j = (j-1) & i){
			int k = i ^ j;
			if(~dp[j].first && ~dp[k].first){
				dp[i] = {j, k};
				break;
			}
		}
		//moo << dp[i].first << endl;
	}
	int e = (1<<K)-1;
	if(~dp[e].first){
		moo << "YES" << endl;
		dfs(e);
		for(int i = 0; i < K; i++){
			moo << ans[i].first << ' ' << ans[i].second+1 << endl;
		}
	}else{
		moo << "NO" << endl;
	}
}