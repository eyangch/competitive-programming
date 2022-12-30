#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, K, A[3001];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N >> K;
		for(int i = 0; i < N; i++){
			eat >> A[i];
		}
		int ans = 1e15;
		for(int i = 1; i <= 3000; i++){
			int mx = 0, mn = 1e15;
			for(int j = 0; j < N; j++){
				int clp = max(1LL, A[j]/i);
				clp = min(clp, K);
				int val = A[j] / clp;
				//moo << ": " << clp << ' ' << val << endl;
				mx = max(mx, val);
				mn = min(mn, val);
			}
			//moo << mn << ' ' << mx << endl;
			ans = min(ans, mx-mn);
		}
		moo << ans << endl;
	}
}