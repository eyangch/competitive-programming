#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int MOD = 998244353;
int N, M, L[50], R[50];
int dp[51][100001];
bool sv[100001];
vector<int> pr;
vector<pair<int, bool>> nm;

void dfs(int n, int i, int r){
	int cn = n * pr[i];
	nm.push_back({cn, r&1});
	for(int j = i+1; j < pr.size(); j++){
		if(cn * pr[j] > M) continue;
		dfs(cn, j, r+1);
	}
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	for(int i = 2; i < 100001; i++){
		if(sv[i]) continue;
		for(int j = 2; i * j < 100001; j++){
			sv[i*j] = 1;
		}
	}
	for(int i = 1; i < 100001; i++){
		if(!sv[i]) pr.push_back(i);
	}
	eat >> N >> M;
	for(int i = 0; i < N; i++){
		eat >> L[i] >> R[i];
	}
	dfs(1, 0, 0);
	int ans = 0;
	for(pair<int, bool> pb : nm){
		int i = pb.first;
		bool p = pb.second;
		dp[0][0] = 1;
		for(int j = 0; j < N; j++){
			int adjL = L[j]/i + (L[j] % i != 0);
			int adjR = R[j]/i;
			for(int k = 0; k <= M/i; k++) dp[j+1][k] = 0;
			for(int k = 0; k <= M/i; k++){
				if(k+adjL > M/i) break;
				dp[j+1][k+adjL] += dp[j][k];
				if(k+adjR+1 <= M/i){
					dp[j+1][k+adjR+1] -= dp[j][k];
				}
			}
			int pfx = 0;
			for(int k = 1; k <= M/i; k++){
				dp[j+1][k] = (dp[j+1][k] + dp[j+1][k-1]) % MOD;
			}
		}
		int ways = 0;
		for(int k = 0; k <= M/i; k++){
			ways = (ways + dp[N][k]) % MOD;
		}
		ans = ((ans + (p ? -1 : 1) * ways) % MOD + MOD) % MOD;
	}
	moo << ans << endl;
}