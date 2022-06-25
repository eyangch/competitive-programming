#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, Z, a[2000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N >> Z;
		for(int i = 0; i < N; i++){
			eat >> a[i];
		}
		int ans = 0;
		for(int i = 0; i < N; i++){
			ans = max(ans, a[i] | Z);
		}
		moo << ans << endl;
	}
}