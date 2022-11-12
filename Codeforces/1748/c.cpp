#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, A[200000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N;
		for(int i = 0; i < N; i++){
			eat >> A[i];
		}
		map<int, int> msum;
		int csum = 0;
		int ans = 0;
		bool f = 0;
		for(int i = 0; i < N; i++){
			if(A[i] == 0){
				if(f){
					int mx = 0;
					for(pair<int, int> j : msum){
						mx = max(mx, j.second);
					}
					//moo << "MX: " << mx << endl;
					ans += mx;
				}else{
					f = 1;
					ans += msum[0];
					//moo << "SUM0: " << msum[0] << endl;
				}
				msum.clear();
				msum[0] = 1;
				csum = 0;
				continue;
			}
			csum += A[i];
			msum[csum]++;
		}
		//moo << ans << endl;
		if(f){
			int mx = 0;
			for(pair<int, int> j : msum){
				mx = max(mx, j.second);
			}
			ans += mx;
		}else{
			ans += msum[0];
		}
		moo << ans << endl;
	}
}