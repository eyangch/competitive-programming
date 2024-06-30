#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, H[100000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N;
		for(int i = 0; i < N; i++){
			eat >> H[i];
		}
		int ans = 0;
		for(int i = N-1; i >= 0; i--){
			ans = max(ans+1, H[i]);
		}
		moo << ans << endl;
	}
}