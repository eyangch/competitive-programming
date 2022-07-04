#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

struct lazy_segment_tree{
	int a[751*4+1], lz[751*4+1], N;
	void init(int N){
		fill(a, a+4*N+1, 0);
		fill(lz, lz+4*N+1, 0);
		this->N = N;
	}
	void push(int i){
		if(lz[i] == 0) return;
		a[i*2] += lz[i];
		a[i*2+1] += lz[i];
		lz[i*2] += lz[i];
		lz[i*2+1] += lz[i];
		lz[i] = 0;
	}
	void upd(int ql, int qx, int l=0, int r=-1, int i=1){
		if(r == -1) r = N-1;
		if(ql > r || N-1 < l) return;
		if(ql <= l && r <= N-1){
			a[i] += qx, lz[i] += qx;
		}else{
			push(i);
			upd(ql, qx, l, (l+r)/2, i*2);
			upd(ql, qx, (l+r)/2+1, r, i*2+1);
			a[i] = min(a[i*2], a[i*2+1]);
		}
	}
	int qry(int ql, int l=0, int r=-1, int i=1){
		if(r == -1) r = N-1;
		if(ql > r || N-1 < l) return 1e12;
		if(ql <= l && r <= N-1) return a[i];
		push(i);
		return min(qry(ql, l, (l+r)/2, i*2), qry(ql, (l+r)/2+1, r, i*2+1));
	}
};

int N, M;
int A[750];
lazy_segment_tree lst;
int minX[751];
set<pair<int, int>, greater<pair<int, int>>> s;

int min_rm(int q){
	lst.init(N+1);
	s.insert({q, 0});
	int rm = 0;
	int lstelem = 0;
	for(pair<int, int> p : s){
		int v = p.first;
		int i = p.second;
		if(lstelem + v < 0){
			rm++;
			continue;
		}
		int x = lst.qry(i);
		if(x + v < 0){
			rm++;
			continue;
		}
		lst.upd(i, v);
		lstelem += v;
	}
	s.erase({q, 0});
	return rm;
}

void dc(int l, int r, int vl, int vr){
	if(l + 1 >= r) return;
	int m = (l+r)/2;
	int ans = min_rm(m);
	minX[ans] = min(minX[ans], m);
	if(ans != vl){
		dc(l, m, vl, ans);
	}
	if(ans != vr){
		dc(m, r, ans, vr);
	}
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> M;
	for(int i = 0; i < N; i++){
		eat >> A[i];
	}
	for(int i = 0; i < N; i++){
		s.insert({A[i], i+1});
	}
	fill(minX, minX+N, 1e12);
	int ans0 = min_rm(0);
	int ans1e12 = min_rm(1e12);
	minX[ans1e12] = 1e12;
	minX[ans0] = 0;
	dc(0, 1e12, ans0, ans1e12);
	int eidx = N+1;
	for(int i = 1; i <= N; i++){
		if(minX[i] > minX[i-1]){
			eidx = i;
			break;
		}
	}
	for(int i = 0; i < M; i++){
		int B; eat >> B;
		int ans = lower_bound(minX, minX+eidx, B, greater<int>()) - minX;
		moo << ans << endl;
	}
}