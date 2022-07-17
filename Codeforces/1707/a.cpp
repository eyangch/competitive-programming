#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, Q, A[100000];
bool ans[100000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N >> Q;
		fill(ans, ans+N, 0);
		for(int i = 0; i < N; i++){
			eat >> A[i];
		}
		int ptr = N-1;
		for(int i = 0; i < Q && ptr >= 0; i++){
			while(ptr > 0 && A[ptr] <= i){
				ans[ptr] = 1;
				ptr--;
			}
			ans[ptr] = 1;
			ptr--;
		}
		for(int i = 0; i <= ptr; i++){
			if(A[i] <= Q){
				ans[i] = 1;
			}
		}
		for(int i = 0; i < N; i++){
			moo << ans[i];
		}
		moo << endl;
	}
}