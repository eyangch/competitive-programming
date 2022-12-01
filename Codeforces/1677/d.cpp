#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int MOD = 998244353;
int T, N, K, V[1000000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N >> K;
		for(int i = 0; i < N; i++){
			eat >> V[i];
		}
		bool ok = 1;
		for(int i = N-1; i >= 0; i--){
			int m = i + K;
			if(m >= N){
				if(V[i] != 0 && V[i] != -1) ok = 0;
			}else{
				V[m] = V[i];
			}
			if(i < K){
				V[i] = 0;
			}
		}
		if(!ok){
			moo << 0 << endl;
			continue;
		}
		int ans = 1;
		for(int i = 0; i < N; i++){
			if(V[i] == 0){
				ans *= min(i+1, K+1);
			}
			if(V[i] == -1){
				ans *= i+1;
			}
			ans %= MOD;
		}
		moo << ans << endl;
	}
}