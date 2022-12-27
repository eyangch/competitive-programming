#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

#define MXN 200005
int T, L[100000], R[100000], ans[100000];
vector<int> F[2*MXN], I[MXN+5];
int nF[2*MXN];

struct segment_tree{
	int A[8*MXN];
	void init(){
		fill(A, A+8*MXN, 0);
	}
	void upd(int x, int y=1, int l=0, int r=2*MXN-1, int v=1){
		if(l > x || r < x) return;
		if(l == r){
			A[v] += y;
		}else{
			upd(x, y, l, (l+r)/2, v*2);
			upd(x, y, (l+r)/2+1, r, v*2+1);
			A[v] = A[v*2] + A[v*2+1];
		}
	}
	int qry(int qr, int ql=0, int l=0, int r=2*MXN-1, int v=1){
		if(l > qr || r < ql) return 0;
		if(l >= ql && r <= qr){
			return A[v];
		}
		return qry(qr, ql, l, (l+r)/2, v*2) + qry(qr, ql, (l+r)/2+1, r, v*2+1);
	}
} S;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	for(int i = 0; i < T; i++){
		eat >> L[i] >> R[i];
		I[L[i]].push_back(i);
	}
	S.init();
	for(int i = MXN-1; i > 0; i--){
		for(int j = 2*i; j < MXN; j+=i){
			F[j].push_back(i);
			S.upd(j, nF[j]);
			nF[j]++;
		}
		for(int j : I[i]){
			int l = L[j], r = R[j];
			int x = (r-l+1);
			int ctot = x * (x-1) * (x-2) / 6;
			ctot -= S.qry(r);
			ans[j] = ctot;
		}
	}
	for(int i = 0; i < MXN; i++){
		F[i].clear();
		nF[i] = 0;
	}
	S.init();
	for(int i = MXN-1; i > 0; i--){
		for(int j = 3*i; j < 2*MXN; j+=i){
			if(j % 2 == 1) continue;
			for(int k : F[j]){
				if(i + k > j/2 && lcm(j/2, lcm(i, k)) == j){
					S.upd(j/2);
				}
			}
			F[j].push_back(i);
		}
		for(int j : I[i]){
			int l = L[j], r = R[j];
			int x = (r-l+1);
			ans[j] -= S.qry(r);
		}
	}
	for(int i = 0; i < T; i++){
		moo << ans[i] << endl;
	}
}