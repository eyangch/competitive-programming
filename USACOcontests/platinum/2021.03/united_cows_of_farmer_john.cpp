#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

struct segment_tree{
	int A[800005], L[800005], C[800005];
	void initC(int l=0, int r=199999, int v=1){
		if(l == r) C[v] = 1;
		else{
			initC(l, (l+r)/2, v*2);
			initC((l+r)/2+1, r, v*2+1);
			C[v] = C[v*2] + C[v*2+1];
		}
	}
	void init(int N){
		fill(A, A+4*N+1, 0);
		fill(L, L+4*N+1, 0);
		initC();
	}
	void push(int l, int r, int v){
		A[v] += L[v] * C[v];
		if(l != r){
			L[v*2] += L[v];
			L[v*2+1] += L[v];
		}
		L[v] = 0;
	}
	void upd(int l, int r, int x, int vl=0, int vr=199999, int v=1){
		push(vl, vr, v);
		if(vl > r || vr < l) return;
		if(vl >= l && vr <= r){
			L[v] += x;
			push(vl, vr, v);
			return;
		}
		upd(l, r, x, vl, (vl+vr)/2, v*2);
		upd(l, r, x, (vl+vr)/2+1, vr, v*2+1);
		A[v] = A[v*2] + A[v*2+1];
	}
	void deactivate(int x, int vl=0, int vr=199999, int v=1){
		push(vl, vr, v);
		if(vl > x || vr < x) return;
		if(vl == vr){
			A[v] = 0;
			C[v] = 0;
			return;
		}
		deactivate(x, vl, (vl+vr)/2, v*2);
		deactivate(x, (vl+vr)/2+1, vr, v*2+1);
		A[v] = A[v*2] + A[v*2+1];
		C[v] = C[v*2] + C[v*2+1];
	}
	int qry(int l, int r, int vl=0, int vr=199999, int v=1){
		if(vl > r || vr < l) return 0;
		push(vl, vr, v);
		if(vl >= l && vr <= r){
			return A[v];
		}
		int a = qry(l, r, vl, (vl+vr)/2, v*2);
		int b = qry(l, r, (vl+vr)/2+1, vr, v*2+1);
		return a + b;
	}
};

int N, A[200000], pv[200000], P[200000];
segment_tree S;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N;
	fill(pv, pv+N, -1);
	for(int i = 0; i < N; i++){
		eat >> A[i];
		A[i]--;
		P[i] = pv[A[i]];
		pv[A[i]] = i;
	}
	S.init(N);
	int ans = 0;
	for(int i = 0; i < N; i++){
		if(P[i] >= 0){
			S.deactivate(P[i]);
			S.upd(P[P[i]]+1, P[i], -1);
		}
		// do stuff
		int q = S.qry(P[i], i);
		ans += q;
		S.upd(P[i]+1, i-1, 1);
	}
	moo << ans << endl;
}