#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N;

int qry(int L, int R){
	moo << "? " << L << ' ' << R << endl;
	moo.flush();
	int ret = 0;
	for(int i = 0; i < R-L+1; i++){
		int x; eat >> x;
		if(x >= L && x <= R) ret++;
	}
	return ret;
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N;
		int lo = 1, hi = N, mid = 0;
		while(lo < hi){
			mid = (lo+hi)/2;
			int cur = qry(lo, mid);
			if(cur & 1){
				hi = mid;
			}else{
				lo = mid+1;
			}
		}
		moo << "! " << (lo+hi)/2 << endl;
		moo.flush();
	}
}