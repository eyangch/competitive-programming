#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, M, A[300000], dp[300000], Q;

int calc(vector<int> &lmx, vector<int> &rmx, vector<int> &tot, vector<int> &mx){
	int ret = 0, cur = 0;
	for(int i = 0; i < (int)tot.size(); i++){
		ret = max(ret, cur + lmx[i]);
		ret = max(ret, mx[i]);
		cur = max(cur + tot[i], rmx[i]);
	}
	return ret;
}

void dfs(int x, int d, vector<int> lmx, vector<int> rmx, vector<int> tot, vector<int> mx){
	if(d >= N) return;
	for(int sp = 0; sp < 2; sp++){
		int dpc = calc(lmx, rmx, tot, mx);
		//if(dpc != dp[x] && dp[x] > 0) moo << dpc << ' ' << dp[x] << endl;
		dp[x] = dpc;
		vector<int> lmx2, rmx2, tot2, mx2;
		for(int i = 0; i < (int)tot.size(); i += 2){
			int l = max(lmx[i], tot[i] + lmx[i+1]);
			int r = max(rmx[i+1], tot[i+1] + rmx[i]);
			int t = tot[i] + tot[i+1];
			int m = max({mx[i], mx[i+1], rmx[i] + lmx[i+1]});
			lmx2.push_back(l), rmx2.push_back(r), tot2.push_back(t), mx2.push_back(m);
		}
		//moo << x << ' ' << d << endl;
		//for(int i : lmx2){
		//	moo << i << ' ';
		//}
		//moo << endl;
		dfs(x, d+1, lmx2, rmx2, tot2, mx2);
		for(int i = 0; i < (int)tot.size(); i += 2){
			swap(lmx[i], lmx[i+1]);
			swap(rmx[i], rmx[i+1]);
			swap(tot[i], tot[i+1]);
			swap(mx[i], mx[i+1]);
		}
		x ^= (1<<d);
	}
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N;
	M = 1<<N;
	for(int i = 0; i < M; i++){
		eat >> A[i];
	}
	vector<int> lmx, rmx, tot, mx;
	for(int i = 0; i < M; i++){
		int mx0 = max(0LL, A[i]);
		lmx.push_back(mx0), rmx.push_back(mx0), tot.push_back(A[i]), mx.push_back(mx0);
	}
	dfs(0, 0, lmx, rmx, tot, mx);
	eat >> Q;
	int cur = 0;
	for(int i = 0; i < Q; i++){
		int x; eat >> x;
		cur ^= (1<<x);
		moo << dp[cur] << endl;
	}
}