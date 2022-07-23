#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

struct lazy_segment_tree{
	int a[1200005], lz[1200005];
	void init(){
		fill(lz, lz+1200005, -1);
	}
	void push(int i, int l, int r){
		if(!~lz[i]) return;
		a[i] = lz[i] * (r - l + 1);
		if(l != r){
			lz[i*2] = lz[i];
			lz[i*2+1] = lz[i];
		}
		lz[i] = -1;
	}
	void upd(int l, int r, int x, int vl=0, int vr=299999, int v=1){
		push(v, vl, vr);
		if(r < l || r < vl || l > vr){
			return;
		}
		if(l <= vl && vr <= r){
			lz[v] = x;
			push(v, vl, vr);
		}else{
			upd(l, r, x, vl, (vl + vr) / 2, v*2);
			upd(l, r, x, (vl+vr)/2+1, vr, v*2+1);
			a[v] = a[v*2] + a[v*2+1];
		}
	}
	int qry1(int l, int r, int vl=0, int vr=299999, int v=1){
		if(r < vl || l > vr){
			return 0;
		}
		push(v, vl, vr);
		if(l <= vl && vr <= r){
			return a[v];
		}else{
			return qry1(l, r, vl, (vl + vr) / 2, v*2) + qry1(l, r, (vl+vr)/2+1, vr, v*2+1);
		}
	}
	int qry2(int x, int sum=0, int vl=0, int vr=299999, int v=1){
		push(v, vl, vr);
		//moo << "qry2: " << x << ' ' << sum << ' ' << vl << ' ' << vr << ' ' << v << ' ' << a[v] << endl;
		if(vl == vr){
			if(a[v] + sum > x) return -1;
			return vl;
		}
		if(a[v] + sum <= x){
			return vr;
		}else{
			int y = qry2(x, sum, vl, (vl+vr)/2, v*2);
			if(a[v*2] + sum <= x) return max(y, qry2(x, sum + a[v*2], (vl+vr)/2+1, vr, v*2+1));
			else return y;
		}
	}
};

int N, Q, A[200000];
lazy_segment_tree f[2];

void upd(int n, int a){
	int x = f[n].qry1(0, a-1);
	int y = f[n].qry2(x);
	//moo << "UPD: " << n << ' ' << a << '/' << x << ' ' << y << endl;
	f[n].upd(a, y, 1);
	f[n].upd(y+1, y+1, 0);
	f[!n].upd(a, y, 0);
	f[!n].upd(y+1, y+1, 1);
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> Q;
	f[0].init(), f[1].init();
	f[0].upd(0, 299999, 1);
	//moo << f[1].qry1(0, 299999) << endl;
	for(int i = 0; i < N; i++){
		eat >> A[i];
		A[i]--;
		upd(0, A[i]);
	}
	for(int i = 0; i < Q; i++){
		int k, l; eat >> k >> l;
		k--, l--;
		upd(1, A[k]);
		A[k] = l;
		upd(0, A[k]);
		int x = f[1].qry1(0, 299999);
		int ans = f[1].qry2(x-1);
		moo << ans+2 << endl;
	}
}