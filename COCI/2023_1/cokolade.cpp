#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, Q, C[100000], pfx[100000], sfx[100000], K, M;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> Q;
	for(int i = 0; i < N; i++){
		eat >> C[i];
	}
	sort(C, C+N);
	pfx[0] = C[0];
	for(int i = 1; i < N; i++){
		pfx[i] = pfx[i-1] + C[i];
	}
	sfx[N-1] = C[N-1];
	for(int i = N-2; i >= 0; i--){
		sfx[i] = sfx[i+1] + C[i];
	}
	for(int i = 0; i < Q; i++){
		eat >> K >> M;
		M--;
		int idx = (upper_bound(C, C+N, K) - C);
		int l = 0, r = M+1, m = 0, a = 1e15;
		r = min(r, idx);
		l = max(l, M+1 - (N - idx));
		while(l <= r){
			m = (l+r)/2;
			int p = -1e15, psum = 0;
			if(m > 0){
				p = C[m-1];
				psum = pfx[m-1];
			}
			int s = -1e15, ssum = 0;
			if(m < M+1){
				s = K * 2 - C[N-(M+1-m)];
				ssum = sfx[N-(M+1-m)];
			}
			int cur = psum + (M+1-m) * K * 2 - ssum;
			//moo << m << ' ' << (M+1-m) << ' ' << cur << endl;
			//moo << p << ' ' << s << endl;
			a = min(a, cur);
			if(p < s){
				l = m+1;
			}else{
				r = m-1;
			}
		}
		assert(a < 5e14);
		moo << a << endl;
	}
	/*for(int i = 0; i < Q; i++){
		eat >> K >> M;
		M--;
		int idx = upper_bound(C, C+N, K, greater<int>()) - C;
		if(idx > M){
			int f = pfx[M] - (M+1) * K;
			int l = (M+1) * K;
			moo << l - f << endl;
		}else{
			int f = pfx[idx] - (idx+1) * K;
			int l = (idx+1) * K + pfx[M] - pfx[idx];
			moo << l - f << endl;
		}
	}*/
}