#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, A[200000], pfx[200000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N;
		pfx[0] = 0;
		int ans = 0;
		for(int i = 0; i < N; i++){
			eat >> A[i];
			A[i]--;
			if(A[i] < i){
				if(A[i] > 0) ans += pfx[A[i]-1];
				pfx[i]++;
			}
			pfx[i+1] = pfx[i];
		}
		moo << ans << endl;
	}
}