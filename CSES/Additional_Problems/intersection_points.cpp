#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

struct segment_tree{
	int A[8000005];
	void init(){
		fill(A, A+8000001, 0);
	}
	void upd(int i, int x, int l=0, int r=2000000, int v=1){
		if(i < l || i > r) return;
		if(l == r){
			A[v] += x;
			return;
		}
		upd(i, x, l, (l+r)/2, v*2);
		upd(i, x, (l+r)/2+1, r, v*2+1);
		A[v] = A[v*2] + A[v*2+1];
	}
	int qry(int l, int r, int vl=0, int vr=2000000, int v=1){
		if(vr < l || vl > r) return 0;
		if(vl >= l && vr <= r){
			return A[v];
		}
		return qry(l, r, vl, (vl+vr)/2, v*2) + qry(l, r, (vl+vr)/2+1, vr, v*2+1);
	}
};

int N;
vector<int> A[2000001], D[2000001];
vector<pair<int, int>> V[2000001];
segment_tree S;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N;
	for(int i = 0; i < N; i++){
		int X1, Y1, X2, Y2; eat >> X1 >> Y1 >> X2 >> Y2;
		X1 += 1e6, X2 += 1e6, Y1 += 1e6, Y2 += 1e6;
		if(X1 == X2){
			A[Y1].push_back(X1);
			D[Y2].push_back(X2);
		}else{
			V[Y1].push_back({X1, X2});
		}
	}
	S.init();
	int ans = 0;
	for(int i = 0; i < 2000001; i++){
		for(int j : D[i]){
			S.upd(j, -1);
		}
		for(pair<int, int> j : V[i]){
			int q = S.qry(j.first, j.second);
			ans += q;
		}
		for(int j : A[i]){
			S.upd(j, 1);
		}
	}
	moo << ans << endl;
}