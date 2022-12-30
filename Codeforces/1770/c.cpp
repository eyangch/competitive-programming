#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, A[100], occ[105];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N;
		for(int i = 0; i < N; i++){
			eat >> A[i];
		}
		sort(A, A+N);
		bool ook = 1;
		for(int i = 1; i < N; i++){
			if(A[i] == A[i-1]) ook = 0;
		}
		for(int i = 2; i <= N; i++){
			fill(occ, occ+i, 0);
			for(int j = 0; j < N; j++){
				occ[A[j]%i]++;
			}
			bool ok = 0;
			for(int j = 0; j < i; j++){
				if(occ[j] < 2) ok = 1;
			}
			if(!ok){
				ook = 0;
				break;
			}
		}
		if(ook) moo << "YES" << endl;
		else moo << "NO" << endl;
	}
}