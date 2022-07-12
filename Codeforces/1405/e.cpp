#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

struct BIT{
	int a[600050], N;
	void init(int N){
		this->N = N;
		fill(a, a+N, 0);
	}
	void upd(int i, int x){
		for(i++; i <= N; i += i & -i){
			a[i] += x;
		}
	}
	int qry(int i){
		int ret = 0;
		for(i++; i > 0; i -= i & -i){
			ret += a[i];
		}
		return ret;
	}
};

int N, Q, A[300000], D[300000], B[300000], P[300000], Qi[300000], X[300000], Y[300000], ans[300000];
vector<int> qu[600050];
BIT pf, q;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> Q;
	pf.init(2 * N + 20);
	fill(B, B+N, -1);
	fill(P, P+N, -1);
	for(int i = 0; i < N; i++){
		eat >> A[i];
		A[i]--;
		D[i] = i - A[i];
	}
	int cur = 0, ptr = 0;
	for(int i = 0; i < N; i++){
		if(D[i] < 0) continue;
		int lo = 0, hi = i, mid = 0, ret = -1;
		while(lo <= hi){
			mid = (lo + hi) / 2;
			int val = pf.qry(i-1);
			if(mid > 0) val -= pf.qry(mid-1);
			if(D[i] <= val){
				ret = mid;
				lo = mid+1;
			}else{
				hi = mid-1;
			}
		}
		P[i] = ret;
		if(P[i] >= 0) pf.upd(P[i], 1);
	}
	q.init(N);
	for(int i = 0; i < Q; i++){
		eat >> X[i] >> Y[i];
	}
	iota(Qi, Qi+Q, 0);
	sort(Qi, Qi+Q, [](int a, int b){
		return Y[a] > Y[b];
	});
	int pv = 0;
	for(int i = 0; i < Q; i++){
		int j = Qi[i];
		int l = X[j], r = N - Y[j] - 1;
		for(; pv <= r; pv++){
			if(!~P[pv]) continue;
			q.upd(P[pv], 1);
		}
		ans[j] = q.qry(r);
		if(l > 0) ans[j] -= q.qry(l-1);
	}
	for(int i = 0; i < Q; i++){
		moo << ans[i] << endl;
	}
}