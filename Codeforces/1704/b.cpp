#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, X, A[200000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N >> X;
		for(int i = 0; i < N; i++){
			eat >> A[i];
		}
		int cnt = 0;
		int mn = 1e15, mx = -1;
		for(int i = 0; i < N; i++){
			mn = min(mn, A[i]);
			mx = max(mx, A[i]);
			if(mx - mn > 2 * X){
				cnt++;
				mn = A[i], mx = A[i];
			}
		}
		moo << cnt << endl;
	}
}