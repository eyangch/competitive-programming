// verified on CF1527E

#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

struct lazy_segtree{ // update: add, query: min
	int A[4*35001+1], Z[4*35001+1];
	void push(int v, int vl, int vr){
		A[v] += Z[v];
		if(vl != vr){
			Z[v*2] += Z[v];
			Z[v*2+1] += Z[v];
		}
		Z[v] = 0;
	}
	void add(int l, int r, int x, int vl=0, int vr=35001-1, int v=1){
		push(v, vl, vr);
		if(vr < l || vl > r) return;
		if(vl >= l && vr <= r){
			Z[v] += x;
			push(v, vl, vr);
			return;
		}
		add(l, r, x, vl, (vl+vr)/2, v*2);
		add(l, r, x, (vl+vr)/2+1, vr, v*2+1);
		A[v] = min(A[v*2], A[v*2+1]);
	}
	void set(int l, int x, int vl=0, int vr=35001-1, int v=1){
		push(v, vl, vr);
		if(vr < l || vl > l) return;
		if(vl == vr){
			A[v] = x;
			return;
		}
		set(l, x, vl, (vl+vr)/2, v*2);
		set(l, x, (vl+vr)/2+1, vr, v*2+1);
		A[v] = min(A[v*2], A[v*2+1]);
	}
	int qry(int l, int r, int vl=0, int vr=35001-1, int v=1){
		if(vr < l || vl > r){
			return 1e15;
		}
		push(v, vl, vr);
		if(vl >= l && vr <= r){
			return A[v];
		}
		int a = qry(l, r, vl, (vl+vr)/2, v*2), b = qry(l, r, (vl+vr)/2+1, vr, v*2+1);
		return min(a, b);
	}
};

int N, K, A[35000], P[35000], dp[101][35001];
vector<int> O[35000];
lazy_segtree LZ_S[101];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> K;
	for(int i = 0; i < N; i++){
		eat >> A[i];
		A[i]--;
		if(O[A[i]].size()){
			P[i] = O[A[i]].back();
		}else{
			P[i] = -2;
		}
		O[A[i]].push_back(i);
	}
	LZ_S[0].add(1, 35000, 1e15);
	for(int i = 1; i <= N; i++){
		for(int j = 0; j <= K; j++){
			LZ_S[j].add(0, P[i-1], i - P[i-1] - 1);
		}
		for(int j = 1; j <= K; j++){
			dp[j][i] = LZ_S[j-1].qry(0, i-1);
			//moo << j << ' ' << i << ' ' << dp[j][i] << endl;
			LZ_S[j].set(i, dp[j][i]);
		}
	}
	moo << dp[K][N] << endl;
}