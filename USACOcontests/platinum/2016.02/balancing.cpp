#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

struct segtree{
	int a[3][2000005];
	static const int mxN = 500000;
	void init(){
		fill(a[0], a[0]+mxN, 0);
		fill(a[1], a[1]+mxN, 0);
		fill(a[2], a[2]+mxN, 0);
	}
	void upd(int i, int x, int y, int v=1, int l=0, int r=mxN){
		if(l > i || r < i) return;
		if(l == r){
			a[x][v] += y;
			//a[2][v] = max(a[0][v], a[1][v]);
			return;
		}
		upd(i, x, y, v*2, l, (l+r)/2);
		upd(i, x, y, v*2+1, (l+r)/2+1, r);
		a[x][v] = a[x][v*2] + a[x][v*2+1];
		//a[2][v] = max(a[0][v], a[1][v]);
	}
	int qry(int v=1, int l=0, int r=mxN, int lsum1=0, int lsum2=0, int rsum1=0, int rsum2=0){
		if(l == r){
			int l1 = lsum1 + a[0][v];
			int l2 = lsum2 + a[1][v];
			int r1 = rsum1 + a[0][v];
			int r2 = rsum2 + a[1][v];
			int ret = max({lsum1, lsum2, r1, r2});
			ret = min(ret, max({l1, l2, rsum1, rsum2}));
			return ret;
		}
		int l1 = lsum1 + a[0][v*2];
		int l2 = lsum2 + a[1][v*2];
		int r1 = rsum1 + a[0][v*2+1];
		int r2 = rsum2 + a[1][v*2+1];
		int lv = max(l1, l2);
		int rv = max(r1, r2);
		int ret = max(lv, rv);
		if(lv < rv){
			int q = qry(v*2+1, (l+r)/2+1, r, l1, l2, rsum1, rsum2);
			ret = min(ret, q);
		}else{
			int q = qry(v*2, l, (l+r)/2, lsum1, lsum2, r1, r2);
			ret = min(ret, q);
		}
		return ret;
	}
};

int N;
pair<int, int> P[100000];
segtree S;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	freopen("balancing.in", "r", stdin); freopen("balancing.out", "w", stdout);
	eat >> N;
	for(int i = 0; i < N; i++){
		eat >> P[i].first >> P[i].second;
		P[i].first /= 2, P[i].second /= 2;
	}
	sort(P, P+N);
	S.init();
	for(int i = 0; i < N; i++){
		S.upd(P[i].second, 0, 1);
	}
	int ans = S.qry();
	for(int i = 0; i < N; i++){
		S.upd(P[i].second, 1, 1);
		S.upd(P[i].second, 0, -1);
		if(i == N-1 || P[i].first != P[i+1].first){
			ans = min(ans, S.qry());
		}
	}
	moo << ans << endl;
}