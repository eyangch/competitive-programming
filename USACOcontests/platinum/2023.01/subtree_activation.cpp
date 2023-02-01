#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, P[200000];
vector<int> G[200000];
int dp[200000][2], st[200000];

int dfs_st(int v){
	st[v] = 1;
	for(int c : G[v]){
		st[v] += dfs_st(c);
	}
	return st[v];
}

void dfs(int v){
	dp[v][0] = 2;
	dp[v][1] = 1;
	for(int c : G[v]){
		dfs(c);
	}

	int mxd = 0;
	for(int c : G[v]){
		int val = dp[c][0] + st[c];
		dp[v][1] += val;
		mxd = max(mxd, val - dp[c][1]);
	}
	dp[v][1] -= mxd;

	vector<pair<int, int>> vd1, vd2;
	for(int c : G[v]){
		int val = dp[c][0] + 2 * st[c];
		int val2 = dp[c][1] + st[c];
		int val3 = dp[c][0];
		dp[v][0] += val;
		vd1.push_back({max(0LL, val - val2), c});
		vd2.push_back({max(0LL, val - val3), c});
	}
	sort(vd1.begin(), vd1.end(), greater<pair<int, int>>());
	sort(vd2.begin(), vd2.end(), greater<pair<int, int>>());
	while(vd1.size() < 2){
		vd1.push_back({0, N + vd1.size()});
	}
	while(vd2.size() < 2){
		vd2.push_back({0, N + 10 + vd2.size()});
	}
	int subv = vd2[0].first;
	subv = max(subv, vd1[0].first + vd1[1].first);
	/*if(vd1[0].second != vd2[0].second){
		subv = vd1[0].first + vd2[0].first;
	}else{
		subv = max(vd1[0].first + vd2[1].first, vd1[1].first + vd2[0].first);
	}*/
	dp[v][0] -= subv;
	dp[v][0] = min(dp[v][0], dp[v][1] + st[v]);
	dp[v][1] = min(dp[v][1], dp[v][0] + st[v]);
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N;
	for(int i = 1; i < N; i++){
		eat >> P[i];
		P[i]--;
		G[P[i]].push_back(i);
	}
	dfs_st(0);
	dfs(0);
	moo << dp[0][0] << endl;
}