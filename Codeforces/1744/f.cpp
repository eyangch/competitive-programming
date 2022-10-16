#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, P[200000], R[200000];
bool V[200000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N;
		fill(V, V+N, 0);
		int z = 0;
		for(int i = 0; i < N; i++){
			eat >> P[i];
			R[P[i]] = i;
			if(P[i] == 0) z = i;
		}
		int l = z, r = z;
		int ans = 0;
		int mx = 0;
		while(1){
			for(int i = mx+1; i < N; i++){
				if(V[i]) mx = i;
				else break;
			}
			int mxlen = (mx+1) * 2;
			int le = max(-1LL, r - mxlen), re = min(N, l + mxlen);
			if(mx < N-1){
				int nxt = R[mx+1];
				if(nxt < l) le = max(le, nxt);
				if(nxt > r) re = min(re, nxt);
			}
			int adjl = mxlen - (r - l);
			int ll = l - le;
			int rr = re - r;
			if(ll > 0 && rr > 0){
				int cur = ll * rr;
				int sub = 0;
				int totlen = ll + rr - 1;
				int amt = totlen - adjl;
				if(amt > 0){
					sub = (amt + 1) * amt / 2;
				}
				ans += cur - sub;
			}
			if(mx == N-1) break;
			int nxt = R[mx+1];
			//moo << l << ' ' << r << ' ' << nxt << endl;
			if(nxt < l){
				for(; l >= nxt; l--){
					V[P[l]] = 1;
				}
				l++;
			}
			if(nxt > r){
				for(; r <= nxt; r++){
					V[P[r]] = 1;
				}
				r--;
			}
		}
		moo << ans << endl;
	}
}