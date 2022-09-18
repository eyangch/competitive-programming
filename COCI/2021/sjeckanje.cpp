#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

struct segtree{
	int a[800005][2][2];
	int b[800005];
	void init(){
		for(int i = 0; i < 800005; i++){
			for(int j = 0; j < 2; j++){
				for(int k = 0; k < 2; k++){
					a[i][j][k] = 0;
				}
			}
			b[i] = 0;
		}
	}
	void upd(int i, int x, int l=0, int r=200000, int v=1){
		if(i < l || i > r) return;
		if(l == r){
			b[v] += x;
			a[v][0][0] = a[v][0][1] = a[v][1][0] = a[v][1][1] = 0;
			if(b[v] > 0){
				a[v][0][0] = b[v];
			}else{
				a[v][1][1] = -b[v];
			}
			return;
		}
		upd(i, x, l, (l+r)/2, v*2);
		upd(i, x, (l+r)/2+1, r, v*2+1);
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < 2; j++){
				a[v][i][j] = 0;
				for(int k = 0; k < 2; k++){
					int c = a[v*2][i][k] + a[v*2+1][k][j];
					a[v][i][j] = max(a[v][i][j], c);
				}
			}
		}
	}
	int qry(){
		return max({a[1][0][0], a[1][0][1], a[1][1][0], a[1][1][1]});
	}
};

int N, Q, A[200000];
segtree S;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> Q;
	S.init();
	for(int i = 0; i < N; i++){
		eat >> A[i];
	}
	for(int i = 0; i < N-1; i++){
		S.upd(i, A[i+1] - A[i]);
	}
	for(int i = 0; i < Q; i++){
		int l, r, x; eat >> l >> r >> x;
		l -= 2, r--;
		if(l >= 0){
			S.upd(l, x);
		}
		if(r <= N-2){
			S.upd(r, -x);
		}
		moo << S.qry() << endl;
	}
}