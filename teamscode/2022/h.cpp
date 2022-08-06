#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, M, A[100000], S[20], E[20], L[20], dp[100000], cdp[100000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N >> M;
		for(int i = 1; i < N; i++){
			eat >> A[i];
		}
		for(int i = 0; i < M; i++){
			eat >> S[i] >> E[i] >> L[i];
			S[i]--, E[i]--;
		}
		fill(dp, dp+N, 1e9);
		dp[0] = 0;
		for(int i = 0; i < M; i++){
			copy(dp, dp+N, cdp);
			int cxor = 0;
			multiset<int> x[32];
			for(int j = S[i]+1; j <= E[i]; j++){
				int er = j - (L[i]);
				//moo << "ER: " << er << endl;
				if(er >= S[i]+1){
					x[cxor].erase(x[cxor].find(dp[er-1]));
					cxor ^= A[er];
					//moo << "ERASE" << endl;
				}
				bool sp[32];
				fill(sp, sp+32, 0);
				for(int k = 0; k < 32; k++){
					if(sp[k]) continue;
					sp[k] = 1;
					sp[k^A[j]] = 1;
					x[k].swap(x[k^A[j]]);
				}
				x[A[j]].insert(dp[j-1]);
				cxor ^= A[j];
				int mn = 1e9;
				for(int k = 0; k < 32; k++){
					if(x[k].size()){
						mn = min(mn, k - 16 + *x[k].begin());
						//moo << "YES " << *x[k].begin() << endl;
					}
				}
				//moo << mn << ' ' << j << ' ' << i << ' ' << "OK" << endl;
				cdp[j] = min(cdp[j], mn);
			}
			copy(cdp, cdp+N, dp);
		}
		moo << dp[N-1] << endl;
	}
}