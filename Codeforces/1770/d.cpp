#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int MOD = 998244353;
int T, N, A[100000], B[100000];
vector<int> G[100000];
int vis[100000], sz[100000], de[100000];

void dfs(int v, int cl){
	if(~vis[v]) return;
	vis[v] = cl;
	for(int c : G[v]){
		dfs(c, cl);
	}
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N;
		//reset
		for(int i = 0; i < N; i++){
			vector<int>().swap(G[i]);
			vis[i] = -1;
			sz[i] = 0;
			de[i] = 0;
		}
		//end reset
		for(int i = 0; i < N; i++){
			eat >> A[i];
			A[i]--;
		}
		for(int i = 0; i < N; i++){
			eat >> B[i];
			B[i]--;
		}
		for(int i = 0; i < N; i++){
			G[A[i]].push_back(B[i]);
			G[B[i]].push_back(A[i]);
		}
		for(int i = 0; i < N; i++){
			if(~vis[i]) continue;
			dfs(i, i);
		}
		int cnt1 = 0, cnt2 = 0;
		for(int i = 0; i < N; i++){
			sz[vis[i]]++;
			de[vis[i]] += G[i].size();
			if(A[i] == B[i]){
				cnt1++;
				cnt2--;
			}
		}
		int ok = 1;
		for(int i = 0; i < N; i++){
			if(de[i] != 2 * sz[i]){
				ok = 0;
				break;
			}
			if(sz[i]) cnt2++;
		}
		if(!ok){
			moo << 0 << endl;
		}else{
			int ans = 1;
			for(int i = 0; i < cnt1; i++){
				ans = ans * N % MOD;
			}
			for(int i = 0; i < cnt2; i++){
				ans = ans * 2 % MOD;
			}
			moo << ans << endl;
		}
	}
}