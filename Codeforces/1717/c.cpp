#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, A[200000], B[200000], I[200000];
bool vis[200000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N;
		for(int i = 0; i < N; i++){
			eat >> A[i];
		}
		for(int i = 0; i < N; i++){
			eat >> B[i];
		}
		bool ok = 1;
		for(int i = 0; i < N; i++){
			if(A[i] > B[i]){
				ok = 0;
				break;
			}
			int n = i+1;
			if(n == N) n = 0;
			if(A[i] != B[i]){
				if(B[i] > B[n]+1){
					ok = 0;
					break;
				}
			}
		}
		if(ok) moo << "YES" << endl;
		else moo << "NO" << endl;
	}
}