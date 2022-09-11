#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, K, A[500000], B[500000], R[500000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	for(int tc = 1; tc <= T; tc++){
		moo << "Case #" << tc << ": ";
		eat >> N >> K;
		for(int i = 0; i < N; i++){
			eat >> A[i];
			A[i]--;
		}
		for(int i = 0; i < N; i++){
			eat >> B[i];
			B[i]--;
		}
		if(N == 2){
			bool eq = (A[0] == B[0]);
			if((eq && K%2==0) || (!eq && K%2==1)){
				moo << "YES" << endl;
			}else{
				moo << "NO" << endl;
			}
			continue;
		}
		bool eq = 1;
		for(int i = 0; i < N; i++){
			if(A[i] != B[i]){
				eq = 0;
				break;
			}
		}
		if(K == 0){
			if(eq) moo << "YES" << endl;
			else moo << "NO" << endl;
			continue;
		}
		for(int i = 0; i < N; i++){
			R[A[i]] = i;
		}
		int start = R[B[0]];
		bool ok = 1;
		for(int i = 0; i < N; i++){
			if(B[i] != A[(start+i)%N]){
				ok = 0;
				break;
			}
		}
		if(K == 1 && eq){
			ok = 0;
		}
		if(ok){
			moo << "YES" << endl;
		}else{
			moo << "NO" << endl;
		}
	}
}